(* name binding test harness *)

Flx_version_hook.set_version ()

let print_help () =
  Flx_flxopt.print_options ();
  exit 0

let reverse_return_parity = ref false;;

try
  let argc = Array.length Sys.argv in
  if argc <= 1
  then begin
    print_endline "usage: flxg --key=value ... filename; -h for help";
    raise (Flx_exceptions.Exit 0)
  end
  ;
  let raw_options = Flx_getopt.parse_options Sys.argv in
  let compiler_options = Flx_flxopt.get_felix_options raw_options in
  reverse_return_parity := compiler_options.Flx_mtypes2.reverse_return_parity;
  let syms = Flx_mtypes2.make_syms compiler_options in

  if Flx_getopt.check_keys raw_options ["h"; "help"] then print_help ();

  if Flx_getopt.check_key raw_options "version" then print_endline
    ("Felix Version " ^ !Flx_version.version_data.Flx_version.version_string);

  if compiler_options.Flx_mtypes2.print_flag then begin
    print_string "//Include directories = ";
    List.iter (fun d -> print_string (d ^ " "))
    compiler_options.Flx_mtypes2.include_dirs;
    print_endline ""
  end
  ;

  let filename =
    match Flx_getopt.get_key_value raw_options "" with
    | Some s -> s
    | None -> exit 0
  in
  let filebase = filename in
  let input_file_name = filebase ^ ".flx"
  and iface_file_name = filebase ^ ".fix"
  and module_name =
    let n = String.length filebase in
    let i = ref (n-1) in
    while !i <> -1 && filebase.[!i] <> '/' do decr i done;
    String.sub filebase (!i+1) (n - !i - 1)
  in

  (* PARSE THE IMPLEMENTATION FILE *)
  print_endline ("//Parsing Implementation " ^ input_file_name);
  let parser_state = List.fold_left
    (Flx_parse.parse_file
      ~include_dirs:compiler_options.Flx_mtypes2.include_dirs)
    (Flx_parse.make_parser_state (fun stmt stmts -> stmt :: stmts) [])
    (compiler_options.Flx_mtypes2.auto_imports @ [input_file_name])
  in
  let parse_tree = List.rev (Flx_parse.parser_data parser_state) in
  let have_interface = Sys.file_exists iface_file_name in
  print_endline (Flx_print.string_of_compilation_unit parse_tree);
  print_endline "//PARSE OK";

  let include_dirs =
    (* (Filename.dirname input_file_name) :: *)
    compiler_options.Flx_mtypes2.include_dirs in
  let compiler_options = { compiler_options with
    Flx_mtypes2.include_dirs = include_dirs } in
  let syms = { syms with
    Flx_mtypes2.compiler_options = compiler_options } in
  let desugar_state = Flx_desugar.make_desugar_state module_name syms in
  let asms = Flx_desugar.desugar_compilation_unit desugar_state parse_tree in

  let root = !(syms.Flx_mtypes2.counter) in
  print_endline
    ("//Top level module '" ^ module_name ^ "' has index " ^ string_of_int root);

  let _, _, _, ifaces, _ =
    Flx_symtab.build_tables syms "root" Flx_ast.dfltvs 0 None None root asms
  in
    print_endline "//BINDING EXECUTABLE CODE";
    print_endline "//-----------------------";
    let bbind_state = Flx_bbind.make_bbind_state syms in
    let bbdfns = Flx_bbind.bbind bbind_state in
    let child_map = Flx_child.cal_children syms bbdfns in
    let bifaces = Flx_bbind.bind_ifaces bbind_state ifaces in
    print_endline "//Binding complete";

    let root_proc =
      match
        try Hashtbl.find syms.Flx_mtypes2.dfns root
        with Not_found ->
          failwith
          (
            "Can't find root module " ^ string_of_int root ^
            " in symbol table?"
          )
      with {
        Flx_types.id=id;
        Flx_types.sr = sr;
        Flx_types.parent = parent;
        Flx_types.vs = vs;
        Flx_types.pubmap = name_map;
        Flx_types.symdef = entry } ->
      begin match entry with
        | `SYMDEF_module -> ()
        | _ -> failwith "Expected to find top level module ''"
      end
      ;
      let entry =
        try Hashtbl.find name_map "_init_"
        with Not_found ->
          failwith "Can't find name _init_ in top level module's name map"
      in
      let index = match entry with
        | `FunctionEntry [x] -> Flx_typing.sye x
        | `FunctionEntry [] -> failwith "Couldn't find '_init_'"
        | `FunctionEntry _ -> failwith "Too many top level procedures called '_init_'"
        | `NonFunctionEntry _ -> failwith "_init_ found but not procedure"
      in
      if compiler_options.Flx_mtypes2.print_flag
      then print_endline
        ("//root module's init procedure has index " ^ string_of_int index);
      index
    in

    Hashtbl.iter
    (fun index (name,parent,sr,entry) -> print_endline
      (
        string_of_int index ^ " --> " ^
        Flx_print.string_of_bbdcl syms.Flx_mtypes2.dfns bbdfns entry index
      )
    )
    bbdfns

with x -> Flx_terminate.terminate !reverse_return_parity x
;;
