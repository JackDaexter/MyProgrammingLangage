/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "exo1.y" /* yacc.c:339  */



int yylex();
int yyerror(char *);

extern int lineno;
int flag_error = 0;
int position = 0;

 #include "table-symbol.h"
FILE *out;

STentry symbolTable[132];
Function symbolFunct[200];

FILE *output;

int jump_label=0;
#define z(instruction) printf("%s\n", instruction)
#define z1(instruction, operande) printf("%s %d\n", instruction, operande)
#define zlabel(ch1, n, ch2) printf("%s%d%s\n", ch1, n, ch2)
char *section;
int is_global = 1; /*Permet de vérifier si les variables sont gloale ou locales */
int call_data = -1; /* Permet de tester si on a déja appeler section.data */
int first = 0; /* Test pour chaque fonction si on à déjà le push */

char *args[] = {"rdi","rsi","rdx","rcx","r8","r9"};
char *reg[] = {"ecx","edx","esi","eax","r8","r9"};
char *taille[] = {"","BYTE","","","DWORD","","","","QWORD"};
char *affect[] = {"ah","al","edx","ecx","eax","rsi","rdi","rcx","rax"};
char name[100];
int use_reg = 0;
int its_global =0;
int its_main = 0;
int nb_args = 0;
int its_call = 0;
int saut = 0;
int g_act = 0;
int posx = 0;
int dont_move = 0;
int adress = 0;
int save = 0;
char nameFunct[100];
int tst = 0;
int nope = 0;
int me = 0;
int its_if = 0;
int its_while = 0;
char vide[100];
int varchar = 0;
char var[100][200];
int valux[100];
int its_affect = 0;
char help[100];

#line 123 "exo1.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "exo1.tab.h".  */
#ifndef YY_YY_EXO1_TAB_H_INCLUDED
# define YY_YY_EXO1_TAB_H_INCLUDED
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
    X = 258,
    P = 259,
    IF = 260,
    ELSE = 261,
    CARACTERE = 262,
    NUM = 263,
    IDENT = 264,
    TYPE = 265,
    EQ = 266,
    ADDSUB = 267,
    DIVSTAR = 268,
    OR = 269,
    AND = 270,
    WHILE = 271,
    RETURN = 272,
    PRINT = 273,
    RACC = 274,
    PO = 275,
    PF = 276,
    LACC = 277,
    READC = 278,
    READE = 279,
    EQUAL = 280,
    CONST = 281,
    VOID = 282,
    ORDERC = 283,
    ORDER = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 60 "exo1.y" /* yacc.c:355  */

  int value;
  int type;
  char carac[3];
  char caractere;
  char name[32];
  char string[2];
  Bvalue litteral;
  Variable var;


#line 205 "exo1.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXO1_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 222 "exo1.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   501

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     5,     2,     2,     2,     2,     2,     2,
       3,     4,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   115,   115,   118,   119,   120,   123,   124,
     125,   126,   127,   128,   129,   130,   133,   134,   137,   138,
     142,   143,   145,   146,   149,   149,   151,   153,   154,   155,
     156,   157,   158,   159,   163,   164,   167,   167,   168,   172,
     172,   186,   186,   198,   199,   200,   201,   202,   203,   204,
     211,   211,   212,   212,   215,   216,   218,   218,   222,   223,
     226,   227,   230,   232,   233,   234,   241,   246,   263,   286,
     286,   308,   309,   309,   311,   311,   311,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   328,
     331,   331,   369,   370,   371,   372,   373,   376,   377,   380,
     381,   383,   384,   386,   405,   407,   434,   436,   470,   473,
     475,   476,   477,   480,   481,   482,   497,   500,   554,   555,
     557,   558,   559,   560,   562,   563,   564,   565,   566,   568,
     569,   570,   571,   572,   573,   576,   577,   579,   581
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'('", "')'", "'!'", "X", "P", "IF",
  "ELSE", "CARACTERE", "NUM", "IDENT", "TYPE", "EQ", "ADDSUB", "DIVSTAR",
  "OR", "AND", "WHILE", "RETURN", "PRINT", "RACC", "PO", "PF", "LACC",
  "READC", "READE", "EQUAL", "CONST", "VOID", "'='", "';'", "ORDERC",
  "ORDER", "','", "'['", "']'", "'{'", "'}'", "$accept", "Prog", "$@1",
  "$@2", "DeclConsts", "ListConst", "Litteral", "NombreSigne", "DeclVars",
  "Declarateurs", "Declarateur", "$@3", "DeclFoncts", "DeclFonct", "@4",
  "EnTeteFonct", "$@5", "$@6", "Parametres", "$@7", "$@8", "ListTypVar",
  "Corps", "$@9", "SuiteInstr", "SuiteBis", "Instr", "$@10", "$@11",
  "$@12", "$@13", "XX", "Exp", "$@14", "EB", "TB", "FB", "M", "E", "T",
  "F", "LValue", "LArray", "Array", "Bloc", "Element", "Arguments",
  "ListExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    40,    41,    33,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,    61,    59,   283,   284,    44,    91,    93,   123,   125
};
# endif

#define YYPACT_NINF -199

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-199)))

#define YYTABLE_NINF -137

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -199,    86,   244,  -199,   -15,    62,  -199,   178,  -199,   167,
      39,    92,    88,   184,  -199,  -199,    84,   206,  -199,  -199,
     206,   206,   113,   119,  -199,   145,    80,   150,    93,   100,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,   129,   128,
    -199,   190,   171,   179,   195,   107,  -199,   203,   207,    98,
    -199,    10,   206,   199,   218,   222,  -199,   233,  -199,    19,
     213,  -199,  -199,  -199,   172,   274,   243,   228,   252,   258,
     114,   227,   257,  -199,  -199,   260,   262,   241,   268,   278,
     248,   290,   478,   254,   259,   218,   188,   -13,  -199,   296,
     299,   307,   218,    62,    62,    62,  -199,  -199,  -199,   303,
     282,  -199,  -199,  -199,   478,  -199,  -199,   298,   478,   424,
    -199,  -199,  -199,  -199,   300,  -199,  -199,  -199,   304,   309,
     309,   309,  -199,   316,  -199,   409,  -199,    46,   319,   321,
     322,   331,   336,   323,   337,   341,  -199,   187,   340,  -199,
    -199,   172,   144,  -199,   343,   355,  -199,   344,   338,   366,
     110,  -199,   478,  -199,   478,   478,   478,   478,   478,   478,
     439,  -199,   383,  -199,     7,    68,   387,   240,  -199,   394,
     377,  -199,   373,   384,  -199,  -199,  -199,  -199,   357,   287,
       6,  -199,  -199,   454,   364,   365,   374,  -199,   331,   336,
     323,   337,   341,  -199,   364,  -199,   454,  -199,   157,     3,
    -199,  -199,  -199,  -199,   376,   454,   454,   454,   389,  -199,
     381,   454,   454,   392,   315,   404,   454,   469,   406,  -199,
    -199,  -199,  -199,    46,    32,  -199,   137,   388,  -199,   393,
     391,    11,    17,  -199,   418,   426,   407,   454,  -199,   434,
     440,   454,  -199,   419,   438,   108,   444,   422,  -199,  -199,
      20,    20,    23,  -199,  -199,   416,  -199,  -199,   420,  -199,
     429,  -199,   425,   432,   428,  -199,  -199,   431,   435,  -199,
    -199,    27,  -199,  -199,  -199,   371,  -199,  -199,   436,  -199,
    -199,  -199,   449,   371,  -199,  -199,  -199,   371,  -199,  -199
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     0,    21,    11,
       0,     0,     0,     0,    17,    18,     0,     0,    10,    16,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
      35,    36,    19,    13,    14,     9,    15,    12,     0,     0,
      38,     0,    26,     0,     0,     0,    23,     0,    41,     0,
      34,     0,     0,     0,    50,    31,    30,     0,    24,     0,
       0,    32,    33,    20,     0,     0,     0,     0,     0,    39,
       0,     0,     0,    37,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    26,    22,     0,
       0,     0,    50,    21,    21,    21,    46,    45,    51,     0,
      53,    43,    29,    47,     0,   114,   113,   117,     0,     0,
      25,   112,    28,    27,     0,    49,    44,    48,     0,    61,
      56,    61,    55,     0,   110,     0,   109,     0,     0,     0,
      96,    98,   100,   102,   104,   106,   108,     0,     0,    40,
      42,     0,     0,    61,     0,     0,   138,     0,   135,     0,
       0,   119,     0,   111,     0,     0,     0,     0,     0,     0,
       0,    90,     0,   118,     0,     0,     0,     0,    74,     0,
       0,    61,     0,     0,    64,    59,    77,    60,     0,     0,
       0,    54,   115,     0,     0,     0,     0,   116,    97,    99,
     101,   103,   105,   107,   113,    92,     0,    93,     0,     0,
      94,    87,    85,    86,     0,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      57,   137,   123,     0,     0,    91,     0,   129,   128,   131,
       0,     0,     0,    88,     0,     0,     0,     0,    65,     0,
       0,     0,    62,     0,     0,     0,     0,     0,   122,   121,
       0,     0,     0,   125,   126,     0,   124,    78,     0,    89,
       0,    83,     0,     0,     0,    81,    80,     0,     0,   133,
     130,     0,   132,   127,    79,     0,    89,    84,     0,    68,
      82,    67,    71,     0,    70,    72,    75,     0,    76,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -199,  -199,  -199,  -199,   261,  -199,    64,  -199,   266,  -199,
     397,  -199,  -199,   442,  -199,  -199,  -199,  -199,   -28,  -199,
    -199,  -199,  -199,  -199,  -116,  -199,    18,  -199,  -199,  -199,
    -199,   196,  -109,  -199,  -199,   324,   318,   320,   325,   317,
     -69,   -79,  -199,  -135,   327,  -198,  -199,  -199
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     5,    12,    18,    19,    13,    45,
      46,    82,    29,    30,    51,    31,    60,    67,    76,    77,
      78,   100,    73,   143,   142,   176,   177,   213,   287,   208,
     288,   275,   178,   196,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   151,   229,   230,   147,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     129,   232,   163,   111,   231,   144,   -58,   149,   198,   201,
     202,    70,   226,   110,   227,    58,   146,     6,   255,   -58,
      83,   226,   227,    59,   271,   111,    79,   179,   226,   111,
      84,   227,    71,   149,   227,   124,   -58,    90,   227,   126,
      20,   199,   150,   228,   203,   199,   250,   149,    72,   199,
     254,   195,   269,   270,   272,   214,   256,   114,   199,   228,
     210,   199,   250,  -120,   118,   199,  -134,    21,   150,   149,
      22,   201,   202,   111,   221,   111,   111,   111,   111,   111,
     111,    33,   150,   187,    34,    35,     3,   225,   248,   249,
     193,     7,    39,    23,    47,    32,   234,   235,   236,    68,
      -4,    26,   239,   240,   150,    48,   203,   244,   246,   149,
      69,   185,   266,    49,    36,     4,    74,    -7,    40,    -7,
      24,   186,    -7,    25,    -7,    -7,    -7,    -7,   260,    -7,
      28,    53,   263,    -7,    -7,    -7,    -7,    -7,   226,    63,
      -7,    -7,    64,    -7,   150,   165,    -7,   166,   227,   104,
      37,    41,   167,    -7,   105,   106,   107,    38,   226,   108,
      52,   -95,    42,   168,   169,   170,   171,   109,   227,   228,
     172,   173,   250,    86,    57,   199,   174,    14,    15,     9,
      61,   -95,    16,   175,    87,    26,    43,    44,   160,   228,
      10,  -112,   -95,    54,   -39,   199,    62,    27,    17,    58,
      75,  -112,  -112,  -112,  -112,  -112,    65,    59,    43,    44,
      66,  -112,   -52,    11,    28,   161,    14,    15,   162,  -112,
    -112,    16,  -112,   150,    55,    56,    55,    56,     4,   -50,
      -7,   -52,    -7,    80,    81,    -7,    85,    -7,    -7,    -7,
      -7,   205,    -7,   206,    91,     4,    -7,    -7,    -7,    -7,
      -7,    92,    -7,    -7,    -7,    54,    -7,    -7,     4,    -7,
      -7,    57,    -7,   207,    96,    -7,    97,    -7,    -7,    -7,
      -7,    98,    -7,    -7,    -7,    89,    -7,    -7,    -7,    -7,
      -7,    99,   101,    -7,    -7,   102,    -7,   -52,   165,    -7,
     166,   112,   104,   282,   103,   167,   113,   105,   106,   107,
     115,   286,   108,   116,   -50,   289,   168,   169,   170,   171,
     109,   117,   220,   172,   173,   122,   165,   123,   166,   174,
     104,   125,   141,   167,   139,   105,   106,   107,   140,   145,
     108,    93,    94,    95,   168,   169,   170,   171,   109,   154,
     242,   172,   173,   152,   180,   153,   166,   174,   104,   155,
     156,   167,   158,   105,   106,   107,   157,   159,   108,   119,
     120,   121,   168,   169,   170,   171,   109,   181,   182,   172,
     173,   164,   165,   183,   166,   174,   104,   184,   211,   167,
     212,   105,   106,   107,   197,   216,   108,   217,   204,   219,
     168,   169,   170,   171,   109,   127,   215,   172,   173,   104,
     -69,   222,   223,   174,   105,   106,   107,   218,   233,   108,
     127,   224,   237,   238,   104,   241,   243,   109,   247,   105,
     106,   107,   257,   251,   108,   127,   209,   258,   252,   104,
     253,   259,   109,  -136,   105,   106,   107,   128,   261,   108,
     127,   262,   265,   264,   104,   267,   268,   109,   273,   105,
     194,   107,   274,   276,   108,   127,   278,   277,   285,   104,
     279,    88,   109,   280,   105,   106,   107,   281,   284,   108,
     245,    50,   283,   189,   104,   192,   190,   109,   188,   105,
     106,   107,   191,   104,   108,     0,     0,     0,   105,   106,
     107,   200,   109,   108,     0,     0,     0,     0,     0,     0,
       0,   109
};

static const yytype_int16 yycheck[] =
{
     109,   199,   137,    82,     1,   121,     0,     1,     1,     3,
       4,     1,     1,    82,    11,    28,   125,    32,     1,    13,
       1,     1,    11,    36,     1,   104,    54,   143,     1,   108,
      11,    11,    22,     1,    11,   104,    30,    65,    11,   108,
       1,    38,    36,    32,    38,    38,    35,     1,    38,    38,
      39,   160,   250,   251,   252,   171,    39,    85,    38,    32,
     169,    38,    35,    31,    92,    38,    39,    28,    36,     1,
      31,     3,     4,   152,   183,   154,   155,   156,   157,   158,
     159,    17,    36,   152,    20,    21,     0,   196,   223,   224,
     159,    29,    12,     1,     1,    11,   205,   206,   207,     1,
       0,     1,   211,   212,    36,    12,    38,   216,   217,     1,
      12,     1,     4,    13,     1,     1,    52,     3,    38,     5,
      32,    11,     8,    35,    10,    11,    12,    13,   237,    15,
      30,     3,   241,    19,    20,    21,    22,    23,     1,    32,
      26,    27,    35,    29,    36,     1,    32,     3,    11,     5,
      31,     1,     8,    39,    10,    11,    12,    12,     1,    15,
      31,     4,    12,    19,    20,    21,    22,    23,    11,    32,
      26,    27,    35,     1,     3,    38,    32,    10,    11,     1,
       1,    24,    15,    39,    12,     1,    36,    37,     1,    32,
      12,     4,    35,     3,    23,    38,     1,    13,    31,    28,
       1,    14,    15,    16,    17,    18,     3,    36,    36,    37,
       3,    24,    13,    35,    30,    28,    10,    11,    31,    32,
      33,    15,    35,    36,    36,    37,    36,    37,     1,    30,
       3,    13,     5,    11,     1,     8,    23,    10,    11,    12,
      13,     1,    15,     3,     1,     1,    19,    20,    21,    22,
      23,    23,    25,    26,    27,     3,    29,    13,     1,    32,
       3,     3,     5,    23,     4,     8,     4,    10,    11,    12,
      13,    30,    15,    29,    30,     1,    19,    20,    21,    22,
      23,    13,     4,    26,    27,    37,    29,    13,     1,    32,
       3,    37,     5,   275,     4,     8,    37,    10,    11,    12,
       4,   283,    15,     4,    30,   287,    19,    20,    21,    22,
      23,     4,    25,    26,    27,    12,     1,    35,     3,    32,
       5,    23,    13,     8,    24,    10,    11,    12,    24,    13,
      15,    70,    71,    72,    19,    20,    21,    22,    23,    17,
      25,    26,    27,    24,     1,    24,     3,    32,     5,    18,
      14,     8,    15,    10,    11,    12,    33,    16,    15,    93,
      94,    95,    19,    20,    21,    22,    23,    12,    24,    26,
      27,    31,     1,    35,     3,    32,     5,    11,     1,     8,
       3,    10,    11,    12,     1,     1,    15,     3,     1,    32,
      19,    20,    21,    22,    23,     1,    23,    26,    27,     5,
      23,    37,    37,    32,    10,    11,    12,    23,    32,    15,
       1,    37,    23,    32,     5,    23,    12,    23,    12,    10,
      11,    12,     4,    35,    15,     1,    32,     1,    35,     5,
      39,    24,    23,    24,    10,    11,    12,    13,     4,    15,
       1,     1,     4,    24,     5,     1,    24,    23,    32,    10,
      11,    12,    32,    24,    15,     1,    24,    32,     9,     5,
      32,    64,    23,    32,    10,    11,    12,    32,    32,    15,
       1,    29,   276,   155,     5,   158,   156,    23,   154,    10,
      11,    12,   157,     5,    15,    -1,    -1,    -1,    10,    11,
      12,   164,    23,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     1,    44,    32,    29,    43,     1,
      12,    35,    45,    48,    10,    11,    15,    31,    46,    47,
       1,    28,    31,     1,    32,    35,     1,    13,    30,    52,
      53,    55,    11,    46,    46,    46,     1,    31,    12,    12,
      38,     1,    12,    36,    37,    49,    50,     1,    12,    13,
      53,    54,    31,     3,     3,    36,    37,     3,    28,    36,
      56,     1,     1,    32,    35,     3,     3,    57,     1,    12,
       1,    22,    38,    62,    46,     1,    58,    59,    60,    58,
      11,     1,    51,     1,    11,    23,     1,    12,    50,     1,
      58,     1,    23,    44,    44,    44,     4,     4,    30,    13,
      61,     4,    37,     4,     5,    10,    11,    12,    15,    23,
      80,    81,    37,    37,    58,     4,     4,     4,    58,    48,
      48,    48,    12,    35,    80,    23,    80,     1,    13,    72,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    24,
      24,    13,    64,    63,    64,    13,    72,    86,    87,     1,
      36,    83,    24,    24,    17,    18,    14,    33,    15,    16,
       1,    28,    31,    83,    31,     1,     3,     8,    19,    20,
      21,    22,    26,    27,    32,    39,    65,    66,    72,    64,
       1,    12,    24,    35,    11,     1,    11,    80,    75,    76,
      77,    78,    79,    80,    11,    72,    73,     1,     1,    38,
      84,     3,     4,    38,     1,     1,     3,    23,    69,    32,
      72,     1,     3,    67,    64,    23,     1,     3,    23,    32,
      25,    72,    37,    37,    37,    72,     1,    11,    32,    84,
      85,     1,    85,    32,    72,    72,    72,    23,    32,    72,
      72,    23,    25,    12,    72,     1,    72,    12,    83,    83,
      35,    35,    35,    39,    39,     1,    39,     4,     1,    24,
      72,     4,     1,    72,    24,     4,     4,     1,    24,    85,
      85,     1,    85,    32,    32,    71,    24,    32,    24,    32,
      32,    32,    66,    71,    32,     9,    66,    68,    70,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    43,    41,    44,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    49,    49,    51,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    52,    52,    54,    53,    53,    56,
      55,    57,    55,    55,    55,    55,    55,    55,    55,    55,
      59,    58,    60,    58,    61,    61,    63,    62,    62,    62,
      64,    64,    65,    66,    66,    66,    66,    66,    66,    67,
      66,    66,    68,    66,    69,    70,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    71,
      73,    72,    72,    72,    72,    72,    72,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    82,    82,
      83,    83,    83,    83,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     5,     4,     2,     0,     5,     3,
       2,     1,     3,     3,     3,     3,     1,     1,     1,     2,
       4,     0,     3,     1,     0,     4,     1,     4,     4,     4,
       2,     2,     2,     2,     2,     1,     0,     3,     2,     0,
       6,     0,     6,     5,     5,     5,     5,     5,     5,     5,
       0,     2,     0,     2,     4,     2,     0,     6,     5,     5,
       2,     0,     3,     2,     1,     3,     2,     5,     5,     0,
       6,     6,     0,     9,     0,     0,     8,     1,     4,     5,
       4,     4,     5,     4,     5,     2,     2,     2,     3,     0,
       0,     4,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     3,     1,     1,     1,     4,     4,     1,     2,     2,
       3,     4,     4,     3,     3,     3,     3,     4,     2,     1,
       3,     1,     3,     3,     3,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 115 "exo1.y" /* yacc.c:1646  */
    {}
#line 1534 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "exo1.y" /* yacc.c:1646  */
    {}
#line 1540 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "exo1.y" /* yacc.c:1646  */
    {lookupFunction(symbolFunct,"main");}
#line 1546 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "exo1.y" /* yacc.c:1646  */
    {addVar(symbolTable,(yyvsp[-2].name),(yyvsp[0].litteral).type,position,is_global,3,(yyvsp[0].litteral).value);}
#line 1552 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 124 "exo1.y" /* yacc.c:1646  */
    {addVar(symbolTable,(yyvsp[-2].name),(yyvsp[0].litteral).type,position,is_global,3,(yyvsp[0].litteral).value);}
#line 1558 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 133 "exo1.y" /* yacc.c:1646  */
    {(yyval.litteral) = (yyvsp[0].litteral);}
#line 1564 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "exo1.y" /* yacc.c:1646  */
    {(yyval.litteral).type = VALUE_CHAR; (yyval.litteral).value = (yyvsp[0].carac)[1];}
#line 1570 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "exo1.y" /* yacc.c:1646  */
    {(yyval.litteral).type = VALUE_INT; (yyval.litteral).value = (yyvsp[0].value);}
#line 1576 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "exo1.y" /* yacc.c:1646  */
    {(yyval.litteral).type = VALUE_INT; if((yyvsp[-1].caractere) == '-'){(yyval.litteral).value = -(yyvsp[0].value);} else {(yyval.litteral).value = (yyvsp[0].value);}}
#line 1582 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 142 "exo1.y" /* yacc.c:1646  */
    {(yyvsp[-4].type) = (yyvsp[-2].type);}
#line 1588 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "exo1.y" /* yacc.c:1646  */
    {its_affect = 1;}
#line 1594 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "exo1.y" /* yacc.c:1646  */
    {if((yyvsp[-4].type) > 0 && (yyvsp[-4].type) <= VALUE_LONG){addVar(symbolTable,(yyvsp[-3].name),(yyvsp[-4].type),position,is_global,0,0);strncpy(var[varchar],(yyvsp[-3].name),strlen((yyvsp[-3].name))); varchar++;}
                                        else{addVar(symbolTable,(yyvsp[-3].name),(yyvsp[(-2) - (4)].type),position,is_global,0,0);strncpy(var[varchar],(yyvsp[-3].name),strlen((yyvsp[-3].name))); varchar++;} }
#line 1601 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "exo1.y" /* yacc.c:1646  */
    {if((yyvsp[(-2) - (1)].type) > 0 && (yyvsp[(-2) - (1)].type) <= VALUE_LONG){addVar(symbolTable,(yyvsp[0].name),(yyvsp[(-2) - (1)].type),position,is_global,0,0);}
                 else  {addVar(symbolTable,(yyvsp[0].name),(yyvsp[-1].type),position,is_global,0,0); }}
#line 1608 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 167 "exo1.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type); }
#line 1614 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 172 "exo1.y" /* yacc.c:1646  */
    {  if(++call_data == 0){
                                         declareGlobal(out,symbolTable);
                                         fprintf(out,"section .text \n");
                                         fprintf(out,"extern printf \n");
                                         fprintf(out,"extern scanf \n");
                                         fprintf(out,"global _start\n");
                                        }
                                        
                                       addFunction(symbolFunct,(yyvsp[0].name),(yyvsp[-1].type),position); 
                                      if(!strcmp((yyvsp[0].name),"main")) {its_main = 1;}
                                       fprintf(out,"%s :\n",returnString(symbolFunct,(yyvsp[0].name)));
                                        fprintf(out,"\t push rsp \n \t mov rbp, rsp \n");  
                                        strncpy(nameFunct,(yyvsp[0].name),strlen((yyvsp[0].name)));}
#line 1632 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 186 "exo1.y" /* yacc.c:1646  */
    { if(++call_data == 0){
                                         declareGlobal(out,symbolTable);
                                         fprintf(out,"section .text \n");
                                         fprintf(out,"extern printf \n");
                                         fprintf(out,"extern scanf \n");
                                         fprintf(out,"global _start\n");
                                        } 
                                       addFunction(symbolFunct,(yyvsp[0].name),(yyvsp[-1].type),position);
                                       if(!strcmp((yyvsp[0].name),"main")) {its_main = 1; }
                                       fprintf(out,"%s :\n",returnString(symbolFunct,(yyvsp[0].name)));
                                       fprintf(out,"\t push rsp \n \t mov rbp, rsp \n ");
                                       strncpy(nameFunct,(yyvsp[0].name),strlen((yyvsp[0].name)));}
#line 1649 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 211 "exo1.y" /* yacc.c:1646  */
    {is_global = 0; ++position;}
#line 1655 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 212 "exo1.y" /* yacc.c:1646  */
    {is_global = 0; ++position;}
#line 1661 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 215 "exo1.y" /* yacc.c:1646  */
    {addArgument(symbolFunct,nameFunct,(yyvsp[-1].type),(yyvsp[0].name));}
#line 1667 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 216 "exo1.y" /* yacc.c:1646  */
    {addArgument(symbolFunct,nameFunct,(yyvsp[-1].type),(yyvsp[0].name));}
#line 1673 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 218 "exo1.y" /* yacc.c:1646  */
    { fprintf(out,"\t sub rsp,%d\n",nbValue()*4); STentry *table;its_affect = 0;
                                  for(int i = 0; i < varchar;i++){fprintf(out,"\t push QWORD %d \n",valux[i]);}
                                  for(int i = varchar-1; i >= 0;i--){if((table = searchIdLocal(symbolTable,var[i],position,is_global)))
                                       {fprintf(out,"\t pop rax \n \t mov [rbp - %d ], %s\n", table->variableLocal.adresse,affect[table->variableLocal.type]);strncpy(var[i],vide,100);}}}
#line 1682 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 221 "exo1.y" /* yacc.c:1646  */
    {if(its_main == 1) { fprintf(out,"\t mov eax,1 \n \t mov ebx,0 \n \t int 0x80 \n"); its_main = 0;} fprintf(out,"\t mov rsp,rbp \n \t pop rbp \n \t ret \n ");strncpy(nameFunct,vide,100);}
#line 1688 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 232 "exo1.y" /* yacc.c:1646  */
    {its_call = 0;}
#line 1694 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 234 "exo1.y" /* yacc.c:1646  */
    {if((yyvsp[(-5) - (3)].type) == 3) {
    					            fprintf(stderr,"Error : line %d : Error, Type void function don't return anything\n",lineno);
                           return 1; 
    				          }
                       fprintf(out,"\t pop rax \n ");
                      
    				          }
#line 1706 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 241 "exo1.y" /* yacc.c:1646  */
    {if((yyvsp[(-5) - (2)].type) == 3) {
    				        fprintf(stderr,"Error : line %d : Error, Type void function don't return anything\n",lineno);
                    return 1;
    			         }}
#line 1715 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 246 "exo1.y" /* yacc.c:1646  */
    {STentry* table = searchIdLocal(symbolTable,(yyvsp[-2].name),position,is_global); 
                            if(table) {
                                    if(table->variableLocal.type != VALUE_INT && table->variableLocal.type != VALUE_LONG) { 
                                    fprintf(stderr,"Error : line %d : readc, error,its a char \n",lineno);
                                    return 1;
                                  }
                              } 
                              fprintf(out,"\t mov rax,rbp \n");
                              fprintf(out,"\t add rax, %d \n",table->variableGlobal.adresse);
                              fprintf(out,"\t mov rsi,rax \n");
                              if(table->variableLocal.type == VALUE_LONG)
                                fprintf(out,"\t mov rdi,read_long \n");
                              else
                                fprintf(out,"\t mov rdi,read_int \n");
                              fprintf(out,"\t mov rax,0 \n");
                              fprintf(out,"\t call scanf WRT ..plt\n");}
#line 1736 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 263 "exo1.y" /* yacc.c:1646  */
    {STentry* table = searchIdLocal(symbolTable,(yyvsp[-2].name),position,is_global);

                               if(table) {
                                    if(table->variableLocal.type != VALUE_CHAR) { 
                                    fprintf(stderr,"Error : line %d : readc, error,its not a char \n",lineno);
                                    return 1;
                                  }
                              }
                              else if ((table = searchIdGlobal(symbolTable,(yyvsp[-2].name),position,is_global))) {
                                    if(table->variableGlobal.type != VALUE_CHAR) { 
                                         fprintf(stderr,"Error : line %d : readc, error,its not a char \n",lineno);
                                         return 1;
                                    }
                                     
                              }
                              fprintf(out,"\t mov rax,rbp \n");
                              fprintf(out,"\t add rax, %d\n",table->variableGlobal.adresse);
                              fprintf(out,"\t mov rsi,rax \n");
                              fprintf(out,"\t mov rdi,read_char \n");
                              fprintf(out,"\t mov rax,0 \n");
                              fprintf(out,"\t call scanf WRT ..plt\n");
    						        	   }
#line 1763 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 286 "exo1.y" /* yacc.c:1646  */
    { me =1;}
#line 1769 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 286 "exo1.y" /* yacc.c:1646  */
    { if(its_call == 0){
                                fprintf(out,"\t pop rax \n");
                              }
                              if((yyvsp[-2].type) == VALUE_INT){
                                  fprintf(out,"\t mov esi, eax \n");
                                  fprintf(out,"\t mov rdi, printf_int \n");
                                  fprintf(out,"\t mov rax,0 \n");
                                  fprintf(out,"\t call  printf WRT ..plt \n");
                               }else if((yyvsp[-2].type) == VALUE_CHAR){
                                  fprintf(out,"\t mov esi, eax \n");
                                  fprintf(out,"\t mov rdi, printf_char\n");
                                  fprintf(out,"\t mov rax,0 \n");
                                  fprintf(out,"\t call  printf WRT ..plt\n");
                               }else{
                                  fprintf(out,"\t mov rsi, rax \n");
                                  fprintf(out,"\t mov rdi, printf_long \n");
                                  fprintf(out,"\t mov rax,0 \n");
                                  fprintf(out,"\t call printf WRT ..plt \n");
                               }
                                 its_call = 0;
                                 me = 0;
                            }
#line 1796 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 308 "exo1.y" /* yacc.c:1646  */
    {fprintf(out,"\t else%d:\n",saut-1);}
#line 1802 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 309 "exo1.y" /* yacc.c:1646  */
    {fprintf(out,"\t jmp end_if%d \n \t else%d: \n",saut,saut);}
#line 1808 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 309 "exo1.y" /* yacc.c:1646  */
    {fprintf(out,"\t end_if%d:\n",saut-1);}
#line 1814 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 311 "exo1.y" /* yacc.c:1646  */
    {fprintf(out,"\t while%d: \n",saut); its_while = 1;}
#line 1820 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 311 "exo1.y" /* yacc.c:1646  */
    {fprintf(out,"\t jmp while%d \t \n \t else%d: \n",saut-1,saut-1);its_while = 0;}
#line 1826 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 311 "exo1.y" /* yacc.c:1646  */
    { /*zlabel("\t jmp while",$<type>7,"");zlabel("\t end_while",$<type>7,":");*/}
#line 1832 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 328 "exo1.y" /* yacc.c:1646  */
    {fprintf(out,"\t begin%d: \n",saut); ++saut;}
#line 1838 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 331 "exo1.y" /* yacc.c:1646  */
    { g_act = 1; if(posx == 1){dont_move = 1;} else {dont_move = 0;} save = adress; if(posx != 2) {nope = 1;}}
#line 1844 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 331 "exo1.y" /* yacc.c:1646  */
    { 
         STentry* table = searchIdLocal(symbolTable,help,position,is_global);
         if ((yyvsp[-3].type) == VALUE_CHAR  && (yyvsp[0].type) == VALUE_LONG) {
              fprintf(stderr,"line %d : Warning conversion to ‘char’ from ‘long int’ may alter its value\n",lineno);
              (yyvsp[-3].type) = (yyvsp[0].type);
              table->variableLocal.type = (yyvsp[0].type);
            
         } 
  		  else if ((yyvsp[-3].type) == VALUE_INT && (yyvsp[0].type) == VALUE_LONG) {
               fprintf(stderr,"line %d : Warning conversion to ‘int’ from ‘long int’ may alter its value\n",lineno);
               (yyvsp[-3].type) = (yyvsp[0].type);
                table->variableLocal.type = (yyvsp[0].type);
           } 
  		  else if ((yyvsp[-3].type) == VALUE_CHAR && (yyvsp[0].type) == VALUE_INT){
  	         fprintf(stderr,"line %d : warning: conversion to ‘char’ from ‘int’ may alter its value \n",lineno);
             (yyvsp[-3].type) = (yyvsp[0].type);
              table->variableLocal.type = (yyvsp[0].type);
  	 	   }
         strncpy(help,vide,100);
         
         fprintf(out,"\t pop rcx\n");
         
         if(dont_move == 1){
           fprintf(out,"\t mov [%s], %s \n ",name,affect[(yyvsp[-3].type) -1]);
         }

        else if(nope == 1){
            fprintf(out,"\t mov QWORD [rbp - %d],rcx \n ",save);
         }
         else{
           fprintf(out,"\t mov QWORD [rbp + %d],%s \n ",save,affect[(yyvsp[-3].type) -1]);
         }
        nope = 0;
         its_global = 0;
         g_act = 0;
          tst = 0;

    }
#line 1887 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 371 "exo1.y" /* yacc.c:1646  */
    {}
#line 1893 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 372 "exo1.y" /* yacc.c:1646  */
    {}
#line 1899 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 377 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);}
#line 1905 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 381 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1911 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 384 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1917 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 386 "exo1.y" /* yacc.c:1646  */
    {{  fprintf(out,"\t pop rcx \n \t pop rax \n");     
                          if (!strcmp((yyvsp[-1].name), ">")){
                            fprintf(out,"\t cmp rax,rcx\n");
                            fprintf(out,"\t jng else%d \n",saut);
                          }
                         else if (!strcmp((yyvsp[-1].name), "<=")){
                            fprintf(out,"\t cmp rax,rcx\n");
                            fprintf(out,"\t jg else%d \n",saut);
                         }
                         else if (!strcmp((yyvsp[-1].name), "<")){
                            fprintf(out," \t cmp rax,rcx\n");
                            fprintf(out,"\t jnl else%d \n",saut);
                         }
                         else if (!strcmp((yyvsp[-1].name), ">=")){
                            fprintf(out,"\t cmp rax,rcx\n");
                            fprintf(out,"\t jl else%d \n",saut);
                         }

                        }}
#line 1941 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 405 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);}
#line 1947 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 407 "exo1.y" /* yacc.c:1646  */
    {   if ((yyvsp[-2].type) == VALUE_LONG || (yyvsp[0].type) == VALUE_LONG){               
                          if((yyvsp[0].type) == VALUE_LONG)
                              (yyval.type) = (yyvsp[0].type); 
                          else if ((yyvsp[-2].type) == VALUE_LONG)
                                       (yyval.type) = (yyvsp[-2].type); 
                        }
                        else if ((yyvsp[-2].type) == VALUE_INT ||(yyvsp[0].type)  == VALUE_INT){
                               if((yyvsp[0].type) == VALUE_INT)
                                    (yyval.type) = (yyvsp[0].type); 
                                else if ((yyvsp[-2].type) == VALUE_INT)
                                    (yyval.type) = (yyvsp[-2].type); 
                        }
                        if((yyvsp[-1].caractere) == '+'){
                           fprintf(out,"\t pop rcx\n ");
                           fprintf(out,"\t pop rax \n");
                           fprintf(out,"\t add rax,rcx \n");
                           fprintf(out,"\t push rax\n ");
                        }
                        else{
                           fprintf(out,"\t pop rcx \n ");
                           fprintf(out,"\t pop rax \n ");
                           fprintf(out,"\t sub rax, rcx \n");
                           fprintf(out,"\t push rax\n ");
                        }
                        
                    }
#line 1978 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 434 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1984 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 436 "exo1.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].type) == VALUE_LONG || (yyvsp[0].type) == VALUE_LONG){               
                          if((yyvsp[0].type) == VALUE_LONG)
                              (yyval.type) = (yyvsp[0].type); 
                          else if ((yyvsp[-2].type) == VALUE_LONG)
                                       (yyval.type) = (yyvsp[-2].type); 
                        }
                        else if ((yyvsp[-2].type) == VALUE_INT || (yyvsp[0].type) == VALUE_INT){
                               if((yyvsp[0].type) == VALUE_INT)
                                    (yyval.type) = (yyvsp[0].type); 
                                else if ((yyvsp[-2].type) == VALUE_INT)
                                    (yyval.type) = (yyvsp[-2].type); 
                        }
                         if((yyvsp[-1].caractere) == '*'){
                           fprintf(out,"\t pop rcx\n ");
                           fprintf(out,"\t pop rax \n");
                           fprintf(out,"\t  imul rax,rcx \n");
                           fprintf(out,"\t push rax \n");
                        }
                        else if((yyvsp[-1].caractere) == '/'){
                           fprintf(out,"\t pop rcx\n");
                           fprintf(out,"\t mov rdx, 0\n");
                           fprintf(out,"\t pop rax\n");
                           fprintf(out,"\t idiv rcx \n");
                           fprintf(out,"\t push rax \n");
                        }
                         else if((yyvsp[-1].caractere) == '%'){
                           fprintf(out,"\t pop rcx\n");
                           fprintf(out,"\t mov rdx, 0\n");
                           fprintf(out,"\t pop rax\n");
                           fprintf(out,"\t idiv rcx \n");
                           fprintf(out,"\t push rdx \n");
                        }
                      }
#line 2022 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 470 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 2028 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 473 "exo1.y" /* yacc.c:1646  */
    { if((yyvsp[-1].caractere) == '-') (yyval.type) = -(yyvsp[0].type); 
                  else (yyval.type) = (yyvsp[0].type); }
#line 2035 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 475 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 2041 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 476 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type);}
#line 2047 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 477 "exo1.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type); if(its_global == 0 && posx == 0) {fprintf(out,"\t push QWORD [rbp - %d] \n ",adress);} 
                           else if (posx == 2 && tst == 0 && g_act != 1){ fprintf(out,"\t push QWORD [rbp + %d] \n ",adress);}
                           else if (me == 1 && posx == 1) {fprintf(out,"\t push QWORD [%s] \n ",name);}}
#line 2055 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 480 "exo1.y" /* yacc.c:1646  */
    { (yyval.type) = VALUE_INT; if(its_affect == 0){fprintf(out,"\t push QWORD %d\n",(yyvsp[0].value));} else{valux[varchar] = (yyvsp[0].value);}}
#line 2061 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 481 "exo1.y" /* yacc.c:1646  */
    {(yyval.type) = VALUE_CHAR; fprintf(out,"\t push BYTE %s \n",(yyvsp[0].carac));}
#line 2067 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 482 "exo1.y" /* yacc.c:1646  */
    {  int nbargg =  getNbArgument( symbolFunct,(yyvsp[-3].name));
                                 //printf("On a %d argument \n",nbarr);
                                 if(lookupFunction(symbolFunct,(yyvsp[-3].name)) == 0){
                                    fprintf(stderr,"Error : This function doesn't exist.\n");
                                    return 1;
                                  }
                                  else if(nbargg != nb_args){

                                     fprintf(stderr,"Error : Error nb Argument : The function %s have %d arguments. Expect %d \n",(yyvsp[-3].name),nb_args,nbargg);
                                     return 1;
                                  }
                                   fprintf(out,"\t call %s \n",(yyvsp[-3].name));
                                   its_call = 1;
                                   nb_args = 0;
                                }
#line 2087 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 497 "exo1.y" /* yacc.c:1646  */
    { if((yyvsp[-2].type) <= VALUE_LONG) { (yyvsp[0].type) = (yyvsp[-2].type);}}
#line 2093 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 500 "exo1.y" /* yacc.c:1646  */
    {STentry* table = searchIdLocal(symbolTable,(yyvsp[0].name),position,is_global);
                  int funct;

    		          if(table) {
                          strncpy(help,(yyvsp[0].name),strlen((yyvsp[0].name)));
                          (yyval.type) = table->variableLocal.type;
                          //printf("\t push %d \n",
                          adress = table->variableLocal.adresse;  
                          its_global = 0;
                          posx = 0;
                    }
                    else if (( funct =  getArgument(symbolFunct,nameFunct,(yyvsp[0].name))) != -1) {
                          posx = 2;
                          adress = 8 + (8 * (funct+1));
                          if(g_act == 1){
                            tst = 1;
                            fprintf(out," \t push QWORD [rbp + %d ] \n",adress);
                          }
                          (yyval.type) = VALUE_LONG;
                  }
                  else if ((table = searchIdGlobal(symbolTable,(yyvsp[0].name),position,is_global))) {
                          if(g_act != 1 && table->variableLocal.type == VALUE_CHAR){
                            table->variableLocal.type = VALUE_INT;
                          }
                         (yyval.type) = table->variableGlobal.type;
                         its_global = 1;
                         strncpy(name,table->variableGlobal.name,strlen(table->variableGlobal.name));
                         if( g_act == 1){
                             its_global = 2;
                             if(table->variableGlobal.isConst == 3){
                               /*fprintf(stderr,"Error : You cannot change const variable %s \n",$1);
                                return 1;*/
                             }
                            fprintf(out,"\t push QWORD [%s] \n",table->variableGlobal.name);
                          }
                          else if(its_if == 1 || its_while ==1){
                            fprintf(out,"\t push QWORD [%s] \n",table->variableGlobal.name);
                          }
                          else{
                            posx = 1;

                          }
                      }
                  
                  else{
                    fprintf(stderr,"Error : The variable %s have not be init \n",(yyvsp[0].name));
                    return 1;
                  }

                  }
#line 2148 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 579 "exo1.y" /* yacc.c:1646  */
    {nb_args++;}
#line 2154 "exo1.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 581 "exo1.y" /* yacc.c:1646  */
    {nb_args++;}
#line 2160 "exo1.tab.c" /* yacc.c:1646  */
    break;


#line 2164 "exo1.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 584 "exo1.y" /* yacc.c:1906  */



int main(){  
  out = fopen("output.asm","w");

  yyparse();
  return flag_error;
}

int yyerror(char *s){
        //IF ERROR RETURN 1 ELSE RETURN 0
	printf("Syntaxe error line %d \n",lineno);
    flag_error = 1; //ERROR 
       
	return 0;
}
