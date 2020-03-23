<<<<<<< HEAD
/* A Bison parser, made by GNU Bison 3.5.3.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.
=======
/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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

<<<<<<< HEAD
/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
<<<<<<< HEAD
#define YYBISON_VERSION "3.5.3"
=======
#define YYBISON_VERSION "3.0.4"
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




<<<<<<< HEAD

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
=======
/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

<<<<<<< HEAD
/* Use api.header.include to #include this header
   instead of duplicating it here.  */
=======
/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
<<<<<<< HEAD
#line 1 "src/parser.y"
=======
#line 1 "src/parser.y" /* yacc.c:355  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

  #include "menu.hpp"

  #include <cassert>
  #include <string>

  extern const astnode * g_root; // A way of getting the AST out

  //extern FILE *yyin; // pointer to input stream

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
   int yylex(void);
   void yyerror(const char *);


<<<<<<< HEAD
#line 129 "src/parser.tab.cpp"
=======
#line 115 "src/parser.tab.cpp" /* yacc.c:355  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
<<<<<<< HEAD
union YYSTYPE
{
#line 20 "src/parser.y"
=======

union YYSTYPE
{
#line 20 "src/parser.y" /* yacc.c:355  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

  astnode * expr;
  int number;
  std::string * str;;

<<<<<<< HEAD
#line 207 "src/parser.tab.cpp"

};
=======
#line 194 "src/parser.tab.cpp" /* yacc.c:355  */
};

>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

<<<<<<< HEAD

=======
/* Copy the second part of user declarations.  */

#line 211 "src/parser.tab.cpp" /* yacc.c:358  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

#ifdef short
# undef short
#endif

<<<<<<< HEAD
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
=======
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
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
<<<<<<< HEAD
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
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;
=======
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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

<<<<<<< HEAD
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
=======
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
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

<<<<<<< HEAD
#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
=======
#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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

<<<<<<< HEAD
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
=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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
<<<<<<< HEAD
  yy_state_t yyss_alloc;
=======
  yytype_int16 yyss_alloc;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
<<<<<<< HEAD
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)
=======
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
<<<<<<< HEAD
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
=======
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
=======
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
<<<<<<< HEAD
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
=======
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
<<<<<<< HEAD
          YYPTRDIFF_T yyi;                      \
=======
          YYSIZE_T yyi;                         \
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   902

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

<<<<<<< HEAD
#define YYUNDEFTOK  2
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
=======
/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
<<<<<<< HEAD
static const yytype_int16 yyrline[] =
=======
static const yytype_uint16 yyrline[] =
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
{
       0,    55,    55,    56,    57,    58,    62,    63,    64,    65,
      66,    67,    68,    69,    73,    74,    78,    79,    80,    81,
      82,    83,    87,    88,    89,    90,    91,    92,    96,    97,
     101,   102,   103,   104,   108,   109,   110,   114,   115,   116,
     120,   121,   122,   123,   124,   128,   129,   130,   134,   135,
     139,   140,   144,   145,   149,   150,   154,   155,   159,   160,
     164,   165,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   183,   184,   188,   192,   193,   197,   198,
     199,   200,   206,   207,   211,   212,   216,   217,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   235,   260,   261,
     301,   302,   306,   307,   308,   309,   310,   312,   315,   317,
     328,   333,   334,   338,   339,   340,   349,   350,   354,   355,
     356,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     373,   374,   375,   379,   380,   384,   385,   386,   387,   388,
     389,   393,   394,   395,   399,   400,   401,   402,   406,   407,
     411,   412,   416,   417,   421,   422,   423,   427,   428,   429,
     430,   435,   436,   437,   438,   443,   444,   448,   451,   452,
     457,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "declarator", "direct_declarator", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "begin", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
<<<<<<< HEAD
static const yytype_int16 yytoknum[] =
=======
static const yytype_uint16 yytoknum[] =
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

<<<<<<< HEAD
#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
=======
#define YYPACT_NINF -167

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     786,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,    34,   -32,  -167,     3,   857,   857,
     -66,    21,    13,   786,    31,  -167,  -167,   -20,  -167,  -167,
     -36,  -167,    94,  -167,  -167,   225,  -167,   355,   178,    21,
    -167,  -167,  -167,    34,  -167,    47,  -167,   -13,  -167,  -167,
     669,   683,   683,   699,    10,    22,    43,    48,   471,    52,
     -23,    38,   489,   575,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,   153,   294,   699,  -167,    60,    28,   168,
      36,   196,    56,    49,    92,   169,    -7,  -167,  -167,   -22,
    -167,     3,  -167,  -167,  -167,   295,   365,  -167,  -167,  -167,
    -167,  -167,    25,   126,   129,  -167,  -167,  -167,  -167,  -167,
     139,  -167,   125,    47,  -167,  -167,   471,   575,  -167,   699,
    -167,  -167,   132,   471,   699,   699,   699,   165,   505,  -167,
    -167,  -167,   -21,     0,   758,    61,   161,   222,  -167,  -167,
     559,   699,   224,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,   699,  -167,   699,   699,   699,   699,
     699,   699,   699,   699,   699,   699,   699,   699,   699,   699,
     699,   699,   699,   699,   699,   699,  -167,  -167,  -167,   401,
    -167,  -167,   744,   587,  -167,    40,  -167,   128,  -167,   857,
    -167,  -167,   -37,  -167,   175,   471,  -167,    70,    97,   102,
     177,   505,  -167,  -167,  -167,   804,   146,  -167,   699,  -167,
    -167,   105,  -167,   156,  -167,  -167,  -167,  -167,  -167,    60,
      60,    28,    28,   168,   168,   168,   168,    36,    36,   196,
      56,    49,    92,   169,     7,  -167,  -167,  -167,   194,   195,
    -167,   176,   128,   840,   629,  -167,   435,  -167,  -167,  -167,
     471,   471,   471,   699,   657,  -167,  -167,   699,  -167,   699,
    -167,  -167,  -167,  -167,   205,  -167,   204,  -167,  -167,   206,
    -167,  -167,   107,   471,   110,  -167,  -167,  -167,  -167,   471,
     188,  -167,   471,  -167,  -167,  -167
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,    97,    86,    87,    89,    90,    91,    92,    95,
      96,    93,    94,    88,     0,   108,   169,     0,    78,    80,
       0,   101,     0,   167,     0,   165,   168,     0,   109,    76,
       0,    82,    84,    79,    81,     0,   171,     0,     0,   100,
     166,     1,   103,     0,    77,     0,   170,     2,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
     152,   144,     6,    16,    28,     0,    30,    34,    37,    40,
      45,    48,    50,    52,    54,    56,    58,    60,    73,     0,
     148,     0,   150,   135,   136,     0,     0,   137,   138,   139,
     140,   107,   115,     0,   110,   111,     2,   105,    28,    75,
       0,    83,    84,     0,   130,    85,     0,     0,    20,     0,
      17,    18,     0,     0,     0,     0,     0,     0,     0,   161,
     162,   163,     0,     0,    99,   116,     0,     0,    12,    13,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    62,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   146,   149,     0,
     145,   151,     0,     0,   113,   118,   114,   119,   106,     0,
     104,   133,     0,   141,     0,     0,   143,     0,     0,     0,
       0,     0,   164,     5,    98,     0,   118,   117,     0,    11,
       8,     0,    14,     0,    10,    61,    31,    32,    33,    35,
      36,    38,    39,    43,    44,    41,    42,    46,    47,    49,
      51,    53,    55,    57,     0,    74,   147,   126,     0,     0,
     122,     0,   120,     0,     0,   112,     0,   131,    21,   142,
       0,     0,     0,     0,     0,    29,     9,     0,     7,     0,
     127,   121,   123,   128,     0,   124,     0,   132,   134,   154,
     156,   157,     0,     0,     0,    15,    59,   129,   125,     0,
       0,   159,     0,   155,   158,   160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,   -18,  -167,   -51,    76,    82,    35,
      84,   103,   101,   106,   115,   100,  -167,   -27,   -44,  -167,
     -49,   -48,   -17,     4,  -167,   239,  -167,   -54,   154,    -2,
     -19,    -8,   -35,  -167,   113,   172,   -81,  -166,   -88,  -167,
     -58,  -167,    59,  -167,   210,  -120,  -167,  -167,  -167,  -167,
    -167,   267,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    72,    73,   211,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   154,
      89,   110,    16,   102,    30,    31,    18,    19,   135,    20,
      21,    22,   238,   104,   105,   136,   239,   187,   115,   192,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    23,
      24,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
<<<<<<< HEAD
static const yytype_int16 yytable[] =
=======
static const yytype_uint16 yytable[] =
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
{
     127,   114,   103,    39,    17,   122,     1,    28,   201,   134,
     173,   109,    27,   132,   133,    32,     1,    35,    90,   242,
     108,   186,    33,    34,   155,   191,   109,    17,     1,   246,
      43,    41,   118,   120,   121,   108,    15,     1,   181,    91,
     242,   112,    42,     1,   175,   175,    44,   247,   163,   164,
     106,    48,    49,    50,   207,    51,    52,   108,   193,   129,
     176,   202,   203,   134,    14,   196,   175,   116,   133,   114,
     133,    15,   174,   175,    14,   197,   198,   199,   178,    36,
     134,   254,    37,   124,    38,    29,   182,   259,   183,   112,
     123,    46,   213,    15,   185,    14,   212,   159,   160,    91,
     184,   182,    15,   183,   125,   216,   217,   218,    63,   126,
     215,   165,   166,   128,    64,    65,    66,    67,    68,    69,
     130,   181,   205,   169,   183,   234,   170,   206,   156,    15,
     113,   235,   250,   157,   158,   241,   175,   249,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   255,   268,   251,
     137,   138,   139,   175,   252,   108,    39,   256,   175,   280,
     171,   257,   282,   175,   185,    45,   175,    35,   161,   162,
      27,   106,    48,    49,    50,   172,    51,    52,   188,   243,
     108,   244,   269,   270,   271,   189,   266,   206,   223,   224,
     225,   226,   114,   190,   272,   274,    45,   205,   264,   183,
     167,   168,   195,   275,   140,   281,   141,   109,   142,   200,
     258,   283,   175,   208,   285,   209,   108,   214,    47,    48,
      49,    50,   276,    51,    52,   219,   220,   248,   253,    63,
     262,   108,   107,   221,   222,    64,    65,    66,    67,    68,
      69,   227,   228,     2,     3,     4,   260,   261,   279,     5,
       6,     7,     8,     9,    10,    11,    12,   277,   278,    13,
     284,   230,   229,   233,    53,    54,    55,   231,    56,    57,
      58,    59,   111,    60,    61,    62,    63,   232,   204,   194,
      40,     0,    64,    65,    66,    67,    68,    69,    47,    48,
      49,    50,   245,    51,    52,   179,     0,    70,    35,    71,
       0,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     2,     3,     4,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,    13,
       0,     0,     0,     0,    53,    54,    55,     0,    56,    57,
      58,    59,     0,    60,    61,    62,    63,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    47,    48,
      49,    50,     0,    51,    52,   153,     0,    70,    35,   177,
       0,     0,     0,     2,     3,     4,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,    13,
       0,     0,     0,     0,    47,    48,    49,    50,     0,    51,
      52,     0,     0,     0,    53,    54,    55,   101,    56,    57,
      58,    59,     0,    60,    61,    62,    63,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,   106,    48,
      49,    50,     0,    51,    52,     0,     0,    70,    35,   180,
      53,    54,    55,     0,    56,    57,    58,    59,     0,    60,
      61,    62,    63,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    47,    48,    49,    50,     0,    51,
      52,     0,     0,    70,    35,   236,     0,     0,     0,     0,
       0,     0,   106,    48,    49,    50,    63,    51,    52,     0,
       0,     0,    64,    65,    66,    67,    68,    69,   106,    48,
      49,    50,     0,    51,    52,     0,     0,     0,   113,   267,
      53,    54,    55,     0,    56,    57,    58,    59,     0,    60,
      61,    62,    63,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      63,     0,     0,    70,    35,     0,    64,    65,    66,    67,
      68,    69,   106,    48,    49,    50,    63,    51,    52,     0,
       0,   131,    64,    65,    66,    67,    68,    69,   106,    48,
      49,    50,     0,    51,    52,     0,     0,    70,     0,     0,
     106,    48,    49,    50,     0,    51,    52,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,    13,
      63,   210,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,   106,    48,    49,    50,    63,    51,    52,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    63,     0,
       0,   240,     0,     0,    64,    65,    66,    67,    68,    69,
     106,    48,    49,    50,     0,    51,    52,     0,     0,     0,
       0,     0,   106,    48,    49,    50,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,   106,    48,    49,    50,
      63,    51,    52,   265,     0,     0,    64,    65,    66,    67,
      68,    69,   106,    48,    49,    50,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,   273,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    69,
     117,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,     0,     0,   119,     0,     0,     1,     0,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,     2,     3,     4,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     2,     0,    13,     1,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,     0,     0,   182,   237,   183,     0,     0,
       0,     0,    15,     0,     2,     3,     4,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,     0,     2,     3,     4,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    14,    13,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   237,   183,     2,     3,
       4,     0,    15,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,     2,     3,     4,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,    13,   263
};

static const yytype_int16 yycheck[] =
{
      58,    45,    37,    22,     0,    53,     3,    15,   128,    63,
      17,    38,    14,    62,    63,    17,     3,    83,    35,   185,
      38,   102,    18,    19,    75,   113,    53,    23,     3,    66,
      66,     0,    50,    51,    52,    53,    68,     3,    96,    35,
     206,    43,    62,     3,    66,    66,    82,    84,    12,    13,
       3,     4,     5,     6,   135,     8,     9,    75,   116,    82,
      82,    82,    62,   117,    61,   123,    66,    80,   117,   113,
     119,    68,    79,    66,    61,   124,   125,   126,    95,    20,
     134,   201,    61,    61,    63,    82,    61,    80,    63,    91,
      80,    32,   141,    68,   102,    61,   140,    69,    70,    95,
     102,    61,    68,    63,    61,   156,   157,   158,    61,    61,
     154,    75,    76,    61,    67,    68,    69,    70,    71,    72,
      82,   179,    61,    67,    63,   174,    77,   135,    68,    68,
      83,   175,    62,    73,    74,   183,    66,   195,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   183,   208,   246,    62,
       7,     8,     9,    66,    62,   183,   185,    62,    66,    62,
      78,    66,    62,    66,   182,    81,    66,    83,    10,    11,
     182,     3,     4,     5,     6,    16,     8,     9,    62,    61,
     208,    63,   250,   251,   252,    66,   244,   205,   163,   164,
     165,   166,   246,    64,   253,   254,    81,    61,   243,    63,
      14,    15,    80,   257,    61,   273,    63,   244,    65,    54,
      64,   279,    66,    62,   282,     3,   244,     3,     3,     4,
       5,     6,   259,     8,     9,   159,   160,    62,    61,    61,
      64,   259,    64,   161,   162,    67,    68,    69,    70,    71,
      72,   167,   168,    28,    29,    30,    62,    62,    52,    34,
      35,    36,    37,    38,    39,    40,    41,    62,    64,    44,
      82,   170,   169,   173,    49,    50,    51,   171,    53,    54,
      55,    56,    43,    58,    59,    60,    61,   172,   134,   117,
      23,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,   189,     8,     9,    95,    -1,    82,    83,    84,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    28,    29,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    49,    50,    51,    -1,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    81,    -1,    82,    83,    84,
      -1,    -1,    -1,    28,    29,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    49,    50,    51,    62,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    82,    83,    84,
      49,    50,    51,    -1,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    61,     8,     9,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    83,    84,
      49,    50,    51,    -1,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    82,    83,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    61,     8,     9,    -1,
      -1,    82,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    82,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    61,     8,     9,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    61,    -1,
      -1,    64,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      61,     8,     9,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    61,    -1,    -1,     3,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    28,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    28,    -1,    44,     3,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    28,    29,    30,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    -1,    28,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    61,    44,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    28,    29,
      30,    -1,    68,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    28,    29,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    44,    61,    68,   107,   108,   111,   112,
     114,   115,   116,   134,   135,   136,   137,   114,   116,    82,
     109,   110,   114,   108,   108,    83,   127,    61,    63,   115,
     136,     0,    62,    66,    82,    81,   127,     3,     4,     5,
       6,     8,     9,    49,    50,    51,    53,    54,    55,    56,
      58,    59,    60,    61,    67,    68,    69,    70,    71,    72,
      82,    84,    86,    87,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   105,
     107,   108,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    62,   108,   117,   118,   119,     3,    64,    89,   102,
     106,   110,   114,    83,   103,   123,    80,    61,    89,    61,
      89,    89,   106,    80,    61,    61,    61,   125,    61,    82,
      82,    82,   105,   105,   112,   113,   120,     7,     8,     9,
      61,    63,    65,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    81,   104,    91,    68,    73,    74,    69,
      70,    10,    11,    12,    13,    75,    76,    14,    15,    67,
      77,    78,    16,    17,    79,    66,    82,    84,   107,   129,
      84,   125,    61,    63,   114,   116,   121,   122,    62,    66,
      64,   123,   124,   125,   120,    80,   125,   105,   105,   105,
      54,   130,    82,    62,   113,    61,   116,   121,    62,     3,
      62,    88,   103,   105,     3,   103,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      97,    98,    99,   100,   105,   103,    84,    62,   117,   121,
      64,   106,   122,    61,    63,   119,    66,    84,    62,   125,
      62,    62,    62,    61,   130,    91,    62,    66,    64,    80,
      62,    62,    64,    62,   117,    64,   106,    84,   123,   125,
     125,   125,   105,    62,   105,   103,   102,    62,    64,    52,
      62,   125,    62,   125,    82,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   115,   116,   116,
     117,   118,   118,   119,   119,   119,   120,   120,   121,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   126,   126,   126,   127,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   131,   132,   132,   132,
     132,   133,   133,   133,   133,   134,   134,   135,   136,   136,
     137,   137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
<<<<<<< HEAD
static const yytype_int8 yyr2[] =
=======
static const yytype_uint8 yyr2[] =
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     3,     4,     3,     4,     3,     1,     2,
       1,     1,     3,     2,     2,     1,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     2,     2,     2,     3,     1,     2,     1,     1,     1,
       3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

<<<<<<< HEAD
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
=======
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
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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


<<<<<<< HEAD
/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
=======
/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
<<<<<<< HEAD
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
=======
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
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
<<<<<<< HEAD
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
=======
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
=======
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
<<<<<<< HEAD
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
=======
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
=======
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
static YYPTRDIFF_T
=======
static YYSIZE_T
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
<<<<<<< HEAD
      YYPTRDIFF_T yyn = 0;
=======
      YYSIZE_T yyn = 0;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
            else
              goto append;

          append:
=======
            /* Fall through.  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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

<<<<<<< HEAD
  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
=======
  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
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
=======
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
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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
<<<<<<< HEAD
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
=======
      int yyn = yypact[*yyssp];
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
=======
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
    default: /* Avoid compiler warnings. */
=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
<<<<<<< HEAD
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
=======
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
          ++yyp;
          ++yyformat;
=======
          yyp++;
          yyformat++;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
    yy_state_fast_t yystate;
=======
    int yystate;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
<<<<<<< HEAD
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;
=======
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

<<<<<<< HEAD
    YYPTRDIFF_T yystacksize;
=======
    YYSIZE_T yystacksize;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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
<<<<<<< HEAD
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
=======
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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

<<<<<<< HEAD

/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
=======
/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

<<<<<<< HEAD

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
=======
 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
<<<<<<< HEAD
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
=======
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
<<<<<<< HEAD
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
=======
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
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
<<<<<<< HEAD
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
=======
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
<<<<<<< HEAD
# undef YYSTACK_RELOCATE
=======
#  undef YYSTACK_RELOCATE
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
<<<<<<< HEAD
=======
#endif /* no yyoverflow */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

<<<<<<< HEAD
      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END
=======
      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
<<<<<<< HEAD
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */
=======

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

<<<<<<< HEAD

=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
/*-----------.
| yybackup.  |
`-----------*/
yybackup:
<<<<<<< HEAD
=======

>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
=======

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

<<<<<<< HEAD
  /* Discard the shifted token.  */
  yychar = YYEMPTY;
=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
| yyreduce -- do a reduction.  |
=======
| yyreduce -- Do a reduction.  |
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
  case 2:
#line 55 "src/parser.y"
                        {(yyval.expr) = new primary_expression(0,*(yyvsp[0].str)); std::cerr << "primary expression 1, which is IDENTIFIER : " <<  *(yyvsp[0].str) << std::endl;}
#line 1736 "src/parser.tab.cpp"
    break;

  case 3:
#line 56 "src/parser.y"
                        {(yyval.expr) = new primary_expression(1,*(yyvsp[0].str)); std::cerr << "primary expression 2, which is const with value: " << *(yyvsp[0].str) <<std::endl;}
#line 1742 "src/parser.tab.cpp"
    break;

  case 4:
#line 57 "src/parser.y"
                         {(yyval.expr) = new primary_expression(2,*(yyvsp[0].str)); std::cerr << "primary expression 3,  which is string literal "<< std::endl;}
#line 1748 "src/parser.tab.cpp"
    break;

  case 5:
#line 58 "src/parser.y"
                             {(yyval.expr) = new primary_expression(3,(yyvsp[-1].expr)); std::cerr << "primary expression 4" << std::endl;}
#line 1754 "src/parser.tab.cpp"
    break;

  case 6:
#line 62 "src/parser.y"
                                                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "postfix expression 1" << std::endl;}
#line 1760 "src/parser.tab.cpp"
    break;

  case 7:
#line 63 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(0, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 2" << std::endl;}
#line 1766 "src/parser.tab.cpp"
    break;

  case 8:
#line 64 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(1, (yyvsp[-2].expr));std::cerr << "postfix expression 3" << std::endl;}
#line 1772 "src/parser.tab.cpp"
    break;

  case 9:
#line 65 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(2, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 4" << std::endl;}
#line 1778 "src/parser.tab.cpp"
    break;

  case 10:
#line 66 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(3, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 5" << std::endl;}
#line 1784 "src/parser.tab.cpp"
    break;

  case 11:
#line 67 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(4, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 6" << std::endl;}
#line 1790 "src/parser.tab.cpp"
    break;

  case 12:
#line 68 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(5, (yyvsp[-1].expr));std::cerr << "postfix expression 7" << std::endl;}
#line 1796 "src/parser.tab.cpp"
    break;

  case 13:
#line 69 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(6, (yyvsp[-1].expr));std::cerr << "postfix expression 8" << std::endl;}
#line 1802 "src/parser.tab.cpp"
    break;

  case 14:
#line 73 "src/parser.y"
                                                                 {(yyval.expr) = new argument_expression_list((yyvsp[0].expr)); std::cerr << "argument expression 1" << std::endl;}
#line 1808 "src/parser.tab.cpp"
    break;

  case 15:
#line 74 "src/parser.y"
                                                                 {(yyval.expr) = new argument_expression_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "argument expression 2" << std::endl;}
#line 1814 "src/parser.tab.cpp"
    break;

  case 16:
#line 78 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "unary expression 1" << std::endl;}
#line 1820 "src/parser.tab.cpp"
    break;

  case 17:
#line 79 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(0, (yyvsp[0].expr)); std::cerr << "unary expression 2" << std::endl;}
#line 1826 "src/parser.tab.cpp"
    break;

  case 18:
#line 80 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(1, (yyvsp[0].expr)); std::cerr << "unary expression 3" << std::endl;}
#line 1832 "src/parser.tab.cpp"
    break;

  case 19:
#line 81 "src/parser.y"
                                           {(yyval.expr) = new unary_expression((yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "unary expression 4" << std::endl;}
#line 1838 "src/parser.tab.cpp"
    break;

  case 20:
#line 82 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(2, (yyvsp[0].expr)); std::cerr << "unary expression 5" << std::endl;}
#line 1844 "src/parser.tab.cpp"
    break;

  case 21:
#line 83 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(3, (yyvsp[-1].expr)); std::cerr << "unary expression 6" << std::endl;}
#line 1850 "src/parser.tab.cpp"
    break;

  case 22:
#line 87 "src/parser.y"
                   {(yyval.number) = 4; std::cerr << "unary operator 1" << std::endl;}
#line 1856 "src/parser.tab.cpp"
    break;

  case 23:
#line 88 "src/parser.y"
                   {(yyval.number) = 5; std::cerr << "unary operator 2" << std::endl;}
#line 1862 "src/parser.tab.cpp"
    break;

  case 24:
#line 89 "src/parser.y"
                   {(yyval.number) = 6; std::cerr << "unary operator 3" << std::endl;}
#line 1868 "src/parser.tab.cpp"
    break;

  case 25:
#line 90 "src/parser.y"
                   {(yyval.number) = 7; std::cerr << "unary operator 4" << std::endl;}
#line 1874 "src/parser.tab.cpp"
    break;

  case 26:
#line 91 "src/parser.y"
                   {(yyval.number) = 8; std::cerr << "unary operator 5" << std::endl;}
#line 1880 "src/parser.tab.cpp"
    break;

  case 27:
#line 92 "src/parser.y"
                   {(yyval.number) = 9; std::cerr << "unary operator 6" << std::endl;}
#line 1886 "src/parser.tab.cpp"
    break;

  case 28:
#line 96 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "cast expression 1" << std::endl;}
#line 1892 "src/parser.tab.cpp"
    break;

  case 29:
#line 97 "src/parser.y"
                                                 {(yyval.expr) = new cast_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "cast expression 2" << std::endl;}
#line 1898 "src/parser.tab.cpp"
    break;

  case 30:
#line 101 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr); std::cerr << "mulitiplicative expression 1" << std::endl;}
#line 1904 "src/parser.tab.cpp"
    break;

  case 31:
#line 102 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(1,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 2" << std::endl;}
#line 1910 "src/parser.tab.cpp"
    break;

  case 32:
#line 103 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(2,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 3" << std::endl;}
#line 1916 "src/parser.tab.cpp"
    break;

  case 33:
#line 104 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(3,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 4" << std::endl;}
#line 1922 "src/parser.tab.cpp"
    break;

  case 34:
#line 108 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr); std::cerr << "additive_expression 1" << std::endl;}
#line 1928 "src/parser.tab.cpp"
    break;

  case 35:
#line 109 "src/parser.y"
                                                             {(yyval.expr) = new additive_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 2" << std::endl;}
#line 1934 "src/parser.tab.cpp"
    break;

  case 36:
#line 110 "src/parser.y"
                                                             {(yyval.expr) = new additive_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 3" << std::endl;}
#line 1940 "src/parser.tab.cpp"
    break;

  case 37:
#line 114 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "shift_expression 1" << std::endl;}
#line 1946 "src/parser.tab.cpp"
    break;

  case 38:
#line 115 "src/parser.y"
                                                       {(yyval.expr) = new shift_expression(1,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 2" << std::endl;}
#line 1952 "src/parser.tab.cpp"
    break;

  case 39:
#line 116 "src/parser.y"
                                                        {(yyval.expr) = new shift_expression(2,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 3" << std::endl;}
#line 1958 "src/parser.tab.cpp"
    break;

  case 40:
#line 120 "src/parser.y"
                                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "relational_expression 1" << std::endl;}
#line 1964 "src/parser.tab.cpp"
    break;

  case 41:
#line 121 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 2" << std::endl;}
#line 1970 "src/parser.tab.cpp"
    break;

  case 42:
#line 122 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 3" << std::endl;}
#line 1976 "src/parser.tab.cpp"
    break;

  case 43:
#line 123 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 4" << std::endl;}
#line 1982 "src/parser.tab.cpp"
    break;

  case 44:
#line 124 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(3, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 5" << std::endl;}
#line 1988 "src/parser.tab.cpp"
    break;

  case 45:
#line 128 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "equality_expression 1" << std::endl;}
#line 1994 "src/parser.tab.cpp"
    break;

  case 46:
#line 129 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(4, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 2" << std::endl;}
#line 2000 "src/parser.tab.cpp"
    break;

  case 47:
#line 130 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(5, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 3" << std::endl;}
#line 2006 "src/parser.tab.cpp"
    break;

  case 48:
#line 134 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "and_expression 1" << std::endl;}
#line 2012 "src/parser.tab.cpp"
    break;

  case 49:
#line 135 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(6, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "and_expression 2" << std::endl;}
#line 2018 "src/parser.tab.cpp"
    break;

  case 50:
#line 139 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "exclusive_or_expression 1" << std::endl;}
#line 2024 "src/parser.tab.cpp"
    break;

  case 51:
#line 140 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(7, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "exclusive_or_expression 2" << std::endl;}
#line 2030 "src/parser.tab.cpp"
    break;

  case 52:
#line 144 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "inclusive_or_expression 1" << std::endl;}
#line 2036 "src/parser.tab.cpp"
    break;

  case 53:
#line 145 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(8, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "inclusive_or_expression 2" << std::endl;}
#line 2042 "src/parser.tab.cpp"
    break;

  case 54:
#line 149 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_and_expression 1" << std::endl;}
#line 2048 "src/parser.tab.cpp"
    break;

  case 55:
#line 150 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(9, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_and_expression 2" << std::endl;}
#line 2054 "src/parser.tab.cpp"
    break;

  case 56:
#line 154 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_or_expression 1" << std::endl;}
#line 2060 "src/parser.tab.cpp"
    break;

  case 57:
#line 155 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(10, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_or_expression 2" << std::endl;}
#line 2066 "src/parser.tab.cpp"
    break;

  case 58:
#line 159 "src/parser.y"
                                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "conditional expression 1" << std::endl;}
#line 2072 "src/parser.tab.cpp"
    break;

  case 59:
#line 160 "src/parser.y"
                                                                             {(yyval.expr) = new conditional_expression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "conditional expression 2" << std::endl;}
#line 2078 "src/parser.tab.cpp"
    break;

  case 60:
#line 164 "src/parser.y"
                                                                             {(yyval.expr) = new assignment_expression((yyvsp[0].expr)); std::cerr << "assignment expression 1" << std::endl;}
#line 2084 "src/parser.tab.cpp"
    break;

  case 61:
#line 165 "src/parser.y"
                                                                             {(yyval.expr) = new assignment_expression((yyvsp[-2].expr), (yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "assignment expression 2" << std::endl;}
#line 2090 "src/parser.tab.cpp"
    break;

  case 62:
#line 169 "src/parser.y"
                             {(yyval.number) = 0; std::cerr << "assignment operator 1" << std::endl;}
#line 2096 "src/parser.tab.cpp"
    break;

  case 63:
#line 170 "src/parser.y"
                             {(yyval.number) = 1; std::cerr << "assignment operator 2" << std::endl;}
#line 2102 "src/parser.tab.cpp"
    break;

  case 64:
#line 171 "src/parser.y"
                             {(yyval.number) = 2; std::cerr << "assignment operator 3" << std::endl;}
#line 2108 "src/parser.tab.cpp"
    break;

  case 65:
#line 172 "src/parser.y"
                             {(yyval.number) = 3; std::cerr << "assignment operator 4" << std::endl;}
#line 2114 "src/parser.tab.cpp"
    break;

  case 66:
#line 173 "src/parser.y"
                             {(yyval.number) = 4; std::cerr << "assignment operator 5" << std::endl;}
#line 2120 "src/parser.tab.cpp"
    break;

  case 67:
#line 174 "src/parser.y"
                             {(yyval.number) = 5; std::cerr << "assignment operator 6" << std::endl;}
#line 2126 "src/parser.tab.cpp"
    break;

  case 68:
#line 175 "src/parser.y"
                             {(yyval.number) = 6; std::cerr << "assignment operator 7" << std::endl;}
#line 2132 "src/parser.tab.cpp"
    break;

  case 69:
#line 176 "src/parser.y"
                             {(yyval.number) = 7; std::cerr << "assignment operator 8" << std::endl;}
#line 2138 "src/parser.tab.cpp"
    break;

  case 70:
#line 177 "src/parser.y"
                             {(yyval.number) = 8; std::cerr << "assignment operator 9" << std::endl;}
#line 2144 "src/parser.tab.cpp"
    break;

  case 71:
#line 178 "src/parser.y"
                             {(yyval.number) = 9; std::cerr << "assignment operator 10" << std::endl;}
#line 2150 "src/parser.tab.cpp"
    break;

  case 72:
#line 179 "src/parser.y"
                             {(yyval.number) = 10; std::cerr << "assignment operator 11" << std::endl;}
#line 2156 "src/parser.tab.cpp"
    break;

  case 73:
#line 183 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "expression 1" << std::endl;}
#line 2162 "src/parser.tab.cpp"
    break;

  case 74:
#line 184 "src/parser.y"
                                                 {(yyval.expr) = new base_expression((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "expression 2" << std::endl;}
#line 2168 "src/parser.tab.cpp"
    break;

  case 75:
#line 188 "src/parser.y"
                                   {(yyval.expr) = (yyvsp[0].expr); std::cerr << "constant_expression 0" << std::endl;}
#line 2174 "src/parser.tab.cpp"
    break;

  case 76:
#line 192 "src/parser.y"
                                      {(yyval.expr) = new declaration((yyvsp[-1].expr)); std::cerr << "declaration 0 " << std::endl;}
#line 2180 "src/parser.tab.cpp"
    break;

  case 77:
#line 193 "src/parser.y"
                                                           {(yyval.expr) = new declaration((yyvsp[-2].expr), (yyvsp[-1].expr));std::cerr << "declaration 1 " << std::endl;}
#line 2186 "src/parser.tab.cpp"
    break;

  case 78:
#line 197 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 0" << std::endl;}
#line 2192 "src/parser.tab.cpp"
    break;

  case 79:
#line 198 "src/parser.y"
                                                           {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 1" << std::endl;}
#line 2198 "src/parser.tab.cpp"
    break;

  case 80:
#line 199 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 2" << std::endl;}
#line 2204 "src/parser.tab.cpp"
    break;

  case 81:
#line 200 "src/parser.y"
                                                   {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 3" << std::endl;}
#line 2210 "src/parser.tab.cpp"
    break;

  case 82:
#line 206 "src/parser.y"
                            {(yyval.expr) = (yyvsp[0].expr); std::cerr << "init_declarator_list 0 " << std::endl;}
#line 2216 "src/parser.tab.cpp"
    break;

  case 83:
#line 207 "src/parser.y"
                                                     {(yyval.expr) = new init_declarator_list((yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "init_declarator_list 1" << std::endl;}
#line 2222 "src/parser.tab.cpp"
    break;

  case 84:
#line 211 "src/parser.y"
                       {(yyval.expr) = new init_declarator((yyvsp[0].expr)); std::cerr << "init_declarator 0 " << std::endl;}
#line 2228 "src/parser.tab.cpp"
    break;

  case 85:
#line 212 "src/parser.y"
                                       {(yyval.expr) = new init_declarator((yyvsp[-2].expr),(yyvsp[0].expr));  std::cerr << "init_declarator 1" << std::endl;}
#line 2234 "src/parser.tab.cpp"
    break;

  case 86:
#line 216 "src/parser.y"
                   {(yyval.expr) = new storage_class_specifier(0); std::cerr << "storage_class_specifier typedef 0 " << std::endl;}
#line 2240 "src/parser.tab.cpp"
    break;

  case 87:
#line 217 "src/parser.y"
                   {(yyval.expr) = new storage_class_specifier(1);  std::cerr << "storage_class_specifier typedef 1 " << std::endl;}
#line 2246 "src/parser.tab.cpp"
    break;

  case 88:
#line 224 "src/parser.y"
                 {(yyval.expr) = new type_specifier(0); std::cerr << "type_specifier void" << std::endl;}
#line 2252 "src/parser.tab.cpp"
    break;

  case 89:
#line 225 "src/parser.y"
                 {(yyval.expr) = new type_specifier(1); std::cerr << "type_specifier char" << std::endl;}
#line 2258 "src/parser.tab.cpp"
    break;

  case 90:
#line 226 "src/parser.y"
                  {(yyval.expr) = new type_specifier(2); std::cerr << "type_specifier short" << std::endl;}
#line 2264 "src/parser.tab.cpp"
    break;

  case 91:
#line 227 "src/parser.y"
                {(yyval.expr) = new type_specifier(3); std::cerr << "type_specifier int" << std::endl;}
#line 2270 "src/parser.tab.cpp"
    break;

  case 92:
#line 228 "src/parser.y"
                 {(yyval.expr) = new type_specifier(4); std::cerr << "type_specifier long 5" << std::endl;}
#line 2276 "src/parser.tab.cpp"
    break;

  case 93:
#line 229 "src/parser.y"
                  {(yyval.expr) = new type_specifier(5); std::cerr << "type_specifier float 6" << std::endl;}
#line 2282 "src/parser.tab.cpp"
    break;

  case 94:
#line 230 "src/parser.y"
                   {(yyval.expr) = new type_specifier(6); std::cerr << "type_specifier double 7" << std::endl;}
#line 2288 "src/parser.tab.cpp"
    break;

  case 95:
#line 231 "src/parser.y"
                   {(yyval.expr) = new type_specifier(7); std::cerr << "type_specifier signed 8" << std::endl;}
#line 2294 "src/parser.tab.cpp"
    break;

  case 96:
#line 232 "src/parser.y"
                     {(yyval.expr) = new type_specifier(8); std::cerr << "type_specifier signed unsigned 9" << std::endl;}
#line 2300 "src/parser.tab.cpp"
    break;

  case 97:
#line 235 "src/parser.y"
                      {(yyval.expr) = new type_specifier(9); std::cerr << "type_name" << std::endl;}
#line 2306 "src/parser.tab.cpp"
    break;

  case 98:
#line 260 "src/parser.y"
                                                  {(yyval.expr) = new specifier_qualifier_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "specifier_qualifier_list 0" << std::endl;}
#line 2312 "src/parser.tab.cpp"
    break;

  case 99:
#line 261 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "specifier_qualifier_list 1" << std::endl;}
#line 2318 "src/parser.tab.cpp"
    break;

  case 100:
#line 301 "src/parser.y"
                                     {(yyval.expr) = new declarator((yyvsp[-1].expr), (yyvsp[0].expr));  std::cerr << "declarator 0" << std::endl;}
#line 2324 "src/parser.tab.cpp"
    break;

  case 101:
#line 302 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "declarator 1" << std::endl;}
#line 2330 "src/parser.tab.cpp"
    break;

  case 102:
#line 306 "src/parser.y"
                       {(yyval.expr) = new direct_declarator(0,*(yyvsp[0].str));std::cerr << "direct_declarator 0,IDENTIFIER : " << *(yyvsp[0].str) <<std::endl; }
#line 2336 "src/parser.tab.cpp"
    break;

  case 103:
#line 307 "src/parser.y"
                              {(yyval.expr) = new direct_declarator(1,(yyvsp[-1].expr)); std::cerr << "direct_declarator 1" << std::endl;}
#line 2342 "src/parser.tab.cpp"
    break;

  case 104:
#line 308 "src/parser.y"
                                                         {(yyval.expr) = new direct_declarator(2,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 2" << std::endl;}
#line 2348 "src/parser.tab.cpp"
    break;

  case 105:
#line 309 "src/parser.y"
                                      {(yyval.expr) = new direct_declarator(3,(yyvsp[-2].expr));  std::cerr << "direct_declarator 3" << std::endl;}
#line 2354 "src/parser.tab.cpp"
    break;

  case 106:
#line 310 "src/parser.y"
                                                         {(yyval.expr) = new direct_declarator(4,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 4" << std::endl;}
#line 2360 "src/parser.tab.cpp"
    break;

  case 107:
#line 312 "src/parser.y"
                                      {(yyval.expr) = new direct_declarator(6,(yyvsp[-2].expr));  std::cerr << "direct_declarator 6" << std::endl;}
#line 2366 "src/parser.tab.cpp"
    break;

  case 108:
#line 315 "src/parser.y"
              {(yyval.expr) = new pointer(0); std::cerr << "pointer 0" << std::endl;}
#line 2372 "src/parser.tab.cpp"
    break;

  case 109:
#line 317 "src/parser.y"
                        {(yyval.expr) = new pointer(1, (yyvsp[0].expr)); std::cerr << "pointer 1" << std::endl;}
#line 2378 "src/parser.tab.cpp"
    break;

  case 110:
#line 328 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_type_list 0" << std::endl;}
#line 2384 "src/parser.tab.cpp"
    break;

  case 111:
#line 333 "src/parser.y"
                                                       {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_list 0" << std::endl; }
#line 2390 "src/parser.tab.cpp"
    break;

  case 112:
#line 334 "src/parser.y"
                                                       {(yyval.expr) = new parameter_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "parameter_list 1" << std::endl;}
#line 2396 "src/parser.tab.cpp"
    break;

  case 113:
#line 338 "src/parser.y"
                                                        {(yyval.expr) = new parameter_declaration(0, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 0" << std::endl; }
#line 2402 "src/parser.tab.cpp"
    break;

  case 114:
#line 339 "src/parser.y"
                                                        {(yyval.expr) = new parameter_declaration(1, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 1" << std::endl; }
#line 2408 "src/parser.tab.cpp"
    break;

  case 115:
#line 340 "src/parser.y"
                                                   {(yyval.expr) = new parameter_declaration(2, (yyvsp[0].expr)); std::cerr << "parameter_declaration 2" << std::endl;  }
#line 2414 "src/parser.tab.cpp"
    break;

  case 116:
#line 349 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr);std::cerr << "type name 1" << std::endl; }
#line 2420 "src/parser.tab.cpp"
    break;

  case 117:
#line 350 "src/parser.y"
                                                         {(yyval.expr) = new type_name((yyvsp[-1].expr), (yyvsp[0].expr));std::cerr << "type name 2" << std::endl;}
#line 2426 "src/parser.tab.cpp"
    break;

  case 118:
#line 354 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "abstract_declarator 0" << std::endl;}
#line 2432 "src/parser.tab.cpp"
    break;

  case 119:
#line 355 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr); std::cerr << "abstract_declarator 1" << std::endl;}
#line 2438 "src/parser.tab.cpp"
    break;

  case 120:
#line 356 "src/parser.y"
                                                         {(yyval.expr) = new abstract_declarator((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "abstract_declarator 2" << std::endl;}
#line 2444 "src/parser.tab.cpp"
    break;

  case 121:
#line 361 "src/parser.y"
                                                                     {(yyval.expr) = (yyvsp[-1].expr);  std::cerr << "direct_abstract_declarator 0" << std::endl;}
#line 2450 "src/parser.tab.cpp"
    break;

  case 122:
#line 362 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(0);  std::cerr << "direct_abstract_declarator 1" << std::endl;}
#line 2456 "src/parser.tab.cpp"
    break;

  case 123:
#line 363 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(1, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 2" << std::endl;}
#line 2462 "src/parser.tab.cpp"
    break;

  case 124:
#line 364 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(2, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 3" << std::endl;}
#line 2468 "src/parser.tab.cpp"
    break;

  case 125:
#line 365 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(3, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 4" << std::endl;}
#line 2474 "src/parser.tab.cpp"
    break;

  case 126:
#line 366 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(4);  std::cerr << "direct_abstract_declarator 5" << std::endl;}
#line 2480 "src/parser.tab.cpp"
    break;

  case 127:
#line 367 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(5, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 6" << std::endl;}
#line 2486 "src/parser.tab.cpp"
    break;

  case 128:
#line 368 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(6, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 7" << std::endl;}
#line 2492 "src/parser.tab.cpp"
    break;

  case 129:
#line 369 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(7, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 8" << std::endl;}
#line 2498 "src/parser.tab.cpp"
    break;

  case 130:
#line 373 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "initializer 0" << std::endl;}
#line 2504 "src/parser.tab.cpp"
    break;

  case 131:
#line 374 "src/parser.y"
                                                 {(yyval.expr) = new initializer(0, (yyvsp[-1].expr)); std::cerr << "initializer 1" << std::endl;}
#line 2510 "src/parser.tab.cpp"
    break;

  case 132:
#line 375 "src/parser.y"
                                                 {(yyval.expr) = new initializer(1, (yyvsp[-2].expr)); std::cerr << "initializer 2" << std::endl;}
#line 2516 "src/parser.tab.cpp"
    break;

  case 133:
#line 379 "src/parser.y"
                                                 {(yyval.expr) = new initializer_list(0, (yyvsp[0].expr)); std::cerr << "initializer_list 0" << std::endl;}
#line 2522 "src/parser.tab.cpp"
    break;

  case 134:
#line 380 "src/parser.y"
                                                 {(yyval.expr) = new initializer_list(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "initializer_list 1" << std::endl;}
#line 2528 "src/parser.tab.cpp"
    break;

  case 135:
#line 384 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 0" << std::endl;}
#line 2534 "src/parser.tab.cpp"
    break;

  case 136:
#line 385 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 1" << std::endl; }
#line 2540 "src/parser.tab.cpp"
    break;

  case 137:
#line 386 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 2" << std::endl;}
#line 2546 "src/parser.tab.cpp"
    break;

  case 138:
#line 387 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 3" << std::endl;}
#line 2552 "src/parser.tab.cpp"
    break;

  case 139:
#line 388 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 4" << std::endl;}
#line 2558 "src/parser.tab.cpp"
    break;

  case 140:
#line 389 "src/parser.y"
                         {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 5" << std::endl;}
#line 2564 "src/parser.tab.cpp"
    break;

  case 141:
#line 393 "src/parser.y"
                                     {(yyval.expr) = new labeled_statement(0, (yyvsp[0].expr)); std::cerr << "labeled_statement 0" << std::endl;}
#line 2570 "src/parser.tab.cpp"
    break;

  case 142:
#line 394 "src/parser.y"
                                                   {(yyval.expr) = new labeled_statement(1, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "labeled_statement 1" << std::endl;}
#line 2576 "src/parser.tab.cpp"
    break;

  case 143:
#line 395 "src/parser.y"
                                   {(yyval.expr) = new labeled_statement(2, (yyvsp[0].expr)); std::cerr << "labeled_statement 2" << std::endl;}
#line 2582 "src/parser.tab.cpp"
    break;

  case 144:
#line 399 "src/parser.y"
                     {(yyval.expr) = new compound_statement(0); std::cerr << "compound_statement 0" << std::endl;}
#line 2588 "src/parser.tab.cpp"
    break;

  case 145:
#line 400 "src/parser.y"
                                   {(yyval.expr) = new compound_statement(1, (yyvsp[-1].expr)); std::cerr << "compound_statement 1" << std::endl;}
#line 2594 "src/parser.tab.cpp"
    break;

  case 146:
#line 401 "src/parser.y"
                                     {(yyval.expr) = new compound_statement(2, (yyvsp[-1].expr)); std::cerr << "compound_statement 2" << std::endl;}
#line 2600 "src/parser.tab.cpp"
    break;

  case 147:
#line 402 "src/parser.y"
                                                     {(yyval.expr) = new compound_statement(3, (yyvsp[-2].expr), (yyvsp[-1].expr)); std::cerr << "compound_statement 3" << std::endl;}
#line 2606 "src/parser.tab.cpp"
    break;

  case 148:
#line 406 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "declaration list 1" << std::endl;}
#line 2612 "src/parser.tab.cpp"
    break;

  case 149:
#line 407 "src/parser.y"
                                           {(yyval.expr) = new declaration_list((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "declaration list 2" << std::endl;}
#line 2618 "src/parser.tab.cpp"
    break;

  case 150:
#line 411 "src/parser.y"
                       {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement_list 0" << std::endl;}
#line 2624 "src/parser.tab.cpp"
    break;

  case 151:
#line 412 "src/parser.y"
                                     {(yyval.expr) = new statement_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "statement_list 1" << std::endl;}
#line 2630 "src/parser.tab.cpp"
    break;

  case 152:
#line 416 "src/parser.y"
                 {(yyval.expr) = new expression_statement(0);std::cerr << "expression_statement 0" << std::endl;}
#line 2636 "src/parser.tab.cpp"
    break;

  case 153:
#line 417 "src/parser.y"
                           {(yyval.expr) = new expression_statement((yyvsp[-1].expr));std::cerr << "expression_statement 1" << std::endl;}
#line 2642 "src/parser.tab.cpp"
    break;

  case 154:
#line 421 "src/parser.y"
                                             {(yyval.expr) = new selection_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 0" << std::endl;}
#line 2648 "src/parser.tab.cpp"
    break;

  case 155:
#line 422 "src/parser.y"
                                                           {(yyval.expr) = new selection_statement(1, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 1" << std::endl;}
#line 2654 "src/parser.tab.cpp"
    break;

  case 156:
#line 423 "src/parser.y"
                                                 {(yyval.expr) = new selection_statement(2, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 2" << std::endl;}
#line 2660 "src/parser.tab.cpp"
    break;

  case 157:
#line 427 "src/parser.y"
                                               {(yyval.expr) = new iteration_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "iteration_statement 0 " << std::endl;}
#line 2666 "src/parser.tab.cpp"
    break;

  case 158:
#line 428 "src/parser.y"
                                                       {(yyval.expr) = new iteration_statement(1, (yyvsp[-5].expr), (yyvsp[-2].expr));std::cerr << "iteration_statement 1 " << std::endl;}
#line 2672 "src/parser.tab.cpp"
    break;

  case 159:
#line 429 "src/parser.y"
                                                                             {(yyval.expr) = new iteration_statement(2, (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 2 " << std::endl;}
#line 2678 "src/parser.tab.cpp"
    break;

  case 160:
#line 430 "src/parser.y"
                                                                                       {(yyval.expr) = new iteration_statement(0, (yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 3 " << std::endl;}
#line 2684 "src/parser.tab.cpp"
    break;

  case 161:
#line 435 "src/parser.y"
                         {(yyval.expr) = new jump_statement(1, "CONTINUE");std::cerr << "jump_statement 1 " << std::endl;}
#line 2690 "src/parser.tab.cpp"
    break;

  case 162:
#line 436 "src/parser.y"
                       {(yyval.expr) = new jump_statement(2, "BREAK");std::cerr << "jump_statement 2 " << std::endl;}
#line 2696 "src/parser.tab.cpp"
    break;

  case 163:
#line 437 "src/parser.y"
                       {(yyval.expr) = new jump_statement(3, "RETURN");std::cerr << "jump_statement 3 " << std::endl;}
#line 2702 "src/parser.tab.cpp"
    break;

  case 164:
#line 438 "src/parser.y"
                                   {(yyval.expr) = new jump_statement(4, (yyvsp[-1].expr));std::cerr << "jump_statement 4 " << std::endl;}
#line 2708 "src/parser.tab.cpp"
    break;

  case 165:
#line 443 "src/parser.y"
                                                   {(yyval.expr) = (yyvsp[0].expr);std::cerr << " translation_unit 1" << std::endl;}
#line 2714 "src/parser.tab.cpp"
    break;

  case 166:
#line 444 "src/parser.y"
                                                   {std::cerr << "translation_unit 2" << std::endl;(yyval.expr) = new translation_unit((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2720 "src/parser.tab.cpp"
    break;

  case 167:
#line 448 "src/parser.y"
                        {g_root = (yyvsp[0].expr);}
#line 2726 "src/parser.tab.cpp"
    break;

  case 168:
#line 451 "src/parser.y"
                                     {(yyval.expr) = new external_declaration(0,(yyvsp[0].expr));std::cerr << "external declaration 1" << std::endl;}
#line 2732 "src/parser.tab.cpp"
    break;

  case 169:
#line 452 "src/parser.y"
                                     {(yyval.expr) =  new external_declaration(1,(yyvsp[0].expr));std::cerr << "external declaration 2" << std::endl;}
#line 2738 "src/parser.tab.cpp"
    break;

  case 170:
#line 457 "src/parser.y"
                                                                                 {std::cerr << "function definition 1" << std::endl;(yyval.expr) = new function_definition((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2744 "src/parser.tab.cpp"
    break;

  case 171:
#line 458 "src/parser.y"
                                                                           {std::cerr << "function definition 2" << std::endl;(yyval.expr) = new function_definition((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2750 "src/parser.tab.cpp"
    break;


#line 2754 "src/parser.tab.cpp"

=======
        case 2:
#line 55 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(0,*(yyvsp[0].str)); std::cerr << "primary expression 1, which is IDENTIFIER : " <<  *(yyvsp[0].str) << std::endl;}
#line 1643 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(1,*(yyvsp[0].str)); std::cerr << "primary expression 2, which is const with value: " << *(yyvsp[0].str) <<std::endl;}
#line 1649 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(2,*(yyvsp[0].str)); std::cerr << "primary expression 3,  which is string literal "<< std::endl;}
#line 1655 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(3,(yyvsp[-1].expr)); std::cerr << "primary expression 4" << std::endl;}
#line 1661 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "postfix expression 1" << std::endl;}
#line 1667 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 63 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new postfix_expression(0, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 2" << std::endl;}
#line 1673 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new postfix_expression(1, (yyvsp[-2].expr));std::cerr << "postfix expression 3" << std::endl;}
#line 1679 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new postfix_expression(2, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 4" << std::endl;}
#line 1685 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new postfix_expression(3, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 5" << std::endl;}
#line 1691 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new postfix_expression(4, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 6" << std::endl;}
#line 1697 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new postfix_expression(5, (yyvsp[-1].expr));std::cerr << "postfix expression 7" << std::endl;}
#line 1703 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 69 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new postfix_expression(6, (yyvsp[-1].expr));std::cerr << "postfix expression 8" << std::endl;}
#line 1709 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 73 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new argument_expression_list((yyvsp[0].expr)); std::cerr << "argument expression 1" << std::endl;}
#line 1715 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new argument_expression_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "argument expression 2" << std::endl;}
#line 1721 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 78 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "unary expression 1" << std::endl;}
#line 1727 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 79 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(0, (yyvsp[0].expr)); std::cerr << "unary expression 2" << std::endl;}
#line 1733 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 80 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(1, (yyvsp[0].expr)); std::cerr << "unary expression 3" << std::endl;}
#line 1739 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 81 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression((yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "unary expression 4" << std::endl;}
#line 1745 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 82 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(2, (yyvsp[0].expr)); std::cerr << "unary expression 5" << std::endl;}
#line 1751 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 83 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(3, (yyvsp[-1].expr)); std::cerr << "unary expression 6" << std::endl;}
#line 1757 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 87 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 4; std::cerr << "unary operator 1" << std::endl;}
#line 1763 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 88 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 5; std::cerr << "unary operator 2" << std::endl;}
#line 1769 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 89 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 6; std::cerr << "unary operator 3" << std::endl;}
#line 1775 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 7; std::cerr << "unary operator 4" << std::endl;}
#line 1781 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 8; std::cerr << "unary operator 5" << std::endl;}
#line 1787 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 9; std::cerr << "unary operator 6" << std::endl;}
#line 1793 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 96 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "cast expression 1" << std::endl;}
#line 1799 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new cast_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "cast expression 2" << std::endl;}
#line 1805 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 101 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "mulitiplicative expression 1" << std::endl;}
#line 1811 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 102 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new multiplicative_expression(1,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 2" << std::endl;}
#line 1817 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 103 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new multiplicative_expression(2,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 3" << std::endl;}
#line 1823 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 104 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new multiplicative_expression(3,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 4" << std::endl;}
#line 1829 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 108 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "additive_expression 1" << std::endl;}
#line 1835 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 109 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new additive_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 2" << std::endl;}
#line 1841 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 110 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new additive_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 3" << std::endl;}
#line 1847 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 114 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "shift_expression 1" << std::endl;}
#line 1853 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 115 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new shift_expression(1,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 2" << std::endl;}
#line 1859 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 116 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new shift_expression(2,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 3" << std::endl;}
#line 1865 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 120 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "relational_expression 1" << std::endl;}
#line 1871 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 121 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 2" << std::endl;}
#line 1877 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 122 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 3" << std::endl;}
#line 1883 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 123 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 4" << std::endl;}
#line 1889 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 124 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(3, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 5" << std::endl;}
#line 1895 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 128 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "equality_expression 1" << std::endl;}
#line 1901 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 129 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(4, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 2" << std::endl;}
#line 1907 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 130 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(5, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 3" << std::endl;}
#line 1913 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 134 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "and_expression 1" << std::endl;}
#line 1919 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(6, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "and_expression 2" << std::endl;}
#line 1925 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 139 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "exclusive_or_expression 1" << std::endl;}
#line 1931 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 140 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(7, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "exclusive_or_expression 2" << std::endl;}
#line 1937 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 144 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "inclusive_or_expression 1" << std::endl;}
#line 1943 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 145 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(8, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "inclusive_or_expression 2" << std::endl;}
#line 1949 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 149 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_and_expression 1" << std::endl;}
#line 1955 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 150 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(9, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_and_expression 2" << std::endl;}
#line 1961 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 154 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_or_expression 1" << std::endl;}
#line 1967 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 155 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(10, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_or_expression 2" << std::endl;}
#line 1973 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "conditional expression 1" << std::endl;}
#line 1979 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 160 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new conditional_expression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "conditional expression 2" << std::endl;}
#line 1985 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 164 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new assignment_expression((yyvsp[0].expr)); std::cerr << "assignment expression 1" << std::endl;}
#line 1991 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 165 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new assignment_expression((yyvsp[-2].expr), (yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "assignment expression 2" << std::endl;}
#line 1997 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 169 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 0; std::cerr << "assignment operator 1" << std::endl;}
#line 2003 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 170 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 1; std::cerr << "assignment operator 2" << std::endl;}
#line 2009 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 171 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 2; std::cerr << "assignment operator 3" << std::endl;}
#line 2015 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 172 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 3; std::cerr << "assignment operator 4" << std::endl;}
#line 2021 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 173 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 4; std::cerr << "assignment operator 5" << std::endl;}
#line 2027 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 174 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 5; std::cerr << "assignment operator 6" << std::endl;}
#line 2033 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 175 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 6; std::cerr << "assignment operator 7" << std::endl;}
#line 2039 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 176 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 7; std::cerr << "assignment operator 8" << std::endl;}
#line 2045 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 177 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 8; std::cerr << "assignment operator 9" << std::endl;}
#line 2051 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 178 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 9; std::cerr << "assignment operator 10" << std::endl;}
#line 2057 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 179 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 10; std::cerr << "assignment operator 11" << std::endl;}
#line 2063 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 183 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "expression 1" << std::endl;}
#line 2069 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 184 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new base_expression((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "expression 2" << std::endl;}
#line 2075 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 188 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "constant_expression 0" << std::endl;}
#line 2081 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 192 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration((yyvsp[-1].expr)); std::cerr << "declaration 0 " << std::endl;}
#line 2087 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 193 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration((yyvsp[-2].expr), (yyvsp[-1].expr));std::cerr << "declaration 1 " << std::endl;}
#line 2093 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 197 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 0" << std::endl;}
#line 2099 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 198 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 1" << std::endl;}
#line 2105 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 199 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 2" << std::endl;}
#line 2111 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 200 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 3" << std::endl;}
#line 2117 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 206 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "init_declarator_list 0 " << std::endl;}
#line 2123 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 207 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new init_declarator_list((yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "init_declarator_list 1" << std::endl;}
#line 2129 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 211 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new init_declarator((yyvsp[0].expr)); std::cerr << "init_declarator 0 " << std::endl;}
#line 2135 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 212 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new init_declarator((yyvsp[-2].expr),(yyvsp[0].expr));  std::cerr << "init_declarator 1" << std::endl;}
#line 2141 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 216 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new storage_class_specifier(0); std::cerr << "storage_class_specifier typedef 0 " << std::endl;}
#line 2147 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 217 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new storage_class_specifier(1);  std::cerr << "storage_class_specifier typedef 1 " << std::endl;}
#line 2153 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 224 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(0); std::cerr << "type_specifier void" << std::endl;}
#line 2159 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 225 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(1); std::cerr << "type_specifier char" << std::endl;}
#line 2165 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 226 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(2); std::cerr << "type_specifier short" << std::endl;}
#line 2171 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 227 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(3); std::cerr << "type_specifier int" << std::endl;}
#line 2177 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 228 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(4); std::cerr << "type_specifier long 5" << std::endl;}
#line 2183 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(5); std::cerr << "type_specifier float 6" << std::endl;}
#line 2189 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 230 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(6); std::cerr << "type_specifier double 7" << std::endl;}
#line 2195 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 231 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(7); std::cerr << "type_specifier signed 8" << std::endl;}
#line 2201 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 232 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(8); std::cerr << "type_specifier signed unsigned 9" << std::endl;}
#line 2207 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 235 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(9); std::cerr << "type_name" << std::endl;}
#line 2213 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 260 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new specifier_qualifier_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "specifier_qualifier_list 0" << std::endl;}
#line 2219 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 261 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "specifier_qualifier_list 1" << std::endl;}
#line 2225 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 301 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declarator((yyvsp[-1].expr), (yyvsp[0].expr));  std::cerr << "declarator 0" << std::endl;}
#line 2231 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 302 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "declarator 1" << std::endl;}
#line 2237 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(0,*(yyvsp[0].str));std::cerr << "direct_declarator 0,IDENTIFIER : " << *(yyvsp[0].str) <<std::endl; }
#line 2243 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 307 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(1,(yyvsp[-1].expr)); std::cerr << "direct_declarator 1" << std::endl;}
#line 2249 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 308 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(2,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 2" << std::endl;}
#line 2255 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 309 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(3,(yyvsp[-2].expr));  std::cerr << "direct_declarator 3" << std::endl;}
#line 2261 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 310 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(4,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 4" << std::endl;}
#line 2267 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 312 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(6,(yyvsp[-2].expr));  std::cerr << "direct_declarator 6" << std::endl;}
#line 2273 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 315 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new pointer(0); std::cerr << "pointer 0" << std::endl;}
#line 2279 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 317 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new pointer(1, (yyvsp[0].expr)); std::cerr << "pointer 1" << std::endl;}
#line 2285 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 328 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_type_list 0" << std::endl;}
#line 2291 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 333 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_list 0" << std::endl; }
#line 2297 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 334 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "parameter_list 1" << std::endl;}
#line 2303 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 338 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_declaration(0, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 0" << std::endl; }
#line 2309 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 339 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_declaration(1, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 1" << std::endl; }
#line 2315 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 340 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_declaration(2, (yyvsp[0].expr)); std::cerr << "parameter_declaration 2" << std::endl;  }
#line 2321 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 349 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);std::cerr << "type name 1" << std::endl; }
#line 2327 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 350 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_name((yyvsp[-1].expr), (yyvsp[0].expr));std::cerr << "type name 2" << std::endl;}
#line 2333 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 354 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "abstract_declarator 0" << std::endl;}
#line 2339 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 355 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "abstract_declarator 1" << std::endl;}
#line 2345 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 356 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new abstract_declarator((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "abstract_declarator 2" << std::endl;}
#line 2351 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 361 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[-1].expr);  std::cerr << "direct_abstract_declarator 0" << std::endl;}
#line 2357 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 362 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(0);  std::cerr << "direct_abstract_declarator 1" << std::endl;}
#line 2363 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 363 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(1, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 2" << std::endl;}
#line 2369 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 364 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(2, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 3" << std::endl;}
#line 2375 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 365 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(3, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 4" << std::endl;}
#line 2381 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 366 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(4);  std::cerr << "direct_abstract_declarator 5" << std::endl;}
#line 2387 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 367 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(5, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 6" << std::endl;}
#line 2393 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 368 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(6, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 7" << std::endl;}
#line 2399 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 369 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(7, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 8" << std::endl;}
#line 2405 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 373 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "initializer 0" << std::endl;}
#line 2411 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 374 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer(0, (yyvsp[-1].expr)); std::cerr << "initializer 1" << std::endl;}
#line 2417 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 375 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer(1, (yyvsp[-2].expr)); std::cerr << "initializer 2" << std::endl;}
#line 2423 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 379 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer_list(0, (yyvsp[0].expr)); std::cerr << "initializer_list 0" << std::endl;}
#line 2429 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 380 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer_list(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "initializer_list 1" << std::endl;}
#line 2435 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 384 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 0" << std::endl;}
#line 2441 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 385 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 1" << std::endl; }
#line 2447 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 386 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 2" << std::endl;}
#line 2453 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 387 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 3" << std::endl;}
#line 2459 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 388 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 4" << std::endl;}
#line 2465 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 389 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 5" << std::endl;}
#line 2471 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 393 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new labeled_statement(0, (yyvsp[0].expr)); std::cerr << "labeled_statement 0" << std::endl;}
#line 2477 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 394 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new labeled_statement(1, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "labeled_statement 1" << std::endl;}
#line 2483 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 395 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new labeled_statement(2, (yyvsp[0].expr)); std::cerr << "labeled_statement 2" << std::endl;}
#line 2489 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 399 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(0); std::cerr << "compound_statement 0" << std::endl;}
#line 2495 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 400 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(1, (yyvsp[-1].expr)); std::cerr << "compound_statement 1" << std::endl;}
#line 2501 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 401 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(2, (yyvsp[-1].expr)); std::cerr << "compound_statement 2" << std::endl;}
#line 2507 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 402 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(3, (yyvsp[-2].expr), (yyvsp[-1].expr)); std::cerr << "compound_statement 3" << std::endl;}
#line 2513 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 406 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "declaration list 1" << std::endl;}
#line 2519 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 407 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration_list((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "declaration list 2" << std::endl;}
#line 2525 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 411 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement_list 0" << std::endl;}
#line 2531 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 412 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new statement_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "statement_list 1" << std::endl;}
#line 2537 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 416 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new expression_statement(0);std::cerr << "expression_statement 0" << std::endl;}
#line 2543 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 417 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new expression_statement((yyvsp[-1].expr));std::cerr << "expression_statement 1" << std::endl;}
#line 2549 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 421 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new selection_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 0" << std::endl;}
#line 2555 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 422 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new selection_statement(1, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 1" << std::endl;}
#line 2561 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 423 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new selection_statement(2, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 2" << std::endl;}
#line 2567 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 427 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "iteration_statement 0 " << std::endl;}
#line 2573 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 428 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(1, (yyvsp[-5].expr), (yyvsp[-2].expr));std::cerr << "iteration_statement 1 " << std::endl;}
#line 2579 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 429 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(2, (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 2 " << std::endl;}
#line 2585 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 430 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(0, (yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 3 " << std::endl;}
#line 2591 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 435 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(1, "CONTINUE");std::cerr << "jump_statement 1 " << std::endl;}
#line 2597 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 436 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(2, "BREAK");std::cerr << "jump_statement 2 " << std::endl;}
#line 2603 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 437 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(3, "RETURN");std::cerr << "jump_statement 3 " << std::endl;}
#line 2609 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 438 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(4, (yyvsp[-1].expr));std::cerr << "jump_statement 4 " << std::endl;}
#line 2615 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 443 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);std::cerr << " translation_unit 1" << std::endl;}
#line 2621 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 444 "src/parser.y" /* yacc.c:1646  */
    {std::cerr << "translation_unit 2" << std::endl;(yyval.expr) = new translation_unit((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2627 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 448 "src/parser.y" /* yacc.c:1646  */
    {g_root = (yyvsp[0].expr);}
#line 2633 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 451 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new external_declaration(0,(yyvsp[0].expr));std::cerr << "external declaration 1" << std::endl;}
#line 2639 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 452 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) =  new external_declaration(1,(yyvsp[0].expr));std::cerr << "external declaration 2" << std::endl;}
#line 2645 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 457 "src/parser.y" /* yacc.c:1646  */
    {std::cerr << "function definition 1" << std::endl;(yyval.expr) = new function_definition((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2651 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 458 "src/parser.y" /* yacc.c:1646  */
    {std::cerr << "function definition 2" << std::endl;(yyval.expr) = new function_definition((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2657 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2661 "src/parser.tab.cpp" /* yacc.c:1646  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }
=======

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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
<<<<<<< HEAD
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
=======
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
=======

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

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

<<<<<<< HEAD

=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

<<<<<<< HEAD

=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

<<<<<<< HEAD

/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
=======
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
                  yystos[+*yyssp], yyvsp);
=======
                  yystos[*yyssp], yyvsp);
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47
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
<<<<<<< HEAD
#line 462 "src/parser.y"
=======
#line 462 "src/parser.y" /* yacc.c:1906  */
>>>>>>> 164926091fc102c411f88cb32c24f0e26fb6da47

/* #include <stdio.h>
#include <string>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
} */

const astnode * g_root;
 /* const astnode* parseAST(char* filename)
{
    yyin = fopen(filename, "r");
    g_root= NULL;
    yyparse();
   return g_root;
} */


 const astnode* parseAST(void){
  //std::cerr << "parseast" << std::endl;
  g_root= 0;
  yyparse();
  return g_root;
}
