/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "misc/bison.y"

  #include <cstdio>
  #include <iostream>
  #include "../inc/assembler.hpp"
  using namespace std;

  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  extern int line_num;

  

  list<symbol_container> *symbol_list = new list<symbol_container>();

  Assembler assembler = Assembler();

  int location_counter = 0;
  string current_section="";
  unsigned char BBBB = 0;
  unsigned char MMMM = 0;
  unsigned char OP = 0;

  bool mem_ind = false;

  void yyerror(const char *s);

#line 98 "src/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INC_PARSER_HPP_INCLUDED
# define YY_YY_INC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    REG = 258,
    CSR = 259,
    PLUS = 260,
    MINUS = 261,
    PERIOD = 262,
    COL = 263,
    DOLLAR = 264,
    GLOBALDIR = 265,
    EXTERNDIR = 266,
    SECTIONDIR = 267,
    WORDDIR = 268,
    SKIPDIR = 269,
    ENDDIR = 270,
    HALT = 271,
    INT = 272,
    IRET = 273,
    CALL = 274,
    RET = 275,
    JMP = 276,
    BEQ = 277,
    BNE = 278,
    BGT = 279,
    PUSH = 280,
    POP = 281,
    XCHG = 282,
    ADD = 283,
    SUB = 284,
    MUL = 285,
    DIV = 286,
    NOT = 287,
    AND = 288,
    OR = 289,
    XOR = 290,
    SHL = 291,
    SHR = 292,
    LD = 293,
    ST = 294,
    CSRRD = 295,
    CSRWR = 296,
    UNKNOWN = 297,
    ENDL = 298,
    RBRACK = 299,
    LBRACK = 300,
    COMMA = 301,
    NUMBER = 302,
    IDENT = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "misc/bison.y"

  int number;
  char* ident;
  int reg_num;
  int csr_num;

#line 206 "src/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  79
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    64,    66,    68,    71,    77,    79,    81,
      84,    93,    97,   112,   116,   121,   135,   137,   150,   162,
     174,   176,   184,   192,   194,   196,   200,   205,   211,   235,
     251,   256,   261,   268,   274,   286,   321,   342,   351,   356,
     361,   366,   371,   376,   381,   386,   391,   398,   405,   428,
     447,   456,   468,   477,   486,   495,   505,   512,   519,   531,
     548,   554,   561,   569,   576,   581,   583,   585,   589,   594
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REG", "CSR", "PLUS", "MINUS", "PERIOD",
  "COL", "DOLLAR", "GLOBALDIR", "EXTERNDIR", "SECTIONDIR", "WORDDIR",
  "SKIPDIR", "ENDDIR", "HALT", "INT", "IRET", "CALL", "RET", "JMP", "BEQ",
  "BNE", "BGT", "PUSH", "POP", "XCHG", "ADD", "SUB", "MUL", "DIV", "NOT",
  "AND", "OR", "XOR", "SHL", "SHR", "LD", "ST", "CSRRD", "CSRWR",
  "UNKNOWN", "ENDL", "RBRACK", "LBRACK", "COMMA", "NUMBER", "IDENT",
  "$accept", "prog", "line", "label", "directive_or_instruction",
  "directive", "instruction", "no_param_instr", "branch_instr",
  "operand_jmp", "stack_instr", "atomic_swap", "arithmetic_gpr2",
  "arithmetic_gpr1", "ld_st_instr", "csr_instr", "operand_data", "symbol",
  "symbols", "literals", "literal", "symbols_literals", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     100,   -32,   -32,   -32,    -1,     7,   -38,   -38,   -38,   -38,
      -1,   -38,    -1,   -38,   -38,   -38,    15,    16,    17,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,     5,
      18,    19,    21,   -38,    14,    25,   100,   139,   -38,   -38,
     -38,   -38,    26,   -38,   -38,    27,    28,   -38,   -38,   -38,
     -38,   -18,   -18,   -38,   -15,   -14,   -38,   -18,   -12,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -10,   -38,
      -1,    32,    -9,   -38,   -38,    -8,    -7,    -6,   -38,   -38,
     -38,   -38,    -5,    -4,   -38,   -32,   -38,   -38,     7,    40,
     -38,   -38,     1,    41,     5,    45,    47,    46,    52,   -38,
     -38,   -38,    -1,   -38,   -38,   -38,   -38,   -38,    10,   -38,
      20,    22,    -1,   -38,   -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    15,    26,    27,    28,
       0,    29,     0,    30,    31,    32,     0,     0,     0,    38,
      39,    40,    41,    47,    42,    43,    44,    45,    46,     0,
       0,     0,     0,     9,     0,     0,     2,     0,     4,     7,
       8,    16,     0,    20,    25,     0,     0,    23,    24,    60,
      61,    10,    11,    12,     0,     0,    65,    68,    69,    63,
      13,    14,    17,    34,    33,    18,    36,    35,     0,    56,
       0,     0,     0,    55,    54,     0,     0,     0,     6,     1,
       3,     5,     0,     0,    22,     0,    66,    67,     0,     0,
      53,    52,     0,     0,     0,     0,     0,     0,     0,    62,
      64,    37,     0,    57,    48,    49,    50,    51,     0,    21,
       0,     0,     0,    59,    58,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,    23,   -38,   -38,    24,   -38,   -38,   -38,   -38,   -11,
     -38,   -38,   -38,   -38,   -38,   -38,   -37,    -3,    13,   -38,
      -2,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    62,
      43,    44,    45,    46,    47,    48,    72,    50,    51,    58,
      64,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      53,    65,    59,    61,    54,    55,   102,    63,    69,    63,
      54,    55,    54,    55,    70,    52,    49,    57,    66,    67,
      68,    75,    78,    76,    77,    79,    73,    74,    85,    82,
      83,    84,    86,    87,    88,    92,    89,    93,    94,    95,
      96,    97,    98,   101,   104,   103,    56,    49,   106,   108,
      71,   107,    56,    49,    56,   109,   112,   105,     0,    80,
       0,    81,     0,     0,   113,     0,   114,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,   100,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,   110,
     111,   115,     0,     0,     0,     0,     0,     0,     0,    63,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,    33,     0,     0,     0,     0,    34,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,    33
};

static const yytype_int8 yycheck[] =
{
       3,    12,     4,     5,     5,     6,     5,    10,     3,    12,
       5,     6,     5,     6,     9,     2,    48,     4,     3,     3,
       3,     3,     8,     4,     3,     0,    29,    29,    46,     3,
       3,     3,    47,    47,    46,     3,    46,    46,    46,    46,
      46,    46,    46,     3,     3,    44,    47,    48,     3,     3,
      45,     4,    47,    48,    47,     3,    46,    94,    -1,    36,
      -1,    37,    -1,    -1,    44,    -1,    44,    70,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    94,    94,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     102,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    43,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    59,    60,    61,    62,    63,    64,    48,
      66,    67,    67,    66,     5,     6,    47,    67,    68,    69,
      70,    69,    58,    66,    69,    58,     3,     3,     3,     3,
       9,    45,    65,    66,    69,     3,     4,     3,     8,     0,
      50,    53,     3,     3,     3,    46,    47,    47,    46,    46,
      66,    69,     3,    46,    46,    46,    46,    46,    46,    66,
      69,     3,     5,    44,     3,    65,     3,     4,     3,     3,
      66,    69,    46,    44,    44,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    67,    67,    68,    68,    69,    69,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     2,     2,     6,
       1,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     2,     2,     1,     1,     1,     3,     5,     5,
       1,     1,     3,     1,     3,     1,     2,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6:
#line 71 "misc/bison.y"
                {
  //addSymbol(string label, string section, int loc_cnt, bool is_local, bool defined)
  assembler.addSymbol((yyvsp[-1].ident), current_section, location_counter, true, true);
}
#line 1480 "src/parser.cpp"
    break;

  case 10:
#line 84 "misc/bison.y"
                   {
    // assembler.globaldir(symbol_list,"UNDEF");//
    // string a = "undef";
    
    // assembler.addSymbols(symbol_list,"UNDEF");
    assembler.__global(symbol_list);
    // assembler.__skip(symbol_list);
  }
#line 1493 "src/parser.cpp"
    break;

  case 11:
#line 93 "misc/bison.y"
                   {
    assembler.addSymbols(symbol_list, "UNDEF");
  }
#line 1501 "src/parser.cpp"
    break;

  case 12:
#line 97 "misc/bison.y"
                   {
    if(current_section != ""){
      assembler.updateSectionSize(current_section, location_counter);
      assembler.addPoolBytes(current_section);
      assembler.backpatching(current_section);
    }
    cout<<"end of section. section size : "<<location_counter<<endl;
    location_counter = 0;
    //void Assembler::addSymbol(string symbol, string section,
    // int loc_cnt, bool is_local, bool defined)
    assembler.addSymbol((yyvsp[0].ident), (yyvsp[0].ident), location_counter, true, true);
    assembler.createSection((yyvsp[0].ident));
    current_section = (yyvsp[0].ident);
  }
#line 1520 "src/parser.cpp"
    break;

  case 13:
#line 112 "misc/bison.y"
                          {

  }
#line 1528 "src/parser.cpp"
    break;

  case 14:
#line 116 "misc/bison.y"
                 {
    location_counter += (yyvsp[0].number);
    assembler.addBytesToSection(current_section,0,(yyvsp[0].number));
  }
#line 1537 "src/parser.cpp"
    break;

  case 15:
#line 121 "misc/bison.y"
        {
    if(current_section != ""){
      assembler.updateSectionSize(current_section, location_counter);
      assembler.addPoolBytes(current_section);
      assembler.backpatching(current_section);
    }
    cout<<"end of section. section size : "<<location_counter<<endl;

    location_counter = 0;
    // assembler.printSectionBytes(current_section);
  }
#line 1553 "src/parser.cpp"
    break;

  case 17:
#line 137 "misc/bison.y"
                  {
    OP = 2;
    MMMM = 1;
    // if(mem_ind){
    //   MMMM++;
    //   mem_ind = false;
    // }

    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, (OP<<4) | MMMM);
    location_counter += 2;
  }
#line 1570 "src/parser.cpp"
    break;

  case 18:
#line 150 "misc/bison.y"
                 {
    OP = 3;
    MMMM = 0;
    if(mem_ind){
      MMMM += 8;
      mem_ind = false;
    }
    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, (OP<<4) | MMMM);
    location_counter += 2;
  }
#line 1586 "src/parser.cpp"
    break;

  case 19:
#line 162 "misc/bison.y"
                                                  {
    if(mem_ind){
      MMMM += 8;
      mem_ind = false;
    }
    unsigned char last = assembler.popLastByte(current_section);
    assembler.addByteToSection(current_section,((yyvsp[-2].reg_num) << 4) | last);
    assembler.addByteToSection(current_section, (0xf<<4) | (unsigned char)(yyvsp[-4].reg_num));
    assembler.addByteToSection(current_section, (OP<<4) | MMMM);
    location_counter += 2;
  }
#line 1602 "src/parser.cpp"
    break;

  case 21:
#line 176 "misc/bison.y"
                                   {
    assembler.addByteToSection(current_section, 0x00);
    assembler.addByteToSection(current_section, ((yyvsp[-2].reg_num) << 4));
    assembler.addByteToSection(current_section, ((yyvsp[0].reg_num) << 4)|(yyvsp[0].reg_num));
    assembler.addByteToSection(current_section, (OP << 4) | MMMM); 
    location_counter += 4;
  }
#line 1614 "src/parser.cpp"
    break;

  case 22:
#line 184 "misc/bison.y"
                       {
    assembler.addByteToSection(current_section, 0x00);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, ((yyvsp[0].reg_num) << 4)|(yyvsp[0].reg_num));
    assembler.addByteToSection(current_section, (OP << 4) | MMMM); 
    location_counter += 4;
  }
#line 1626 "src/parser.cpp"
    break;

  case 26:
#line 200 "misc/bison.y"
      {
    location_counter += 4;
    assembler.addBytesToSection(current_section, 0x00, 4);
  }
#line 1635 "src/parser.cpp"
    break;

  case 27:
#line 205 "misc/bison.y"
     {
    location_counter += 4;
    assembler.addBytesToSection(current_section, 0x00, 3);
    assembler.addByteToSection(current_section, 0x10);
  }
#line 1645 "src/parser.cpp"
    break;

  case 28:
#line 211 "misc/bison.y"
      {
    //pop pc; pop status;
    //status <= mem32[sp+4]
    assembler.addByteToSection(current_section, 4);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0x0e);
    assembler.addByteToSection(current_section, 0x96);

    //pc <= mem32[sp]
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xfe);
    assembler.addByteToSection(current_section, 0x92);

    //sp <= sp + 8
    assembler.addByteToSection(current_section,8);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xEE);
    assembler.addByteToSection(current_section, 0x91);

    location_counter += 12;
    // assembler.addByteToSection(current_section, )
  }
#line 1673 "src/parser.cpp"
    break;

  case 29:
#line 235 "misc/bison.y"
     {
    // pc <= mem32[sp]
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0xe0);
    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, 0x92);
    // sp <= sp + 4
    assembler.addByteToSection(current_section,4);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xEE);
    assembler.addByteToSection(current_section, 0x91);
    location_counter += 8;
  }
#line 1691 "src/parser.cpp"
    break;

  case 30:
#line 251 "misc/bison.y"
     {
    OP = 3;
    MMMM = 1;
  }
#line 1700 "src/parser.cpp"
    break;

  case 31:
#line 256 "misc/bison.y"
     {
    OP = 3;
    MMMM = 2;
  }
#line 1709 "src/parser.cpp"
    break;

  case 32:
#line 261 "misc/bison.y"
     {
    OP = 3;
    MMMM = 3;
  }
#line 1718 "src/parser.cpp"
    break;

  case 33:
#line 268 "misc/bison.y"
         {
    assembler.addLiteralToPool((yyvsp[0].number), location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2);
    location_counter += 2;
  }
#line 1728 "src/parser.cpp"
    break;

  case 34:
#line 274 "misc/bison.y"
        {
    mem_ind = true;
    cout << "operand_jmp " << (yyvsp[0].ident) << " " << current_section << "  " << location_counter << endl;
    assembler.foundSymbol(current_section, (yyvsp[0].ident), location_counter);
    assembler.addSymbolToPool((yyvsp[0].ident), location_counter, current_section);
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter += 2;
  }
#line 1741 "src/parser.cpp"
    break;

  case 35:
#line 286 "misc/bison.y"
           {
    // // reg <= mem32[sp]
    // assembler.addByteToSection(current_section,0);
    // assembler.addByteToSection(current_section, 0xe0);
    // assembler.addByteToSection(current_section, $2<<4);
    // assembler.addByteToSection(current_section, 0x92);
    // // sp <= sp + 4
    // assembler.addByteToSection(current_section,4);
    // assembler.addByteToSection(current_section, 0);
    // assembler.addByteToSection(current_section, 0xEE);
    // assembler.addByteToSection(current_section, 0x91);
    // location_counter += 8;
    /*

    // pc <= mem32[sp]
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0xe0);
    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, 0x92);
    // sp <= sp + 4
    assembler.addByteToSection(current_section,4);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xEE);
    assembler.addByteToSection(current_section, 0x91);
    location_counter += 8;
    */

    assembler.addByteToSection(current_section,0x04);
    assembler.addByteToSection(current_section,0x00);
    assembler.addByteToSection(current_section,((yyvsp[0].reg_num) << 4) | 0xe);
    assembler.addByteToSection(current_section,0x93);
    location_counter += 4;

  }
#line 1780 "src/parser.cpp"
    break;

  case 36:
#line 321 "misc/bison.y"
            {
    // // sp <= sp - 4;
    // assembler.addByteToSection(current_section,0xfc);
    // assembler.addByteToSection(current_section, 0xff);
    // assembler.addByteToSection(current_section, 0xee);
    // assembler.addByteToSection(current_section, 0x91);
    // // mem[sp] <= reg
    // assembler.addByteToSection(current_section,0);
    // assembler.addByteToSection(current_section, $2 << 4);
    // assembler.addByteToSection(current_section, 0x0e);
    // assembler.addByteToSection(current_section, 0x80);
    // location_counter += 8;
    assembler.addByteToSection(current_section, 0xfc);
    assembler.addByteToSection(current_section, ((yyvsp[0].reg_num)<<4 )| 0xf);
    assembler.addByteToSection(current_section, 0xe0);
    assembler.addByteToSection(current_section, 0x81);
    location_counter += 4;
  }
#line 1803 "src/parser.cpp"
    break;

  case 37:
#line 342 "misc/bison.y"
                        {
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, ((yyvsp[0].reg_num) << 4));
    assembler.addByteToSection(current_section, (yyvsp[-2].reg_num));
    assembler.addByteToSection(current_section, 0x40);
    location_counter += 4;
  }
#line 1815 "src/parser.cpp"
    break;

  case 38:
#line 351 "misc/bison.y"
     {
    OP = 5;
    MMMM = 0;
  }
#line 1824 "src/parser.cpp"
    break;

  case 39:
#line 356 "misc/bison.y"
     {
    OP = 5;
    MMMM = 1;
  }
#line 1833 "src/parser.cpp"
    break;

  case 40:
#line 361 "misc/bison.y"
     {
    OP = 5;
    MMMM = 2;
  }
#line 1842 "src/parser.cpp"
    break;

  case 41:
#line 366 "misc/bison.y"
     {
    OP = 5;
    MMMM = 3;
  }
#line 1851 "src/parser.cpp"
    break;

  case 42:
#line 371 "misc/bison.y"
     {
    OP = 6;
    MMMM = 1;
  }
#line 1860 "src/parser.cpp"
    break;

  case 43:
#line 376 "misc/bison.y"
    {
    OP = 6;
    MMMM = 2;
  }
#line 1869 "src/parser.cpp"
    break;

  case 44:
#line 381 "misc/bison.y"
     {
    OP = 6;
    MMMM = 3;
  }
#line 1878 "src/parser.cpp"
    break;

  case 45:
#line 386 "misc/bison.y"
     {
    OP = 7;
    MMMM = 0;
  }
#line 1887 "src/parser.cpp"
    break;

  case 46:
#line 391 "misc/bison.y"
     {
    OP = 7;
    MMMM = 1;
  }
#line 1896 "src/parser.cpp"
    break;

  case 47:
#line 398 "misc/bison.y"
     {
    OP = 6;
    MMMM = 0;
  }
#line 1905 "src/parser.cpp"
    break;

  case 48:
#line 405 "misc/bison.y"
                             {
    if(mem_ind){
      unsigned char AAAABBBB = ((yyvsp[0].reg_num)<<4)|BBBB;
      assembler.addByteToSection(current_section, AAAABBBB);
      unsigned char OPMMMM = (0x9<<4)|MMMM;
      assembler.addByteToSection(current_section, OPMMMM);
      location_counter += 2;

      assembler.addBytesToSection(current_section, 0 ,2);
      assembler.addByteToSection(current_section, (yyvsp[0].reg_num) << 4 | (yyvsp[0].reg_num));
      assembler.addByteToSection(current_section, OPMMMM);
      location_counter += 4;

      mem_ind = false;
    }else{
      unsigned char AAAABBBB = ((yyvsp[0].reg_num)<<4)|BBBB;
      assembler.addByteToSection(current_section, AAAABBBB);
      unsigned char OPMMMM = (0x9<<4)|MMMM;
      assembler.addByteToSection(current_section, OPMMMM);
      location_counter += 2;
    }
  }
#line 1932 "src/parser.cpp"
    break;

  case 49:
#line 428 "misc/bison.y"
                             {
    //zamena pushovanih nula, registrom u CCCC bite
    if(mem_ind){
      mem_ind = false;
      
    }else{
      MMMM = 0;
    }
    unsigned char CCCCDDDD = assembler.popLastByte(current_section);
    CCCCDDDD |= ((yyvsp[-2].reg_num) << 4);
    assembler.addByteToSection(current_section, CCCCDDDD);
    unsigned char AAAABBBB = BBBB;
    assembler.addByteToSection(current_section, AAAABBBB);
    assembler.addByteToSection(current_section, (8 << 4) | MMMM);
    location_counter += 2;
  }
#line 1953 "src/parser.cpp"
    break;

  case 50:
#line 447 "misc/bison.y"
                         {
    //gpr <= csr
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, ((yyvsp[0].reg_num) << 4) | (yyvsp[-2].csr_num));
    assembler.addByteToSection(current_section, 0x90);
    location_counter += 4;
  }
#line 1966 "src/parser.cpp"
    break;

  case 51:
#line 456 "misc/bison.y"
                         {
    //csr <= gpr
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, ((yyvsp[0].csr_num) << 4) | (yyvsp[-2].reg_num));
    assembler.addByteToSection(current_section, 0x94);
    location_counter += 4;
  }
#line 1979 "src/parser.cpp"
    break;

  case 52:
#line 468 "misc/bison.y"
                {
    BBBB = 0xf;
    MMMM = 0b0010;
    assembler.addLiteralToPool((yyvsp[0].number), location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2);

    location_counter+=2;
  }
#line 1992 "src/parser.cpp"
    break;

  case 53:
#line 477 "misc/bison.y"
               {
    BBBB = 0xf;
    MMMM = 0b0010;
    assembler.foundSymbol(current_section, (yyvsp[0].ident), location_counter);
    assembler.addSymbolToPool((yyvsp[0].ident), location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2); 
    location_counter+=2;
  }
#line 2005 "src/parser.cpp"
    break;

  case 54:
#line 486 "misc/bison.y"
         {
    assembler.addLiteralToPool((yyvsp[0].number), location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2);
    location_counter+=2;
    BBBB = 0xf;
    MMMM = 0b0010;
    mem_ind = true;
  }
#line 2018 "src/parser.cpp"
    break;

  case 55:
#line 495 "misc/bison.y"
        {
    assembler.foundSymbol(current_section, (yyvsp[0].ident), location_counter);
    assembler.addSymbolToPool((yyvsp[0].ident), location_counter, current_section);
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter += 2;
    BBBB = 0xf;
    MMMM = 0b0010;
    mem_ind = true;
  }
#line 2032 "src/parser.cpp"
    break;

  case 56:
#line 505 "misc/bison.y"
       {
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter +=2;
    BBBB = (yyvsp[0].reg_num);
    MMMM = 0b0001;
  }
#line 2043 "src/parser.cpp"
    break;

  case 57:
#line 512 "misc/bison.y"
                     {
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter +=2;
    BBBB = (yyvsp[-1].reg_num);
    MMMM = 0b0010;
  }
#line 2054 "src/parser.cpp"
    break;

  case 58:
#line 519 "misc/bison.y"
                                  {
    if((yyvsp[-1].number)>0xFFF){
      //ERROR RETURN
    }else{
    assembler.addByteToSection(current_section, (unsigned char)(yyvsp[-1].number));
    assembler.addByteToSection(current_section, (unsigned char)((yyvsp[-1].number)>>8));
    location_counter += 2;
    BBBB = (yyvsp[-3].reg_num);
    MMMM = 2;
    }
  }
#line 2070 "src/parser.cpp"
    break;

  case 59:
#line 531 "misc/bison.y"
                                 {
    int sym_val = assembler.getSymbolValue((yyvsp[-1].ident));
    if(sym_val > 0xFFF || sym_val == -1){
      //ERROR RETURN
    }else{
      //relokacija sym_val
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0);
    location_counter += 2;
    BBBB = (yyvsp[-3].reg_num);
    MMMM = 2;
    }
  }
#line 2088 "src/parser.cpp"
    break;

  case 60:
#line 548 "misc/bison.y"
             {

}
#line 2096 "src/parser.cpp"
    break;

  case 61:
#line 554 "misc/bison.y"
        {
    symbol_container cont;
    cont.symbol_name = (yyvsp[0].ident);
    cont.cur_loc_cnt = location_counter;
    symbol_list->push_back(cont);
  }
#line 2107 "src/parser.cpp"
    break;

  case 62:
#line 561 "misc/bison.y"
                      {
    symbol_container cont;
    cont.symbol_name = (yyvsp[0].ident);
    cont.cur_loc_cnt = location_counter;
    symbol_list->push_back(cont);
  }
#line 2118 "src/parser.cpp"
    break;

  case 63:
#line 569 "misc/bison.y"
         {
    location_counter += 4;
    for(int i = 0; i < 4; i++){
      assembler.addByteToSection(current_section, (yyvsp[0].number) >> i * 8);
    }
  }
#line 2129 "src/parser.cpp"
    break;

  case 64:
#line 576 "misc/bison.y"
                        {

  }
#line 2137 "src/parser.cpp"
    break;

  case 65:
#line 581 "misc/bison.y"
                {(yyval.number) = (yyvsp[0].number);}
#line 2143 "src/parser.cpp"
    break;

  case 66:
#line 583 "misc/bison.y"
              {(yyval.number) = (yyvsp[0].number);}
#line 2149 "src/parser.cpp"
    break;

  case 67:
#line 585 "misc/bison.y"
               {(yyval.number) = -1*(yyvsp[0].number);}
#line 2155 "src/parser.cpp"
    break;

  case 68:
#line 589 "misc/bison.y"
           {
      location_counter += 4 * (symbol_list->size());
      assembler.__word(current_section, symbol_list);
    }
#line 2164 "src/parser.cpp"
    break;

  case 69:
#line 594 "misc/bison.y"
            {

    }
#line 2172 "src/parser.cpp"
    break;


#line 2176 "src/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 599 "misc/bison.y"


int main(int argc, char* argv[]){
  char finput[128];
  strcpy(finput, argv[3]);

  FILE *file = fopen(finput, "r");

  if(!file){
    cout<<"File doesn't exist!  " <<argv[3] <<endl;
    return -1;
  }
  yyin = file;
  do{
    yyparse();
  }while(!feof(yyin));
  // assembler.printSymbolTable();
  // assembler.printSectionBytes();
  // assembler.printRelocations();
  assembler.makeOutputFile(argv[2]);
  fclose(file);
  return 0;
}

void yyerror(const char *s) {
  cout << "Greska u parsiranju na liniji " << line_num << "! Poruka: " << s <<endl;
  exit(-1);
}
