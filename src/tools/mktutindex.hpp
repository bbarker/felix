#ifndef _FLX_GUARD_mktutindex
#define _FLX_GUARD_mktutindex
//Input file: src/tools/mktutindex.flx
//Generated by Felix Version 1.1.7dev
//Timestamp: 2011/12/22 13:11:2 UTC
//Timestamp: 2011/12/22 23:11:2 (local)

//FELIX RUNTIME
#include "flx_rtl.hpp"
#include "flx_gc.hpp"
#ifndef FLX_NO_INCLUDES
#include "mktutindex.includes"
#endif


//-----------------------------------------
//USER HEADERS
#include "flx_rtl_config.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

//-----------------------------------------
//FELIX SYSTEM
namespace flxusr { namespace mktutindex {
struct thread_frame_t;

//-----------------------------------------
//NAME THE TYPES

//PRIMITIVE 5154 INSTANCE 54050: string
typedef ::std::basic_string<char> _a5154t_54050;
typedef int _us2;

//TYPE 54052: string^2
struct _at54052;

//PRIMITIVE 2534 INSTANCE 54053: int
//typedef int int;

//TYPE 54054: int^2
struct _at54054;

//PRIMITIVE 7513 INSTANCE 54055: RE2
typedef ::re2::RE2* _a7513t_54055;

//PRIMITIVE 7512 INSTANCE 54056: RE2_
typedef ::re2::RE2 _a7512t_54056;

//TYPE 54057: bool^2
struct _at54057;

//PRIMITIVE 2527 INSTANCE 54059: address
typedef void * _a2527t_54059;

//PRIMITIVE 10967 INSTANCE 54060: dirent_t
typedef struct dirent* _a10967t_54060;

//PRIMITIVE 10968 INSTANCE 54061: DIR_t
typedef DIR* _a10968t_54061;

//TYPE 54062: string * &DIR_t
struct _tt54062;

//PRIMITIVE 4330 INSTANCE 54063: ostream
typedef ::std::ostream* _a4330t_54063;

//TYPE 54064: ostream * string
struct _tt54064;

//TYPE 54066: DIR_t * dirent_t * &dirent_t * &int
struct _tt54066;

//TYPE 54067: list[string] * string
struct _tt54067;

//TYPE 54068: string * list[string]
struct _tt54068;

//TYPE 54069: string -> void
struct _pt54069;

//PRIMITIVE 4304 INSTANCE 54070: output_text_file
typedef FILE* _a4304t_54070;

//TYPE 54071: output_text_file * string
struct _tt54071;

//PRIMITIVE 4303 INSTANCE 54072: input_text_file
typedef FILE* _a4303t_54072;

//PRIMITIVE 2529 INSTANCE 54073: char
//typedef char char;

//TYPE 54074: char^2
struct _at54074;

//TYPE 54075: string * int
struct _tt54075;

//PRIMITIVE 10826 INSTANCE 54098: stat_t
typedef struct stat _a10826t_54098;

//TYPE 54099: string * &stat_t * &int
struct _tt54099;

//PRIMITIVE 10855 INSTANCE 54100: mode_t
//typedef mode_t mode_t;

//TYPE 54101: mode_t^2
struct _at54101;

//PRIMITIVE 10736 INSTANCE 54103: errno_t
typedef int _a10736t_54103;

//TYPE 54104: errno_t^2
struct _at54104;

//PRIMITIVE 7515 INSTANCE 54105: StringPiece
typedef ::re2::StringPiece _a7515t_54105;

//PRIMITIVE 7578 INSTANCE 54106: Anchor
typedef ::re2::RE2::Anchor _a7578t_54106;

//TYPE 54107: RE2 * StringPiece * int * Anchor * &StringPiece * int
struct _tt54107;

//TYPE 54108: &list[string]^2
struct _at54108;

//TYPE 54109: &list[string] * list[string]
struct _tt54109;


//-----------------------------------------
//DEFINE THE TYPES

//TYPE 54052: string^2
struct _at54052 {
  static size_t const len = 2;
  typedef _a5154t_54050 element_type;
  _a5154t_54050 data[2];
  _at54052() {}
  _at54052(_a5154t_54050 a0, _a5154t_54050 a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54054: int^2
struct _at54054 {
  static size_t const len = 2;
  typedef int element_type;
  int data[2];
  _at54054() {}
  _at54054(int a0, int a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54057: bool^2
struct _at54057 {
  static size_t const len = 2;
  typedef _us2 element_type;
  _us2 data[2];
  _at54057() {}
  _at54057(_us2 a0, _us2 a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54062: string * &DIR_t
struct _tt54062 {
  _a5154t_54050 mem_0;
  _a10968t_54061* mem_1;
  _tt54062(){}
  _tt54062(_a5154t_54050 a0, _a10968t_54061* a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54064: ostream * string
struct _tt54064 {
  _a4330t_54063 mem_0;
  _a5154t_54050 mem_1;
  _tt54064(){}
  _tt54064(_a4330t_54063 a0, _a5154t_54050 a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54066: DIR_t * dirent_t * &dirent_t * &int
struct _tt54066 {
  _a10968t_54061 mem_0;
  _a10967t_54060 mem_1;
  _a10967t_54060* mem_2;
  int* mem_3;
  _tt54066(){}
  _tt54066(_a10968t_54061 a0, _a10967t_54060 a1, _a10967t_54060* a2, int* a3):
    mem_0(a0), mem_1(a1), mem_2(a2), mem_3(a3){}
};

//TYPE 54067: list[string] * string
struct _tt54067 {
  void* mem_0;
  _a5154t_54050 mem_1;
  _tt54067(){}
  _tt54067(void* a0, _a5154t_54050 a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54068: string * list[string]
struct _tt54068 {
  _a5154t_54050 mem_0;
  void* mem_1;
  _tt54068(){}
  _tt54068(_a5154t_54050 a0, void* a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54069: string -> void
struct _pt54069: ::flx::rtl::con_t {
  typedef void rettype;
  typedef _a5154t_54050 argtype;
  virtual ::flx::rtl::con_t *call(::flx::rtl::con_t *, _a5154t_54050 const &)=0;
  virtual _pt54069 *clone()=0;
  virtual ::flx::rtl::con_t *resume()=0;
};

//TYPE 54071: output_text_file * string
struct _tt54071 {
  _a4304t_54070 mem_0;
  _a5154t_54050 mem_1;
  _tt54071(){}
  _tt54071(_a4304t_54070 a0, _a5154t_54050 a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54074: char^2
struct _at54074 {
  static size_t const len = 2;
  typedef char element_type;
  char data[2];
  _at54074() {}
  _at54074(char a0, char a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54075: string * int
struct _tt54075 {
  _a5154t_54050 mem_0;
  int mem_1;
  _tt54075(){}
  _tt54075(_a5154t_54050 a0, int a1):
    mem_0(a0), mem_1(a1){}
};

//TYPE 54099: string * &stat_t * &int
struct _tt54099 {
  _a5154t_54050 mem_0;
  _a10826t_54098* mem_1;
  int* mem_2;
  _tt54099(){}
  _tt54099(_a5154t_54050 a0, _a10826t_54098* a1, int* a2):
    mem_0(a0), mem_1(a1), mem_2(a2){}
};

//TYPE 54101: mode_t^2
struct _at54101 {
  static size_t const len = 2;
  typedef mode_t element_type;
  mode_t data[2];
  _at54101() {}
  _at54101(mode_t a0, mode_t a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54104: errno_t^2
struct _at54104 {
  static size_t const len = 2;
  typedef _a10736t_54103 element_type;
  _a10736t_54103 data[2];
  _at54104() {}
  _at54104(_a10736t_54103 a0, _a10736t_54103 a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54107: RE2 * StringPiece * int * Anchor * &StringPiece * int
struct _tt54107 {
  _a7513t_54055 mem_0;
  _a7515t_54105 mem_1;
  int mem_2;
  _a7578t_54106 mem_3;
  _a7515t_54105* mem_4;
  int mem_5;
  _tt54107(){}
  _tt54107(_a7513t_54055 a0, _a7515t_54105 a1, int a2, _a7578t_54106 a3, _a7515t_54105* a4, int a5):
    mem_0(a0), mem_1(a1), mem_2(a2), mem_3(a3), mem_4(a4), mem_5(a5){}
};

//TYPE 54108: &list[string]^2
struct _at54108 {
  static size_t const len = 2;
  typedef void** element_type;
  void** data[2];
  _at54108() {}
  _at54108(void** a0, void** a1) {
    data[0] = a0;
    data[1] = a1;
  }
};

//TYPE 54109: &list[string] * list[string]
struct _tt54109 {
  void** mem_0;
  void* mem_1;
  _tt54109(){}
  _tt54109(void** a0, void* a1):
    mem_0(a0), mem_1(a1){}
};


//-----------------------------------------
//DEFINE FUNCTION CLASS NAMES
struct _lam_10492;
struct _init_;
struct rfi;
struct _i21768_f21768__lam_10669__apos_2;
struct _i21802_f21802__lam_10669__apos_2;
struct println;
struct _i43906_f43906__lam_10669__apos_2;


//-----------------------------------------
//DEFINE FUNCTION CLASSES

//------------------------------
//FUNCTION <11029>: _lam_10492
struct _lam_10492: _pt54069 {
  FLX_FMEM_DECL

  int j;
  _us2 found;
  int i;
  int _i20678_v20678_j;
  _us2 _i20677_v20677_found;
  int _i20676_v20676_i;
  _a5154t_54050 _urv19284;
  _a5154t_54050 _urv19957;
  _a5154t_54050 _genout_urv19956;
  _a4303t_54072 _genout_urv19955;
  _a5154t_54050 hline;
  _a4303t_54072 f;
  _a5154t_54050 x;
  _lam_10492(FLX_FPAR_DECL_ONLY);
  _lam_10492* clone();
  ::flx::rtl::con_t *call(::flx::rtl::con_t*,_a5154t_54050 const &);
  ::flx::rtl::con_t *resume();
};

//------------------------------
//FUNCTION <11558>: _init_
struct _init_: ::flx::rtl::con_t {
  FLX_FMEM_DECL

  void* t;
  void* _i43951_v43951_iter__apos_2_mv_1002;
  _pt54069* _f_uncurry;
  void* _i43949_v43949_x;
  void* _i43942_v43942_t;
  void* _i43941_v43941_iter__apos_2_mv_1002;
  _pt54069* _i43940_v43940__f_uncurry;
  void* _i43939_v43939_x;
  void* _i22981_v22981_t;
  void* _i22980_v22980_iter__apos_2_mv_1002;
  _pt54069* _i22979_v22979__f_uncurry;
  int _i22353_v22353_j;
  _us2 _i22352_v22352_found;
  int _i22351_v22351_i;
  int _i22350_v22350_j;
  _us2 _i22349_v22349_found;
  int _i22348_v22348_i;
  _a5154t_54050 _i22347_v22347__urv19284;
  _a5154t_54050 _i22346_v22346__urv19957;
  _a5154t_54050 _i22345_v22345__genout_urv19956;
  _a4303t_54072 _i22344_v22344__genout_urv19955;
  _a5154t_54050 _i22343_v22343_hline;
  _a4303t_54072 _i22342_v22342_f;
  void* _i22319_v22319_t;
  void* _i22318_v22318_iter__apos_2_mv_1002;
  _pt54069* _i22317_v22317__f_uncurry;
  void* _i22316_v22316_t;
  void* _i22315_v22315_iter__apos_2_mv_1002;
  _pt54069* _i22314_v22314__f_uncurry;
  _a5154t_54050 h;
  void* _i22312_v22312_t;
  void* _i22311_v22311_iter__apos_2_mv_1002;
  _a4304t_54070 _genout_urv22283;
  void* _i22279_v22279_t;
  void* _i22278_v22278_iter__apos_2_mv_1002;
  _pt54069* _i22277_v22277__f_uncurry;
  void* _i22209_v22209_t;
  void* _i22208_v22208_iter__apos_2_mv_1002;
  _pt54069* _i22207_v22207__f_uncurry;
  void* _i22206_v22206_t;
  void* _i22205_v22205_iter__apos_2_mv_1002;
  _pt54069* _i22204_v22204__f_uncurry;
  void* _i22202_v22202_t;
  void* _i22201_v22201_iter__apos_2_mv_1002;
  void* acc;
  void* _i21801_v21801_aux__apos_2_mv_1014;
  void* init_uncurry;
  void* _i21799_v21799_x;
  void* _urv15991;
  _a2527t_54059 _genout_urv16059;
  void* files;
  int err;
  _a10967t_54060 eret;
  _a10967t_54060 e;
  _a10968t_54061 d;
  _a5154t_54050 _urv16283;
  void* rfi_mv_10658;
  _a5154t_54050 dname2;
  void* _urv21734;
  _a7513t_54055 _genout_urv21733;
  _a5154t_54050 result;
  _a5154t_54050 _urv12865;
  _init_(FLX_FPAR_DECL_ONLY);
  _init_* clone();
  ::flx::rtl::con_t *call(::flx::rtl::con_t*);
  ::flx::rtl::con_t *resume();
};

//------------------------------
//PROCEDURE <21750>: _init_::rfi
struct rfi {
  FLX_FMEM_DECL
  _init_ *ptr_init_;

  void* _i21770_v21770_acc;
  void* _i21767_v21767_aux__apos_2_mv_1014;
  void* _i21766_v21766_init_uncurry;
  void* _i21765_v21765_x;
  void* _i21764_v21764__urv15991;
  void* _i21763_v21763_files;
  _a2527t_54059 _i21762_v21762__genout_urv16059;
  void* _i21761_v21761_files;
  int _i21760_v21760_err;
  _a10967t_54060 _i21759_v21759_eret;
  _a10967t_54060 _i21758_v21758_e;
  _a10968t_54061 _i21757_v21757_d;
  _a5154t_54050 _i21756_v21756__urv16283;
  void* _i21755_v21755_rfi_mv_10658;
  _us2 rfi_mv_10648;
  _a5154t_54050 _i21751_v21751_dname2;
  rfi  (FLX_FPAR_DECL _init_*);
  void* apply(_a5154t_54050 const &);
};

//------------------------------
//PROCEDURE <21768>: _init_::rfi::_lam_10669'2
struct _i21768_f21768__lam_10669__apos_2 {
  FLX_FMEM_DECL
  rfi *ptrrfi;
  _init_ *ptr_init_;

  void* _i21788_v21788_aux__apos_2_mv_992;
  void* x_uncurry;
  void* y;
  void* _urv13454;
  _us2 _urv13478;
  void* last;
  void* z;
  _us2 _genout_urv13542;
  int _i21780_v21780__lam_10669__apos_2_mv_10694;
  mode_t m;
  int _i21777_v21777_err;
  _a10826t_54098 b;
  _a5154t_54050 _urv13921;
  int _i21774_v21774__lam_10669__apos_2_mv_10687;
  _a5154t_54050 _i21773_v21773_d;
  _a5154t_54050 _i21772_v21772__lam_10669__apos_2_mv_10680;
  _a5154t_54050 _i21769_v21769_f;
  _i21768_f21768__lam_10669__apos_2  (FLX_FPAR_DECL rfi*, _init_*);
  void* apply(_a5154t_54050 const &);
};

//------------------------------
//PROCEDURE <21802>: _init_::_lam_10669'2
struct _i21802_f21802__lam_10669__apos_2 {
  FLX_FMEM_DECL
  _init_ *ptr_init_;

  void* _i43908_v43908_acc;
  void* _i43905_v43905_aux__apos_2_mv_1014;
  void* _i43904_v43904_init_uncurry;
  void* _i43903_v43903_x;
  void* _i43902_v43902__urv15991;
  _a2527t_54059 _i43900_v43900__genout_urv16059;
  void* _i43899_v43899_files;
  int _i43898_v43898_err;
  _a10967t_54060 _i43897_v43897_eret;
  _a10967t_54060 _i43896_v43896_e;
  _a10968t_54061 _i43895_v43895_d;
  _a5154t_54050 _i43894_v43894__urv16283;
  void* _i43893_v43893_rfi_mv_10658;
  _a5154t_54050 _i43891_v43891_dname2;
  void* _i21822_v21822_aux__apos_2_mv_992;
  void* _i21821_v21821_x_uncurry;
  void* _i21820_v21820_y;
  void* _i21819_v21819__urv13454;
  _us2 _i21818_v21818__urv13478;
  void* _i21817_v21817_last;
  void* _i21816_v21816_z;
  _us2 _i21815_v21815__genout_urv13542;
  int _i21814_v21814__lam_10669__apos_2_mv_10694;
  mode_t _i21812_v21812_m;
  int _i21811_v21811_err;
  _a10826t_54098 _i21810_v21810_b;
  _a5154t_54050 _i21809_v21809__urv13921;
  int _i21808_v21808__lam_10669__apos_2_mv_10687;
  _a5154t_54050 _i21807_v21807_d;
  _a5154t_54050 _i21806_v21806__lam_10669__apos_2_mv_10680;
  _a5154t_54050 _i21803_v21803_f;
  _i21802_f21802__lam_10669__apos_2  (FLX_FPAR_DECL _init_*);
  void* apply(_a5154t_54050 const &);
};

//------------------------------
//FUNCTION <41367>: println
struct println: _pt54069 {
  FLX_FMEM_DECL

  _a5154t_54050 _i41396_v41396_x;
  println(FLX_FPAR_DECL_ONLY);
  println* clone();
  ::flx::rtl::con_t *call(::flx::rtl::con_t*,_a5154t_54050 const &);
  ::flx::rtl::con_t *resume();
};

//------------------------------
//PURE C PROCEDURE <41402>: add
void* FLX_REGPARM add(FLX_FPAR_DECL  void*, _a5154t_54050);

//------------------------------
//PROCEDURE <43906>: _init_::_lam_10669'2::_lam_10669'2
struct _i43906_f43906__lam_10669__apos_2 {
  FLX_FMEM_DECL
  _i21802_f21802__lam_10669__apos_2 *ptr_i21802_f21802__lam_10669__apos_2;
  _init_ *ptr_init_;

  void* _i43924_v43924_aux__apos_2_mv_992;
  void* _i43923_v43923_x_uncurry;
  void* _i43922_v43922_y;
  void* _i43921_v43921__urv13454;
  _us2 _i43920_v43920__urv13478;
  void* _i43919_v43919_last;
  void* _i43918_v43918_z;
  _us2 _i43917_v43917__genout_urv13542;
  int _i43916_v43916__lam_10669__apos_2_mv_10694;
  mode_t _i43915_v43915_m;
  int _i43914_v43914_err;
  _a10826t_54098 _i43913_v43913_b;
  _a5154t_54050 _i43912_v43912__urv13921;
  int _i43911_v43911__lam_10669__apos_2_mv_10687;
  _a5154t_54050 _i43910_v43910_d;
  _a5154t_54050 _i43909_v43909__lam_10669__apos_2_mv_10680;
  _a5154t_54050 _i43907_v43907_f;
  _i43906_f43906__lam_10669__apos_2  (FLX_FPAR_DECL _i21802_f21802__lam_10669__apos_2*, _init_*);
  void* apply(_a5154t_54050 const &);
};

struct thread_frame_t {
  int argc;
  char **argv;
  FILE *flx_stdin;
  FILE *flx_stdout;
  FILE *flx_stderr;
  ::flx::gc::generic::gc_profile_t *gcp;
  ::flx::gc::generic::gc_shape_t *shape_list_head;
  thread_frame_t(
  );
  _a5154t_54050 INSTALL_ROOT_TOPDIR;
  _a5154t_54050 sep;
  _a4304t_54070 _i11028_v11028_f;
  void* docs;
  _a7513t_54055 re;

};

FLX_DCL_THREAD_FRAME

}} // namespace flxusr::mktutindex
using namespace ::flxusr::mktutindex;
//header complete
#endif
