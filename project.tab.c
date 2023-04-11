
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "project.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<conio.h>
    #include "identifier_data.c"
    void yyerror(char *);
    int yylex(void);
    int typenow=-1;
    struct datatype casedata;
    int caseflag;
    int ifdone[1000];
    int ifptr;
    struct identifier *root=NULL,*last=NULL;
    int sym[26];


/* Line 189 of yacc.c  */
#line 92 "project.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 18 "project.y"

    #ifndef __DT__
    #define __DT__
    struct __DT__ datatype {
        int type;
        char *strval;
        int intval;
        double realval;
    };
    #endif



/* Line 209 of yacc.c  */
#line 130 "project.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VARIABLE = 258,
     VARACCESS = 259,
     NUM = 260,
     STR = 261,
     LE_OP = 262,
     GE_OP = 263,
     EQ_OP = 264,
     NE_OP = 265,
     ALLOCATE = 266,
     SIN = 267,
     ASIN = 268,
     COS = 269,
     ACOS = 270,
     TAN = 271,
     ATAN = 272,
     POW = 273,
     LOG = 274,
     LOG10 = 275,
     RETURN = 276,
     INC = 277,
     DEC = 278,
     ADD = 279,
     SUB = 280,
     IF = 281,
     ELSE_IF = 282,
     ELSE = 283,
     FOR = 284,
     WHILE = 285,
     INT = 286,
     REAL = 287,
     DESCRIBE = 288,
     CLASS = 289,
     FUNC = 290,
     STRING = 291,
     VOID = 292,
     OPTIONS = 293,
     OPTION = 294,
     DEFAULT = 295,
     PRINT = 296,
     IMPORT = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 29 "project.y"

    char text[1009];
    struct datatype val;



/* Line 214 of yacc.c  */
#line 196 "project.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 208 "project.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   690

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,    44,     2,    50,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,     2,
      52,     2,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    18,    24,
      25,    36,    38,    40,    42,    44,    46,    47,    51,    52,
      57,    61,    62,    65,    68,    71,    74,    77,    80,    83,
      86,    89,    90,    99,   100,   107,   111,   112,   114,   115,
     125,   126,   127,   137,   142,   144,   146,   148,   153,   158,
     163,   168,   173,   178,   185,   190,   195,   199,   203,   207,
     211,   215,   219,   223,   227,   231,   235,   239,   242,   244,
     247,   251,   253,   257,   259,   263,   265,   277,   281,   284,
     287,   295,   296,   302,   303,   308,   310
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    57,    55,    -1,    56,    55,    -1,
      74,    55,    -1,    85,    55,    -1,    62,    -1,    34,     3,
      46,    62,    47,    -1,    -1,    59,    35,     3,    48,    60,
      49,    58,    46,    62,    47,    -1,    31,    -1,    32,    -1,
      36,    -1,    37,    -1,     3,    -1,    -1,    59,     3,    61,
      -1,    -1,    50,    59,     3,    61,    -1,    50,    59,     3,
      -1,    -1,    68,    62,    -1,    74,    62,    -1,    78,    62,
      -1,    77,    62,    -1,    80,    62,    -1,    67,    62,    -1,
      73,    62,    -1,    81,    62,    -1,    63,    62,    -1,    -1,
      38,    48,    72,    49,    64,    46,    65,    47,    -1,    -1,
      39,    72,    51,    62,    66,    65,    -1,    40,    51,    62,
      -1,    -1,    72,    -1,    -1,    26,    48,    72,    49,    46,
      62,    47,    69,    70,    -1,    -1,    -1,    27,    48,    72,
      49,    46,    62,    47,    71,    70,    -1,    28,    46,    62,
      47,    -1,     5,    -1,     6,    -1,     4,    -1,    12,    48,
      72,    49,    -1,    13,    48,    72,    49,    -1,    15,    48,
      72,    49,    -1,    14,    48,    72,    49,    -1,    19,    48,
      72,    49,    -1,    20,    48,    72,    49,    -1,    18,    48,
      72,    50,    72,    49,    -1,    16,    48,    72,    49,    -1,
      17,    48,    72,    49,    -1,    72,    24,    72,    -1,    72,
      43,    72,    -1,    72,    45,    72,    -1,    72,    44,    72,
      -1,    72,     7,    72,    -1,    72,     8,    72,    -1,    72,
      52,    72,    -1,    72,    53,    72,    -1,    72,     9,    72,
      -1,    72,    10,    72,    -1,    48,    72,    49,    -1,    21,
      67,    -1,    21,    -1,    59,    75,    -1,    76,    50,    75,
      -1,    76,    -1,     3,    11,    72,    -1,     3,    -1,    79,
      50,    77,    -1,    79,    -1,    29,    48,    74,    51,    72,
      51,    79,    49,    46,    62,    47,    -1,     4,    11,    72,
      -1,     4,    22,    -1,     4,    23,    -1,    30,    48,    72,
      49,    46,    62,    47,    -1,    -1,    41,    48,    82,    83,
      49,    -1,    -1,    72,    84,    50,    83,    -1,    72,    -1,
      42,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    53,    54,    55,    56,    57,    60,    72,
      72,    86,    87,    88,    89,    90,    99,   100,   101,   101,
     102,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   115,   115,   121,   121,   128,   133,   134,   139,   139,
     149,   150,   150,   156,   162,   163,   168,   192,   200,   208,
     216,   224,   232,   240,   253,   261,   269,   272,   275,   278,
     281,   284,   287,   290,   293,   296,   299,   303,   306,   310,
     313,   314,   317,   344,   354,   355,   358,   364,   397,   434,
     473,   479,   479,   484,   484,   487,   491
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VARIABLE", "VARACCESS", "NUM", "STR",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "ALLOCATE", "SIN", "ASIN", "COS",
  "ACOS", "TAN", "ATAN", "POW", "LOG", "LOG10", "RETURN", "INC", "DEC",
  "ADD", "SUB", "IF", "ELSE_IF", "ELSE", "FOR", "WHILE", "INT", "REAL",
  "DESCRIBE", "CLASS", "FUNC", "STRING", "VOID", "OPTIONS", "OPTION",
  "DEFAULT", "PRINT", "IMPORT", "'-'", "'*'", "'/'", "'{'", "'}'", "'('",
  "')'", "','", "':'", "'<'", "'>'", "$accept", "program", "class",
  "function", "$@1", "type", "func_para", "func_paras", "statement",
  "switch", "$@2", "casegrammer", "$@3", "mathexpr", "if", "$@4",
  "elsifgrmr", "$@5", "expression", "return", "declaration", "vars",
  "varr", "assign", "for", "varassign", "while", "print", "$@6", "mul_exp",
  "$@7", "import", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    45,    42,    47,   123,   125,    40,    41,
      44,    58,    60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    56,    58,
      57,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    64,    63,    66,    65,    65,    65,    67,    69,    68,
      70,    71,    70,    70,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    77,    77,    78,    79,    79,    79,
      80,    82,    81,    84,    83,    83,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     1,     5,     0,
      10,     1,     1,     1,     1,     1,     0,     3,     0,     4,
       3,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     8,     0,     6,     3,     0,     1,     0,     9,
       0,     0,     9,     4,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     2,
       3,     1,     3,     1,     3,     1,    11,     3,     2,     2,
       7,     0,     5,     0,     4,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    15,    46,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,     0,    11,    12,
       0,    13,    14,     0,     0,     0,     0,     0,     2,     2,
       0,     7,    21,    21,    21,    37,    21,     2,    21,    21,
      75,    21,    21,     2,     0,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    67,     0,     0,
       0,     0,     0,    81,    86,     0,     1,     4,     3,    73,
       0,    69,    71,     0,    30,    21,    27,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     5,
       7,    25,    24,     0,    26,    29,     6,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,    66,     0,     0,     0,    23,    60,    61,
      64,    65,    56,    57,    59,    58,    62,    63,     0,    74,
      47,    48,    50,    49,    54,    55,     0,    51,    52,     0,
       0,     0,     0,    31,    83,     0,    72,    16,    70,     0,
      21,     0,    21,     8,     0,     0,    82,     0,     0,    53,
       0,     0,     0,    36,     0,    18,     9,    38,     0,    80,
       0,     0,     0,    84,     0,    17,     0,    40,     0,     0,
      21,    32,     0,    21,     0,     0,    39,    21,    21,    35,
      18,     0,     0,    21,     0,    33,    19,    10,     0,     0,
      76,    36,     0,    43,    34,    21,     0,    41,    40,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,   176,    73,   158,   175,    31,    32,
     154,   172,   201,    33,    34,   177,   186,   208,    35,    36,
      75,    71,    72,    38,    39,    40,    41,    42,   112,   145,
     155,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     564,   -67,     3,   -67,   -67,   -43,   -38,   -35,   -31,   -29,
     -21,   -14,   -12,    -6,   642,    -4,     2,     6,   -67,   -67,
      65,   -67,   -67,    24,    25,    74,   642,    78,   564,   564,
      -2,   -67,   604,   604,   604,   521,   604,   564,   604,   604,
      29,   604,   604,   564,   642,   -67,   -67,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   -67,   -67,   642,    15,
     642,    36,   642,   -67,   -67,   117,   -67,   -67,   -67,    75,
      82,   -67,    47,    97,   -67,   604,   -67,   -67,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   642,   -67,   -67,
     -67,   -67,   -67,    98,   -67,   -67,   -67,   521,   173,   184,
     195,   242,   253,   264,    31,   311,   322,   333,    50,   380,
     604,   391,   642,   -67,   642,    55,    97,   -67,   521,   521,
     521,   521,   179,   179,    13,    13,   521,   521,     3,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   642,   -67,   -67,    58,
     642,    59,    61,   -67,   402,    57,   521,    15,   -67,   449,
     604,   460,   604,   -67,    63,    60,   -67,   108,    66,   -67,
      67,    98,    69,    -8,   642,    62,   -67,   -67,    68,   -67,
     642,    77,    71,   -67,    15,   -67,    73,    21,    84,   471,
     604,   -67,   128,   604,    85,    86,   -67,   604,   604,   -67,
      62,    87,   642,   604,    88,   -67,   -67,   -67,   510,    89,
     -67,    -8,    91,   -67,   -67,   604,    92,   -67,    21,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -13,   -67,   -67,   -67,     0,   -67,   -52,   -30,   -67,
     -67,   -61,   -67,   129,   -67,   -67,   -66,   -67,     9,   -67,
      70,    28,   -67,    53,   -67,   -10,   -67,   -67,   -67,   -16,
     -67,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -86
static const yytype_int16 yytable[] =
{
      30,    69,    74,    76,    77,    47,    88,    90,    91,    92,
      48,    94,    95,    49,    44,    67,    68,    50,     1,    51,
      78,    79,    80,    81,    89,    45,    46,    52,    30,    30,
      96,   170,   171,    70,    53,    65,    54,    30,    78,    79,
      80,    81,    55,    30,    58,   117,    18,    19,   184,   185,
      59,    21,    22,    97,    60,    82,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    86,    87,   107,    61,   109,
      37,   111,    62,    63,    83,    84,    85,    64,    66,    93,
     142,   136,   110,    86,    87,   115,   114,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   116,    37,    37,
      69,   140,   128,   147,   150,   152,   156,    37,   153,   163,
     164,   165,   174,    37,   167,   166,   169,   178,   181,   183,
     160,   144,   162,   146,    78,    79,    80,    81,   180,   108,
     187,   190,   193,   192,   197,   200,   203,   205,   196,   207,
     204,    82,   209,    57,   148,   149,   129,   157,   173,   151,
     189,   168,     0,   191,     0,     0,     0,   194,   195,     0,
      83,    84,    85,   199,     0,     0,   113,     0,     0,    86,
      87,     0,     0,   144,   182,   206,     0,     0,     0,   179,
      78,    79,    80,    81,     0,     0,    78,    79,    80,    81,
       0,    78,    79,    80,    81,     0,     0,    82,     0,     0,
       0,   198,    78,    79,    80,    81,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    82,
       0,     0,   130,    84,    85,    86,    87,    83,    84,    85,
       0,    86,    87,   131,     0,     0,    86,    87,    83,    84,
      85,     0,     0,     0,   132,     0,     0,    86,    87,    78,
      79,    80,    81,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,     0,     0,    82,     0,     0,     0,
       0,    78,    79,    80,    81,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,    82,     0,
       0,   133,     0,     0,    86,    87,    83,    84,    85,     0,
       0,     0,   134,     0,     0,    86,    87,    83,    84,    85,
       0,     0,     0,   135,     0,     0,    86,    87,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,    78,
      79,    80,    81,     0,     0,    82,     0,     0,     0,     0,
      78,    79,    80,    81,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    82,     0,     0,
     137,     0,     0,    86,    87,    83,    84,    85,     0,     0,
       0,   138,     0,     0,    86,    87,    83,    84,    85,     0,
       0,     0,   139,     0,     0,    86,    87,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,     0,     0,    82,     0,     0,     0,     0,    78,
      79,    80,    81,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    82,     0,     0,   141,
       0,     0,    86,    87,    83,    84,    85,     0,     0,     0,
     143,     0,     0,    86,    87,    83,    84,    85,     0,     0,
       0,   -85,     0,     0,    86,    87,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
      81,     0,     0,    82,     0,     0,     0,     0,    78,    79,
      80,    81,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    82,     0,     0,   159,     0,
       0,    86,    87,    83,    84,    85,     0,     0,     0,     0,
       0,   161,    86,    87,    83,    84,    85,    78,    79,    80,
      81,     0,   188,    86,    87,     0,     0,     0,    78,    79,
      80,    81,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,     0,     0,     0,   202,
       0,     0,    86,    87,    83,    84,    85,     1,     2,     3,
       4,     0,     0,    86,    87,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
      15,     0,     0,    16,    17,    18,    19,     0,    20,     0,
      21,    22,    23,     0,     0,    24,    25,     1,     2,     3,
       4,     0,    26,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
      15,     0,     0,    16,    17,    18,    19,     0,     0,     0,
      21,    22,    23,     0,     0,    24,    56,     3,     4,     0,
       0,     0,    26,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26
};

static const yytype_int16 yycheck[] =
{
       0,     3,    32,    33,    34,    48,    36,    37,    38,    39,
      48,    41,    42,    48,    11,    28,    29,    48,     3,    48,
       7,     8,     9,    10,    37,    22,    23,    48,    28,    29,
      43,    39,    40,    35,    48,    26,    48,    37,     7,     8,
       9,    10,    48,    43,    48,    75,    31,    32,    27,    28,
      48,    36,    37,    44,    48,    24,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    52,    53,    58,     3,    60,
       0,    62,    48,    48,    43,    44,    45,     3,     0,    50,
     110,    50,    46,    52,    53,     3,    11,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    50,    28,    29,
       3,    51,     4,    48,    46,    46,    49,    37,    47,    46,
      50,     3,    50,    43,    47,    49,    47,    49,    47,    46,
     150,   112,   152,   114,     7,     8,     9,    10,    51,    59,
      46,     3,    46,    48,    47,    47,    47,    46,   190,    47,
     201,    24,   208,    14,   116,   136,    93,   147,   164,   140,
     180,   161,    -1,   183,    -1,    -1,    -1,   187,   188,    -1,
      43,    44,    45,   193,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,   164,   174,   205,    -1,    -1,    -1,   170,
       7,     8,     9,    10,    -1,    -1,     7,     8,     9,    10,
      -1,     7,     8,     9,    10,    -1,    -1,    24,    -1,    -1,
      -1,   192,     7,     8,     9,    10,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    24,
      -1,    -1,    49,    44,    45,    52,    53,    43,    44,    45,
      -1,    52,    53,    49,    -1,    -1,    52,    53,    43,    44,
      45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    -1,    -1,    24,    -1,    -1,    -1,
      -1,     7,     8,     9,    10,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    24,    -1,
      -1,    49,    -1,    -1,    52,    53,    43,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    43,    44,    45,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    -1,    -1,    24,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    24,    -1,    -1,
      49,    -1,    -1,    52,    53,    43,    44,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    43,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    -1,    -1,    24,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    24,    -1,    -1,    49,
      -1,    -1,    52,    53,    43,    44,    45,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,    43,    44,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      10,    -1,    -1,    24,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    24,    -1,    -1,    49,    -1,
      -1,    52,    53,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    43,    44,    45,     7,     8,     9,
      10,    -1,    51,    52,    53,    -1,    -1,    -1,     7,     8,
       9,    10,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    43,    44,    45,     3,     4,     5,
       6,    -1,    -1,    52,    53,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,
      36,    37,    38,    -1,    -1,    41,    42,     3,     4,     5,
       6,    -1,    48,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      36,    37,    38,    -1,    -1,    41,     4,     5,     6,    -1,
      -1,    -1,    48,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    26,    29,    30,    31,    32,
      34,    36,    37,    38,    41,    42,    48,    55,    56,    57,
      59,    62,    63,    67,    68,    72,    73,    74,    77,    78,
      79,    80,    81,    85,    11,    22,    23,    48,    48,    48,
      48,    48,    48,    48,    48,    48,     4,    67,    48,    48,
      48,     3,    48,    48,     3,    72,     0,    55,    55,     3,
      35,    75,    76,    59,    62,    74,    62,    62,     7,     8,
       9,    10,    24,    43,    44,    45,    52,    53,    62,    55,
      62,    62,    62,    50,    62,    62,    55,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    74,    72,
      46,    72,    82,    49,    11,     3,    50,    62,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,     4,    77,
      49,    49,    49,    49,    49,    49,    50,    49,    49,    49,
      51,    49,    62,    49,    72,    83,    72,    48,    75,    72,
      46,    72,    46,    47,    64,    84,    49,    59,    60,    49,
      62,    51,    62,    46,    50,     3,    49,    47,    79,    47,
      39,    40,    65,    83,    50,    61,    58,    69,    49,    72,
      51,    47,    59,    46,    27,    28,    70,    46,    51,    62,
       3,    62,    48,    46,    62,    62,    61,    47,    72,    62,
      47,    66,    49,    47,    65,    46,    62,    47,    71,    70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 50 "project.y"
    {
                    printf("compilation successful\n");
                ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 60 "project.y"
    {  int temp=addNewClass(&root,&last,(yyvsp[(2) - (5)].text),"");
                                                        if(!temp)
                                                        {
                                                            printf("Error: %s is already declared.\n",(yyvsp[(2) - (5)].text));
                                                            exit(-1);
                                                        }   
                                                        else{
                                                            printf("class declared\n");
                                                        }                     

                                                      ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 72 "project.y"
    {
                        char *val;
                        int n=log10(typenow)+1;
                        val=calloc(n+1,sizeof(char));
                        snprintf(val,n,"%ld",typenow);
                        int res=addNewFunc(&root,&last,(yyvsp[(3) - (6)].text),val);
                        if(!res){
                            printf("Compilation error: %s already declared\n",(yyvsp[(3) - (6)].text));
                        }
                        else{
                            printf("function declared: %s\n",(yyvsp[(3) - (6)].text));
                        }
                    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 86 "project.y"
    {typenow=1;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 87 "project.y"
    {typenow=2;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 88 "project.y"
    {typenow=3;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 89 "project.y"
    {typenow=4;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 90 "project.y"
    {
                    struct identifier* temp=getVal(&root,(yyvsp[(1) - (1)].text));
                    if(temp==NULL || temp->data.type!=6){
                        printf("error: class can't be defined\n");
                        exit(-1);
                    }
                    typenow=temp->data.intval;
                ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 115 "project.y"
    {
                        casedata = (yyvsp[(3) - (4)].val);
                        printf("\n\nSwitch case \n");
                        print_datatype(casedata);
                    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 121 "project.y"
    {
                    if(caseflag == 0 && evaluate((yyvsp[(2) - (4)].val),casedata,"==").intval == 1){
                        caseflag = 1;
                        printf("Case executed :: ");
                        print_datatype((yyvsp[(2) - (4)].val));
                    }
                ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 128 "project.y"
    {
                    if(caseflag == 0){
                        printf("Defualt executed\n");
                    }
                ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 134 "project.y"
    {
                    printf("value of the expression: ");
                    print_datatype((yyvsp[(1) - (1)].val));
                ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 139 "project.y"
    {
                        ifptr++;
                        if(boolvalue((yyvsp[(3) - (7)].val))){
                            printf("\n\nif executed\n");
                            ifdone[ifptr]=1;
                        }
                    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 145 "project.y"
    {
                        ifptr--;
                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 150 "project.y"
    {
                if(ifdone[ifptr]==0 && boolvalue((yyvsp[(3) - (7)].val))){
                    ifdone[ifptr]=1;
                    printf("ELSE IF executed\n");
                }
            ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 156 "project.y"
    {
                if(ifdone[ifptr]==0){
                    printf("ELSE executed\n\n");
                }
            ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 162 "project.y"
    {(yyval.val)=(yyvsp[(1) - (1)].val);print_datatype((yyvsp[(1) - (1)].val));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 163 "project.y"
    {
                    
                    print_datatype((yyvsp[(1) - (1)].val));
                    (yyval.val) = (yyvsp[(1) - (1)].val); 
                ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 168 "project.y"
    {
                    struct identifier* res = isDeclared(&root,(yyvsp[(1) - (1)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (1)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if(res->data.type==2)
                        (yyval.val) = make_datatype_int(res->data.intval);
                    else if(res->data.type==3)
                        (yyval.val) = make_datatype_double(res->data.realval);
                    else if(res->data.type==4){
                        (yyval.val) = make_datatype_char(res->data.strval);
                    }
                    print_datatype((yyval.val));
                }
                ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 192 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",sin(val));
            ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 200 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",asin(val));
            ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 208 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",acos(val));
            ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 216 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",cos(val));
            ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 224 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",log(val));
            ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 232 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",log10(val));
            ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 240 "project.y"
    {
                    if((yyvsp[(3) - (6)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    if((yyvsp[(5) - (6)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (6)].val).type==2?(yyvsp[(3) - (6)].val).intval:(yyvsp[(3) - (6)].val).realval;
                    double p = (yyvsp[(5) - (6)].val).type==2?(yyvsp[(5) - (6)].val).intval:(yyvsp[(5) - (6)].val).realval;
                    printf("Value of the expression :: %f\n",pow(val,p));
            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 253 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",tan(val));
            ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 261 "project.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).realval;
                    printf("Value of the expression :: %f\n",atan(val));
            ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 269 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"+");
            ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 272 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"-");
            ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 275 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"/");
            ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 278 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"*");
            ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 281 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"<=");
            ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 284 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),">=");
            ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 287 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"<");
            ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 290 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),">");
            ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 293 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"==");
            ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 296 "project.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"!=");
            ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 299 "project.y"
    { 
                (yyval.val) = (yyvsp[(2) - (3)].val);
            ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 303 "project.y"
    {
                printf("return occured\n");
            ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 306 "project.y"
    {
                printf("void return\n");
            ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 317 "project.y"
    {
                char *val;
                if ((yyvsp[(3) - (3)].val).type == 2) {
                    (yyvsp[(3) - (3)].val).type = 4;
                    int n = log10((yyvsp[(3) - (3)].val).intval) + 1;
                    val = calloc(n + 1, sizeof(char));
                    snprintf(val, n + 1, "%ld", (yyvsp[(3) - (3)].val).intval);
                }
                else if ((yyvsp[(3) - (3)].val).type == 3) {
                    (yyvsp[(3) - (3)].val).type = 4;
                    printf("%lf",(yyvsp[(3) - (3)].val).realval);
                    val = calloc(51, sizeof(char));
                    snprintf(val, 50, "%lf", (yyvsp[(3) - (3)].val).realval);
                }
                else{
                    val = (yyvsp[(3) - (3)].val).strval;
                }
                int res = addNewVal(&root,&last,(yyvsp[(1) - (3)].text),val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else{
                    printf("varriable declared : %s\n",(yyvsp[(1) - (3)].text));
                }
            ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 344 "project.y"
    {
                int temp = addNewVal(&root,&last,(yyvsp[(1) - (1)].text),"");
                if(!temp)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (1)].text));
                    exit(-1);
                }
            ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 358 "project.y"
    {
                    printf("\n\nfor loop\n\n");

                ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 364 "project.y"
    {
                struct identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if((yyvsp[(3) - (3)].val).type == 2){
                        int n = log10((yyvsp[(3) - (3)].val).intval) + 1;
                        char *num = calloc(n, sizeof(char));
                        sprintf(num,"%ld",(yyvsp[(3) - (3)].val).intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),num);
                        printf("Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).intval);
                    }
                    else if((yyvsp[(3) - (3)].val).type == 3){
                        char *num = calloc(51,sizeof(char));
                        snprintf(num,50,"%lf",(yyvsp[(3) - (3)].val).realval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),num);
                        printf("Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).realval);
                    }
                    else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).strval);
                        printf("Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).strval);
                    }
                }
            ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 397 "project.y"
    {
                struct identifier* res = isDeclared(&root,(yyvsp[(1) - (2)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (2)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.realval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"+");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        printf("Value assigned :: %s = %d\n",(yyvsp[(1) - (2)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.realval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        printf("Value assigned :: %s = %f\n",(yyvsp[(1) - (2)].text),tmp2.realval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),tmp2.strval);
                        printf("Value assigned :: %s = %s\n",(yyvsp[(1) - (2)].text),tmp2.strval);
                }
            ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 434 "project.y"
    {
                struct identifier* res = isDeclared(&root,(yyvsp[(1) - (2)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (2)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.realval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"-");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.realval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        printf("Value assigned :: %s = %d\n",(yyvsp[(1) - (2)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.realval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        printf("Value assigned :: %s = %f\n",(yyvsp[(1) - (2)].text),tmp2.realval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),tmp2.strval);
                        printf("Value assigned :: %s = %s\n",(yyvsp[(1) - (2)].text),tmp2.strval);
                }
            ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 473 "project.y"
    {
                    printf("\n\nwhile loop\n");
                    print_datatype((yyvsp[(3) - (7)].val));
                ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 479 "project.y"
    {
                    printf("PRINT : ")
                ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 484 "project.y"
    {
                    print_datatype((yyvsp[(1) - (1)].val));
                ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 487 "project.y"
    {
                    print_datatype((yyvsp[(1) - (1)].val));
                ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 491 "project.y"
    {
                    printf("importing files %s\n",(yyvsp[(2) - (2)].text));
                ;}
    break;



/* Line 1455 of yacc.c  */
#line 2372 "project.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 494 "project.y"


void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    yyparse();
}

