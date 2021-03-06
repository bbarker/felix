Package: src/packages/logic.fdoc


=====
Logic
=====

=================== ======================================
key                 file                                   
=================== ======================================
bool.flx            share/lib/std/scalar/bool.flx          
boolexpr.fsyn       share/lib/std/scalar/boolexpr.fsyn     
predicate.flx       share/lib/std/algebra/predicate.flx    
staticbool.flx      share/lib/std/kind/staticbool.flx      
staticbool_ops.fsyn share/lib/std/kind/staticbool_ops.fsyn 
=================== ======================================


Boolean Logic
=============


We have two kinds of boolean, cbool is the binding to C/C++
bool type which is usually a single byte.

The other kind, bool, is a synonym for type 2, which is
a compact linear type and will use a a 64 bit word.

We provide the same operations on both, since as values
they're compatible. However the Felix bool is the standard
type.

Pointers to these two types are not compatible.
Although a sole bool is much bigger than a cbool,
64 bools can fit in a single machine word, as opposed
to only 8 cbools.



.. index:: Bool(class)
.. index:: bool(ctor)
.. index:: land(fun)
.. index:: nand(fun)
.. index:: lor(fun)
.. index:: nor(fun)
.. index:: xor(fun)
.. index:: lnot(fun)
.. index:: implies(fun)
.. index:: CBool(class)
.. index:: cbool(ctor)
.. index:: cfalse(const)
.. index:: ctrue(const)
.. index:: land(fun)
.. index:: nand(fun)
.. index:: lor(fun)
.. index:: nor(fun)
.. index:: xor(fun)
.. index:: lnot(fun)
.. index:: implies(fun)
.. index:: zero(fun)
.. index:: str(fun)
.. index:: str(fun)
.. code-block:: felix

  //[bool.flx]
  typedef bool = 2;
  type cbool = "bool" requires index TYPE_cbool; 
  
  open class Bool
  {
    ctor bool:cbool="$1";
  
    //$ Short cut and via closure
    noinline fun andthen (x: bool, y:1->bool) : bool => 
      if x then #y else false
    ;
   
    //$ Short cut and via closure
    noinline fun orelse (x: bool, y:1->bool) : bool => 
      if x then true else #y
    ;
  
     //$ Disjunction: logical and.
    fun land: bool * bool -> bool = "$1&&$2";      // x and y
  
    //$ Negated and.
    fun nand: bool * bool -> bool = "!($1&&$2)";   // not (x and y)
  
    //$ Conjunction: logical or.
    fun lor: bool * bool -> bool = "$1||$2";       // x or y
  
    //$ Negated or.
    fun nor: bool * bool -> bool = "!($1||$2)";    // not (x or y)
  
    //$ Logical exclusive or.
    fun xor: bool * bool -> bool = "$1!=$2";       // (x or y) and not (x and y)
  
    //$ Logical negation.
    fun lnot: bool -> bool = "!$1";                // not x
  
    //$ Logical implication.
    fun implies: bool * bool -> bool = "!$1||$2";  // not x or y
  
    //$ Mutating or.
    proc |= : &bool * bool = "*$1|=$2;";  
  
    //$ Mutating and.
    proc &= : &bool * bool = "*$1&=$2;";  
  
    // Elide double negations.
    //reduce dneg(x:bool): lnot (lnot x) => x;       
    // Elide double negations.
    //reduce dneg(x:bool,y:bool): lnot (nand(x,y)) => land(x,y); 
    // Elide double negations.
    //reduce dneg(x:bool,y:bool): lnot (nor(x,y)) => lor(x,y);
  }
  
  //$ Standard operations on cboolean type.
  open class CBool
  {
    ctor cbool:bool="$1";
    const cfalse: cbool="false";
    const ctrue: cbool="true";
  
    //$ Short cut and via closure
    noinline fun andthen (x: cbool, y:1->cbool) : cbool => 
      if x then #y else cfalse
    ;
  
    //$ Short cut and via closure
    noinline fun orelse (x: cbool, y:1->cbool) : cbool => 
      if x then ctrue else #y
    ;
   
    //$ Disjunction: logical and.
    fun land: cbool * cbool -> cbool = "$1&&$2";      // x and y
  
    //$ Negated and.
    fun nand: cbool * cbool -> cbool = "!($1&&$2)";   // not (x and y)
  
    //$ Conjunction: logical or.
    fun lor: cbool * cbool -> cbool = "$1||$2";       // x or y
  
    //$ Negated or.
    fun nor: cbool * cbool -> cbool = "!($1||$2)";    // not (x or y)
  
    //$ Logical exclusive or.
    fun xor: cbool * cbool -> cbool = "$1!=$2";       // (x or y) and not (x and y)
  
    //$ Logical negation.
    fun lnot: cbool -> cbool = "!$1";                // not x
  
    //$ Logical implication.
    fun implies: cbool * cbool -> cbool = "!$1||$2";  // not x or y
  
    //$ Mutating or.
    proc |= : &cbool * cbool = "*$1|=$2;";  
  
    //$ Mutating and.
    proc &= : &cbool * cbool = "*$1&=$2;";  
  
    // Elide double negations.
    //reduce dneg(x:cbool): lnot (lnot x) => x;       
    // Elide double negations.
    //reduce dneg(x:cbool,y:cbool): lnot (nand(x,y)) => land(x,y); 
    // Elide double negations.
    //reduce dneg(x:cbool,y:cbool): lnot (nor(x,y)) => lor(x,y);
  }
  
  
  instance FloatAddgrp[bool] {
    fun zero () => 0 :>> bool;
    fun - (x:bool) => (sub (2, caseno x)) :>> bool;
    fun + (x:bool, y:bool) : bool => (add ((caseno x , caseno y)) % 2) :>> bool;
    fun - (x:bool, y:bool) : bool => (add (2, sub(caseno x , caseno y)) % 2) :>> bool;
  }
  
  instance Str[bool] {
    //$ Convert bool to string.
    fun str (b:bool) : string => if b then "true" else "false" endif;
  }
  
  instance Tord[bool] {
    //$ Total ordering of bools, false < true.
    //$ Note that x < y is equivalent to x implies y.
    fun < : bool * bool -> bool = "$1<$2";
  }
  
  open Tord[bool];
  open Show[bool];
  open Addgrp[bool];
  
  instance Str[cbool] {
    //$ Convert cbool to string.
    fun str (b:cbool) : string => if b then "ctrue" else "cfalse" endif;
  }
  
  instance Tord[cbool] {
    //$ Total ordering of cbools, false < true.
    //$ Note that x < y is equivalent to x implies y.
    fun < : cbool * cbool -> cbool = "$1<$2";
  }
  
  open Tord[cbool];
  open Show[cbool];
  
Syntax
======



.. code-block:: felix

  //[boolexpr.fsyn]
  syntax boolexpr
  {
    //$ Boolean false.
    satom := "false" =># "'(ast_typed_case  0 2)";
  
    //$ Boolean true.
    satom := "true" =># "'(ast_typed_case  1 2)";
  
    //$ Logical implication.
    x[simplies_condition_pri] := x[>simplies_condition_pri] "implies" x[>simplies_condition_pri] =># "(Infix)";
  
    //$ Logical disjunction (or).
    x[sor_condition_pri] := x[>sor_condition_pri] ( "or" x[>sor_condition_pri])+ =># "(chain 'ast_orlist _1 _2)" note "lor";
  
    //$ Logical conjunction (and).
    x[sand_condition_pri] := x[>sand_condition_pri] ( "and" x[>sand_condition_pri])+ =># "(chain 'ast_andlist _1 _2)" note "land";
  
    //$ Logical negation (not).
    x[snot_condition_pri] := "not" x[snot_condition_pri]  =># "`(ast_not ,_sr ,_2)";
  
    x[scomparison_pri]:= x[>scomparison_pri] "\not" cmp x[>scomparison_pri] =># "`(ast_not ,_sr (ast_apply ,_sr (,_3 (,_1 ,_4))))";
  
    // tex logic operators
    x[stex_implies_condition_pri] := x[>stex_implies_condition_pri]  "\implies" x[>stex_implies_condition_pri] =># "(infix 'implies)";
    x[stex_or_condition_pri] := x[>stex_or_condition_pri] ( "\lor" x[>stex_or_condition_pri])+ =># "(chain 'ast_orlist _1 _2)" note "lor";
    x[stex_and_condition_pri] := x[>stex_and_condition_pri] ( "\land" x[>stex_and_condition_pri])+ =># "(chain 'ast_andlist _1 _2)" note "land";
    x[stex_not_condition_pri] := "\lnot" x[stex_not_condition_pri]  =># "`(ast_not ,_sr ,_2)";
  
  
    bin := "\iff" =># '(nos _1)'; // NOT IMPLEMENTED FIXME
    bin := "\impliedby" =># '(nos _1)'; // NOT IMPLEMENTED FIXME
  
    //$ Conditional expression.
    satom := sconditional "endif" =># "_1";
  
    //$ Conditional expression (prefix).
    sconditional := "if" sexpr "then" sexpr selse_part =>#
        "`(ast_cond ,_sr (,_2 ,_4 ,_5))";
  
        selif := "elif" sexpr "then" sexpr =># "`(,_2 ,_4)";
  
        selifs := selif =># "`(,_1)";
        selifs := selifs selif =># "(cons _2 _1)";
  
        selse_part:= "else" sexpr =># "_2";
        selse_part:= selifs "else" sexpr =>#
            """
              (let ((f (lambda (result condthn)
                (let ((cond (first condthn)) (thn (second condthn)))
                  `(ast_cond ,_sr (,cond ,thn ,result))))))
              (fold_left f _3 _1))
            """;
  }
  
Predicate combinators.
======================

A <em>predicate</em> is any function returning
a boolean argument. Predicates are also relations
by simply providing a tuple argument.

This is a simple class allowing predicates to be combined
directly using symbolic operators to form new predicates, using logical 
conjunction  :code:`and`, disjunction  :code:`or`, implication  :code:`implies`
and negation  :code:`not`. The parser maps these operator onto the 
functions  :code:`land`,  :code:`lor`,  :code:`implies`, and  :code:`lnot` respectively.



.. index:: Predicate(class)
.. code-block:: felix

  //[predicate.flx]
  
  // Some operations on predicates.
  // These also automatically apply to relations, but just taking
  // the argument as a tuple.
  
  open class Predicate[T]
  {
     fun land (f:T->bool,g:T->bool) =>
       fun (x:T) => f x and g x
     ;
  
     fun lor (f:T->bool,g:T->bool) =>
       fun (x:T) => f x or g x
     ;
  
     fun implies (f:T->bool,g:T->bool) =>
       fun (x:T) => f x implies g x
     ;
  
     fun lnot (f:T->bool) =>
       fun (x:T) => not (f x)
     ;
  
  }
  
  
Compile time booleans
=====================


.. code-block:: felix

  //[staticbool.flx]
  
  typedef fun n"`and" (x:BOOL,y:BOOL):BOOL => _typeop ("_staticbool_and",(x,y),BOOL);
  typedef fun n"`or" (x:BOOL,y:BOOL):BOOL => _typeop ("_staticbool_or",(x,y),BOOL);
  typedef fun n"`xor" (x:BOOL,y:BOOL):BOOL => _typeop ("_staticbool_xor",(x,y),BOOL);
  typedef fun n"`not" (x:BOOL):BOOL => _typeop ("_staticbool_not",(x),BOOL);
  typedef fun n"`true" ():BOOL => _typeop ("_staticbool_true",(),BOOL);
  typedef fun n"`false" ():BOOL => _typeop ("_staticbool_false",(),BOOL);


.. code-block:: felix

  //[staticbool_ops.fsyn]
  syntax staticbool_ops 
  {
    x[sand_condition_pri] := x[sand_condition_pri] "`and" x[>sand_condition_pri] =># "(Infix)";
    x[sor_condition_pri] := x[sor_condition_pri] "`or" x[>sor_condition_pri] =># "(Infix)";
    x[sor_condition_pri] := x[sor_condition_pri] "`xor" x[>sor_condition_pri] =># "(Infix)";
    x[snot_condition_pri] :=  "`not" x[snot_condition_pri] =># "(Prefix)";
    satom := "`true"  =># '`(ast_apply (,_sr, (,(nos "`true") ())))';
    satom := "`false"  =># '`(ast_apply (,_sr, (,(nos "`true") ())))';
  }
  



