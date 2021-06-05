
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TCONST	258
#define	TELSE	259
#define	TIF	260
#define	TINT	261
#define	TRETURN	262
#define	TVOID	263
#define	TWHILE	264
#define	TPOINT	265
#define	TILLSP	266
#define	TPLUS	267
#define	TMINUS	268
#define	TSTAR	269
#define	TSLASH	270
#define	TMOD	271
#define	TASSIGN	272
#define	TADDASSIGN	273
#define	TSUBASSIGN	274
#define	TMULASSIGN	275
#define	TDIVASSIGN	276
#define	TMODASSIGN	277
#define	TOR	278
#define	TEQUAL	279
#define	TNOTEQU	280
#define	TLESS	281
#define	TOVER	282
#define	TLESSE	283
#define	TINC	284
#define	TDEC	285
#define	TOSBRA	286
#define	TCSBRA	287
#define	TCOMMA	288
#define	TOMBRA	289
#define	TCMBRA	290
#define	TOLBRA	291
#define	TCLBRA	292
#define	TSEMI	293
#define	TNUMBER	294
#define	TFLOAT	295
#define	TLONG	296
#define	TNOT	297
#define	TAND	298
#define	TOVERE	299
#define	TILLIDENT	300
#define	TONECMT	301
#define	TMULCMT	302
#define	TIDENT	303
#define	TSTRING	304
#define	TCHAR	305
#define	TCHARVAR	306
#define	TSTRINGVAR	307
#define	LOWER_THAN_ELSE	308

#line 1 "parser.y"

/*
* parser.y.- yacc source for the MiniC(HW3)
*
* Programmer - team2
*
* 1871040이유정 / 1871026 신인류 / 1876136 박가현
*
* date -  6/05/2021
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"
 int type_int=0;
 int type_void=0;
 int type_float=0;
 
 int type_char=0;
 int type_string=0;
 int param_int=0;
 int param_float=0;
 int param_char=0;
 int param_string=0;
 char scope[100]="\0";
extern reporterror();
extern yylex();
extern char *yytext;
extern yyerror(char *s);
extern append(char *dst, char c);

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		201
#define	YYFLAG		-32768
#define	YYNTBASE	54

#define YYTRANSLATE(x) ((unsigned)(x) <= 308 ? yytranslate[x] : 99)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    51,    53,    55,    57,    59,    63,    65,    66,    68,
    72,    76,    79,    84,    89,    91,    92,    94,    97,   101,
   105,   107,   111,   115,   117,   121,   125,   129,   133,   135,
   140,   145,   147,   149,   151,   153,   154,   156,   157,   159,
   162,   165,   167,   169,   171,   173,   175,   178,   181,   183,
   184,   190,   198,   204,   208,   210,   212,   216,   220,   224,
   228,   232,   236,   240,   244,   248,   252,   256,   260,   262,
   266,   270,   272,   276,   280,   282,   286,   290,   294,   298,
   300,   304,   308,   312,   316,   320,   324,   328,   332,   334,
   338,   342,   346,   350,   352,   356,   360,   364,   368,   372,
   376,   378,   381,   384,   387,   390,   392,   397,   402,   405,
   408,   410,   411,   413,   415,   419,   421,   423,   425,   429,
   431
};

static const short yyrhs[] = {    55,
     0,    56,     0,    55,    56,     0,    57,     0,    72,     0,
    48,    38,     0,    48,     1,     0,    58,    69,     0,    58,
    38,     0,    58,     1,     0,    59,    64,    65,     0,    60,
     0,    61,     0,    60,    61,     0,    62,     0,    63,     0,
     3,     0,     6,     0,     8,     0,    40,     0,    50,     0,
    49,     0,    48,     0,    45,     0,    41,     0,    31,    66,
    32,     0,    67,     0,     0,    68,     0,    67,    33,    68,
     0,    67,    68,     1,     0,    59,    75,     0,    34,    70,
    77,    35,     0,    34,    70,    77,     1,     0,    71,     0,
     0,    72,     0,    71,    72,     0,    59,    73,    38,     0,
    59,    73,     1,     0,    74,     0,    73,    33,    74,     0,
    73,    74,     1,     0,    75,     0,    75,    17,    39,     0,
    75,    17,    10,     0,    75,    17,    51,     0,    75,    17,
    52,     0,    48,     0,    48,    36,    76,    37,     0,    48,
    36,    76,     1,     0,    45,     0,    41,     0,    39,     0,
    10,     0,     0,    78,     0,     0,    79,     0,    78,    79,
     0,    78,    72,     0,    69,     0,    80,     0,    82,     0,
    83,     0,    84,     0,    81,    38,     0,    85,     1,     0,
    85,     0,     0,     5,    31,    85,    32,    79,     0,     5,
    31,    85,    32,    79,     4,    79,     0,     9,    31,    85,
    32,    79,     0,     7,    81,    38,     0,    86,     0,    87,
     0,    93,    17,    86,     0,    93,    18,    86,     0,    93,
    19,    86,     0,    93,    20,    86,     0,    93,    21,    86,
     0,    93,    22,    86,     0,    93,    17,     1,     0,    93,
    18,     1,     0,    93,    19,     1,     0,    93,    20,     1,
     0,    93,    21,     1,     0,    93,    22,     1,     0,    88,
     0,    87,    23,    88,     0,    87,    23,     1,     0,    89,
     0,    88,    43,    89,     0,    88,    43,     1,     0,    90,
     0,    89,    24,    90,     0,    89,    25,    90,     0,    89,
    24,     1,     0,    89,    25,     1,     0,    91,     0,    90,
    27,    91,     0,    90,    44,    91,     0,    90,    26,    91,
     0,    90,    28,    91,     0,    90,    27,     1,     0,    90,
    26,     1,     0,    90,    44,     1,     0,    90,    28,     1,
     0,    92,     0,    91,    12,    92,     0,    91,    12,     1,
     0,    91,    13,    92,     0,    91,    13,     1,     0,    93,
     0,    92,    14,    93,     0,    92,    15,    93,     0,    92,
    16,    93,     0,    92,    14,     1,     0,    92,    15,     1,
     0,    92,    16,     1,     0,    94,     0,    13,    93,     0,
    42,    93,     0,    29,    93,     0,    30,    93,     0,    98,
     0,    94,    36,    85,    37,     0,    94,    31,    95,    32,
     0,    94,    29,     0,    94,    30,     0,    96,     0,     0,
    97,     0,    86,     0,    97,    33,    86,     0,    48,     0,
    39,     0,    10,     0,    31,    85,    32,     0,    51,     0,
    52,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    43,    45,    46,    49,    50,    51,    52,    57,    58,    59,
    67,    69,    71,    72,    74,    75,    77,    80,    81,    82,
    83,    84,    87,   116,   117,   120,   122,   123,   125,   126,
   127,   135,   166,   167,   173,   174,   176,   177,   179,   186,
   197,   198,   199,   204,   205,   206,   207,   208,   210,   236,
   245,   249,   250,   252,   253,   254,   256,   257,   259,   260,
   261,   263,   264,   265,   266,   267,   269,   270,   276,   277,
   279,   280,   282,   284,   286,   288,   289,   290,   291,   292,
   293,   294,   295,   299,   303,   307,   311,   315,   320,   321,
   322,   327,   328,   329,   334,   335,   336,   337,   341,   346,
   347,   348,   349,   350,   351,   356,   360,   364,   369,   370,
   371,   375,   376,   380,   381,   382,   383,   384,   388,   393,
   399,   400,   401,   402,   403,   405,   406,   407,   408,   409,
   411,   412,   414,   416,   417,   420,   425,   426,   427,   428,
   429
};

static const char * const yytname[] = {   "$","error","$undefined.","TCONST",
"TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TPOINT","TILLSP","TPLUS","TMINUS",
"TSTAR","TSLASH","TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN",
"TMODASSIGN","TOR","TEQUAL","TNOTEQU","TLESS","TOVER","TLESSE","TINC","TDEC",
"TOSBRA","TCSBRA","TCOMMA","TOMBRA","TCMBRA","TOLBRA","TCLBRA","TSEMI","TNUMBER",
"TFLOAT","TLONG","TNOT","TAND","TOVERE","TILLIDENT","TONECMT","TMULCMT","TIDENT",
"TSTRING","TCHAR","TCHARVAR","TSTRINGVAR","LOWER_THAN_ELSE","mini_c","translation_unit",
"external_dcl","function_def","function_header","dcl_spec","dcl_specifiers",
"dcl_specifier","type_qualifier","type_specifier","function_name","formal_param",
"opt_formal_param","formal_param_list","param_dcl","compound_st","opt_dcl_list",
"declaration_list","declaration","init_dcl_list","init_declarator","declarator",
"opt_number","opt_stat_list","statement_list","statement","expression_st","opt_expression",
"if_st","while_st","return_st","expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","additive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    54,    55,    55,    56,    56,    56,    56,    57,    57,    57,
    58,    59,    60,    60,    61,    61,    62,    63,    63,    63,
    63,    63,    64,    64,    64,    65,    66,    66,    67,    67,
    67,    68,    69,    69,    70,    70,    71,    71,    72,    72,
    73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
    75,    75,    75,    76,    76,    76,    77,    77,    78,    78,
    78,    79,    79,    79,    79,    79,    80,    80,    81,    81,
    82,    82,    83,    84,    85,    86,    86,    86,    86,    86,
    86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
    87,    88,    88,    88,    89,    89,    89,    89,    89,    90,
    90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
    91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
    93,    93,    93,    93,    93,    94,    94,    94,    94,    94,
    95,    95,    96,    97,    97,    98,    98,    98,    98,    98,
    98
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     3,     1,     0,     1,     3,
     3,     2,     4,     4,     1,     0,     1,     2,     3,     3,
     1,     3,     3,     1,     3,     3,     3,     3,     1,     4,
     4,     1,     1,     1,     1,     0,     1,     0,     1,     2,
     2,     1,     1,     1,     1,     1,     2,     2,     1,     0,
     5,     7,     5,     3,     1,     1,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
     3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
     3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
     1,     2,     2,     2,     2,     1,     4,     4,     2,     2,
     1,     0,     1,     1,     3,     1,     1,     1,     3,     1,
     1
};

static const short yydefact[] = {     0,
    17,    18,    19,    20,     0,    22,    21,     1,     2,     4,
     0,     0,    12,    13,    15,    16,     5,     7,     6,     3,
    10,    36,     9,     8,    53,    52,    49,     0,     0,    41,
    44,    14,     0,    58,    35,    37,    56,    28,    11,    40,
     0,    39,    53,    52,    49,     0,     0,     0,    70,     0,
   138,     0,     0,     0,     0,   137,     0,   136,   140,   141,
    62,     0,    57,    59,    63,     0,    64,    65,    66,     0,
    75,    76,    89,    92,    95,   100,   109,   114,   121,   126,
    38,    55,    54,     0,     0,     0,    27,    29,    42,    43,
    46,    45,    47,    48,     0,     0,    69,     0,   122,   124,
   125,     0,   123,    34,    33,    61,    60,    67,    68,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
   132,     0,    51,    50,    32,    26,     0,     0,     0,    74,
     0,   139,    91,    90,   114,    94,    93,    98,    96,    99,
    97,   106,   103,   105,   101,   108,   104,   107,   102,   111,
   110,   113,   112,   118,   115,   119,   116,   120,   117,    83,
    77,    84,    78,    85,    79,    86,    80,    87,    81,    88,
    82,   134,     0,   131,   133,     0,    30,    31,    70,    70,
   128,     0,   127,    71,    73,   135,    70,    72,     0,     0,
     0
};

static const short yydefgoto[] = {   199,
     8,     9,    10,    11,    33,    13,    14,    15,    16,    28,
    39,    86,    87,    88,    61,    34,    35,    17,    29,    30,
    31,    84,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
   183,   184,   185,    80
};

static const short yypact[] = {    50,
-32768,-32768,-32768,-32768,    21,-32768,-32768,    50,-32768,-32768,
    17,   -11,    54,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    54,-32768,-32768,    -4,     1,   -10,    19,    44,-32768,
    12,-32768,    65,   581,    54,-32768,     7,    54,-32768,-32768,
    65,-32768,-32768,-32768,    76,    47,    -8,    70,   611,    84,
-32768,   611,   611,   611,   611,-32768,   611,-32768,-32768,-32768,
-32768,    46,   533,-32768,-32768,    87,-32768,-32768,-32768,    38,
-32768,   109,    96,    11,    -3,    71,    81,   228,   172,-32768,
-32768,-32768,-32768,    41,    65,   110,   108,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   611,   111,-32768,   611,-32768,-32768,
-32768,   119,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    78,
    92,   123,   137,   168,   182,   213,   227,   258,   272,   303,
   317,   348,   362,   393,   407,   438,   452,   483,-32768,-32768,
   611,   611,-32768,-32768,-32768,-32768,    54,   154,   124,-32768,
   127,-32768,-32768,    96,-32768,-32768,    11,-32768,    -3,-32768,
    -3,-32768,    71,-32768,    71,-32768,    71,-32768,    71,-32768,
    81,-32768,    81,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   128,-32768,   130,   133,-32768,-32768,   596,   596,
-32768,   611,-32768,   157,-32768,-32768,   596,-32768,   164,   173,
-32768
};

static const short yypgoto[] = {-32768,
-32768,   169,-32768,-32768,     0,-32768,   159,-32768,-32768,-32768,
-32768,-32768,-32768,   -83,   171,-32768,-32768,    -2,-32768,    -1,
    95,-32768,-32768,-32768,   -62,-32768,   135,-32768,-32768,-32768,
   -46,  -112,-32768,    77,    75,     6,   176,    27,   -47,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		663


static const short yytable[] = {    12,
   107,    91,    97,   138,    99,   100,   101,    12,   102,   103,
   171,   173,   175,   177,   179,   181,    82,    21,   182,    36,
   -23,    18,   114,   115,   116,    37,   -25,    46,    47,    25,
    92,   -24,    81,    26,   112,   113,    27,    85,   109,    89,
   117,   133,    93,    94,    40,    83,   104,    90,   139,    38,
    22,   141,     1,   187,    23,     2,     1,     3,    19,     2,
   106,     3,   145,   145,   145,   145,   145,   145,   145,   145,
   145,   145,   165,   167,   169,   -69,    41,   134,   143,   196,
   105,    42,   118,   119,    43,   186,    85,    51,    44,     4,
    52,    45,   146,     4,   120,   121,   122,     5,     6,     7,
    95,    51,     6,     7,    52,    43,    53,    54,    55,    44,
     1,    37,    45,     2,    98,     3,    56,   149,   151,    57,
    53,    54,    55,   148,   108,    58,   194,   195,    59,    60,
    56,   110,    51,    57,   198,    52,    85,   150,   111,    58,
   137,   136,    59,    60,   161,   163,    51,     4,   140,    52,
   142,    53,    54,    55,   188,   189,     6,     7,   190,   191,
   197,    56,   192,   200,    57,    53,    54,    55,   152,   193,
    58,    32,   201,    59,    60,    56,    20,    51,    57,   135,
    52,    24,   154,    96,    58,   147,   144,    59,    60,     0,
     0,    51,     0,     0,    52,     0,    53,    54,    55,     0,
   129,   130,   131,     0,     0,     0,    56,   132,     0,    57,
    53,    54,    55,   156,     0,    58,     0,     0,    59,    60,
    56,     0,    51,    57,     0,    52,     0,   158,     0,    58,
     0,     0,    59,    60,     0,     0,    51,     0,     0,    52,
     0,    53,    54,    55,   123,   124,   125,   126,   127,   128,
     0,    56,     0,     0,    57,    53,    54,    55,   160,     0,
    58,     0,     0,    59,    60,    56,     0,    51,    57,     0,
    52,     0,   162,     0,    58,     0,     0,    59,    60,     0,
     0,    51,     0,     0,    52,     0,    53,    54,    55,   153,
   155,   157,   159,     0,     0,     0,    56,     0,     0,    57,
    53,    54,    55,   164,     0,    58,     0,     0,    59,    60,
    56,     0,    51,    57,     0,    52,     0,   166,     0,    58,
     0,     0,    59,    60,     0,     0,    51,     0,     0,    52,
     0,    53,    54,    55,     0,     0,     0,     0,     0,     0,
     0,    56,     0,     0,    57,    53,    54,    55,   168,     0,
    58,     0,     0,    59,    60,    56,     0,    51,    57,     0,
    52,     0,   170,     0,    58,     0,     0,    59,    60,     0,
     0,    51,     0,     0,    52,     0,    53,    54,    55,     0,
     0,     0,     0,     0,     0,     0,    56,     0,     0,    57,
    53,    54,    55,   172,     0,    58,     0,     0,    59,    60,
    56,     0,    51,    57,     0,    52,     0,   174,     0,    58,
     0,     0,    59,    60,     0,     0,    51,     0,     0,    52,
     0,    53,    54,    55,     0,     0,     0,     0,     0,     0,
     0,    56,     0,     0,    57,    53,    54,    55,   176,     0,
    58,     0,     0,    59,    60,    56,     0,    51,    57,     0,
    52,     0,   178,     0,    58,     0,     0,    59,    60,     0,
     0,    51,     0,     0,    52,     0,    53,    54,    55,     0,
     0,     0,     0,     0,     0,     0,    56,     0,     0,    57,
    53,    54,    55,   180,     0,    58,     0,     0,    59,    60,
    56,     0,    51,    57,     0,    52,     0,     0,     0,    58,
     0,     0,    59,    60,     0,     0,     0,     0,     0,     0,
     0,    53,    54,    55,     0,     0,     0,     0,     0,     0,
     0,    56,     0,     0,    57,     0,     0,     0,     0,     0,
    58,     0,     0,    59,    60,     1,     0,    48,     2,    49,
     3,    50,    51,     0,     0,    52,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    53,    54,    55,     0,     0,    22,     0,     0,     0,
   -70,    56,     4,     0,    57,     0,     0,     0,     0,     0,
    58,     6,     7,    59,    60,    48,     0,    49,     0,    50,
    51,     0,     0,    52,     0,     0,     0,     0,     0,     0,
    48,     0,    49,     0,    50,    51,     0,     0,    52,    53,
    54,    55,     0,     0,    22,     0,     0,     0,   -70,    56,
    51,     0,    57,    52,    53,    54,    55,     0,    58,    22,
     0,    59,    60,     0,    56,     0,     0,    57,     0,    53,
    54,    55,     0,    58,     0,     0,    59,    60,     0,    56,
     0,     0,    57,     0,     0,     0,     0,     0,    58,     0,
     0,    59,    60
};

static const short yycheck[] = {     0,
    63,    10,    49,    87,    52,    53,    54,     8,    55,    57,
   123,   124,   125,   126,   127,   128,    10,     1,   131,    22,
    31,     1,    26,    27,    28,    36,    31,    29,    17,    41,
    39,    31,    35,    45,    24,    25,    48,    38,     1,    41,
    44,     1,    51,    52,     1,    39,     1,     1,    95,    31,
    34,    98,     3,   137,    38,     6,     3,     8,    38,     6,
    63,     8,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,    38,    33,    37,     1,   192,
    35,    38,    12,    13,    41,   132,    87,    10,    45,    40,
    13,    48,     1,    40,    14,    15,    16,    48,    49,    50,
    31,    10,    49,    50,    13,    41,    29,    30,    31,    45,
     3,    36,    48,     6,    31,     8,    39,   112,   113,    42,
    29,    30,    31,     1,    38,    48,   189,   190,    51,    52,
    39,    23,    10,    42,   197,    13,   137,     1,    43,    48,
    33,    32,    51,    52,   118,   119,    10,    40,    38,    13,
    32,    29,    30,    31,     1,    32,    49,    50,    32,    32,
     4,    39,    33,     0,    42,    29,    30,    31,     1,    37,
    48,    13,     0,    51,    52,    39,     8,    10,    42,    85,
    13,    11,     1,    49,    48,   111,   110,    51,    52,    -1,
    -1,    10,    -1,    -1,    13,    -1,    29,    30,    31,    -1,
    29,    30,    31,    -1,    -1,    -1,    39,    36,    -1,    42,
    29,    30,    31,     1,    -1,    48,    -1,    -1,    51,    52,
    39,    -1,    10,    42,    -1,    13,    -1,     1,    -1,    48,
    -1,    -1,    51,    52,    -1,    -1,    10,    -1,    -1,    13,
    -1,    29,    30,    31,    17,    18,    19,    20,    21,    22,
    -1,    39,    -1,    -1,    42,    29,    30,    31,     1,    -1,
    48,    -1,    -1,    51,    52,    39,    -1,    10,    42,    -1,
    13,    -1,     1,    -1,    48,    -1,    -1,    51,    52,    -1,
    -1,    10,    -1,    -1,    13,    -1,    29,    30,    31,   114,
   115,   116,   117,    -1,    -1,    -1,    39,    -1,    -1,    42,
    29,    30,    31,     1,    -1,    48,    -1,    -1,    51,    52,
    39,    -1,    10,    42,    -1,    13,    -1,     1,    -1,    48,
    -1,    -1,    51,    52,    -1,    -1,    10,    -1,    -1,    13,
    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    39,    -1,    -1,    42,    29,    30,    31,     1,    -1,
    48,    -1,    -1,    51,    52,    39,    -1,    10,    42,    -1,
    13,    -1,     1,    -1,    48,    -1,    -1,    51,    52,    -1,
    -1,    10,    -1,    -1,    13,    -1,    29,    30,    31,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
    29,    30,    31,     1,    -1,    48,    -1,    -1,    51,    52,
    39,    -1,    10,    42,    -1,    13,    -1,     1,    -1,    48,
    -1,    -1,    51,    52,    -1,    -1,    10,    -1,    -1,    13,
    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    39,    -1,    -1,    42,    29,    30,    31,     1,    -1,
    48,    -1,    -1,    51,    52,    39,    -1,    10,    42,    -1,
    13,    -1,     1,    -1,    48,    -1,    -1,    51,    52,    -1,
    -1,    10,    -1,    -1,    13,    -1,    29,    30,    31,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
    29,    30,    31,     1,    -1,    48,    -1,    -1,    51,    52,
    39,    -1,    10,    42,    -1,    13,    -1,    -1,    -1,    48,
    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
    48,    -1,    -1,    51,    52,     3,    -1,     5,     6,     7,
     8,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    29,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,
    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
    48,    49,    50,    51,    52,     5,    -1,     7,    -1,     9,
    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
     5,    -1,     7,    -1,     9,    10,    -1,    -1,    13,    29,
    30,    31,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
    10,    -1,    42,    13,    29,    30,    31,    -1,    48,    34,
    -1,    51,    52,    -1,    39,    -1,    -1,    42,    -1,    29,
    30,    31,    -1,    48,    -1,    -1,    51,    52,    -1,    39,
    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,
    -1,    51,    52
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 7:
#line 52 "parser.y"
{
                 yyerrok;
                 reporterror(wrong_st);
           ;
    break;}
case 10:
#line 60 "parser.y"
{
                    /* type을 0(default)로 세팅 */    
                    look_tmp->type=0;
                    yyerrok;
                    reporterror(wrong_funcdef);    
                  ;
    break;}
case 18:
#line 80 "parser.y"
{type_int=1;;
    break;}
case 19:
#line 81 "parser.y"
{type_void=1;;
    break;}
case 20:
#line 82 "parser.y"
{type_float=1;;
    break;}
case 21:
#line 83 "parser.y"
{type_char=1;;
    break;}
case 22:
#line 84 "parser.y"
{type_string=1;;
    break;}
case 23:
#line 88 "parser.y"
{
	      strcpy(scope,preyytext);
                  /* type이 identifier about parse error또는 
                  not defined identifier/function로 설정된 경우 */
                  if(look_id->type==0||look_id->type==5){
                        
                        
                        /* void인지 int인지 float인지에 따라 function type 설정*/
                        if(type_void==1){
                              look_id->type=4; /* function, return type=void */
                        }else if(type_int==1){
                              look_id->type=8; /* function, return type=int */
                        }else if(type_float==1){
                              look_id->type=9; /* function, return type=float */
                        }else if(type_char==1){ /* function, return type=char */
                              look_id->type=14;
                        }else if(type_string==1){ /* function, return type=string */
                              look_id->type=15;
                        }
                    
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        type_char=0;
                        type_string=0;
                  }
                  ;
    break;}
case 31:
#line 127 "parser.y"
{
                    yyerrok;
                    reporterror(nocomma);
             ;
    break;}
case 32:
#line 135 "parser.y"
{
                  if(type_int==1){ /* int로 설정된 경우 */
                        param_int=1; 
                        look_id->type=10;  /* integer scalar parameter */
						strcpy(look_id->scope, scope);
                  }else if(type_float==1){ /* float으로 설정된 경우 */
                        param_float=1;
                        look_id->type=11; /* float scalar parameter */
                        strcpy(look_id->scope, scope);
                  }else if(type_char==1){
                        param_char=1;
                        look_id->type=16;                        
                        strcpy(look_id->scope, scope);
                  }
                  else if(type_string==1){
                        param_string=1;
                        look_id->type=17;                        
                       strcpy(look_id->scope, scope);
                  }
                  type_int=0;
                  type_void=0;
                  type_float=0;
                  type_char=0;
                  type_string=0;
                  param_int=0;
                  param_float=0;
                  param_char=0;
                  param_string=0;
	      look_tmp=look_id;
;
    break;}
case 34:
#line 168 "parser.y"
{
                        yyerrok;
                        reporterror(nobrace); /* no brace error */
                  ;
    break;}
case 39:
#line 179 "parser.y"
{
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        type_char=0;
                        type_string=0;
                  ;
    break;}
case 40:
#line 186 "parser.y"
{
                        look_tmp->type=0; /* identifier about parse error*/
                        yyerrok;
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        type_char=0;
                        type_string=0;
                        reporterror(nosemi); /* no semicolon error */
                  ;
    break;}
case 43:
#line 199 "parser.y"
{
                    yyerrok;
                    reporterror(nocomma);
             ;
    break;}
case 49:
#line 210 "parser.y"
{
                  if(look_id->type==0){
                        /* scalar : int인지 void인지 float인지에 따라*/
                        if(type_int==1){
                              look_id->type=1; /* integer scalar variable */
                              strcpy(look_id->scope, scope);
                        }
                        else if(type_void==1){
                              look_id->type=2; /* void scalar variable */
                              strcpy(look_id->scope, scope);
                        }
                        else if(type_float==1){
                              look_id->type=6; /* float scalar variable */
                              strcpy(look_id->scope, scope);
                        }
                        else if(type_char==1){
                              look_id->type=12; /* char scalar variable */
                              strcpy(look_id->scope, scope);
                        }     
                        else if(type_string==1){
                              look_id->type=13; /* string scalar variable */
                              strcpy(look_id->scope, scope);
                        }          
                  }
                  look_tmp=look_id;
            ;
    break;}
case 50:
#line 237 "parser.y"
{
                  /* array : int인지 float인지에 따라*/
                  if(look_id->type==0){
                        if(type_int==1)look_id->type=3; /* array integer variable */
                        else if(type_float==1) look_id->type=7;  /* array float variable */            
                  }
                   look_tmp=look_id;
            ;
    break;}
case 51:
#line 245 "parser.y"
{
                  yyerrok;
                  reporterror(nobracket); /* no bracekt error */
            ;
    break;}
case 68:
#line 271 "parser.y"
{
                        yyerrok;
                        reporterror(nosemi); /* no semicolon error */
                  ;
    break;}
case 83:
#line 295 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 84:
#line 299 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 85:
#line 303 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 86:
#line 307 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 87:
#line 311 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 88:
#line 315 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 91:
#line 322 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 94:
#line 329 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 98:
#line 337 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 99:
#line 341 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 105:
#line 351 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 106:
#line 356 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 107:
#line 360 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 108:
#line 364 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 111:
#line 371 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 113:
#line 376 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 118:
#line 384 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 119:
#line 388 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 120:
#line 393 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 136:
#line 421 "parser.y"
{
                  if(look_id->type==0)
                        look_id->type=5; /* not defined identifier/function */
            ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 432 "parser.y"

