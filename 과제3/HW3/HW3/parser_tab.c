
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
#define	TPLUS	265
#define	TMINUS	266
#define	TSTAR	267
#define	TSLASH	268
#define	TMOD	269
#define	TASSIGN	270
#define	TADDASSIGN	271
#define	TSUBASSIGN	272
#define	TMULASSIGN	273
#define	TDIVASSIGN	274
#define	TMODASSIGN	275
#define	TOR	276
#define	TEQUAL	277
#define	TNOTEQU	278
#define	TLESS	279
#define	TOVER	280
#define	TLESSE	281
#define	TINC	282
#define	TDEC	283
#define	TOSBRA	284
#define	TCSBRA	285
#define	TCOMMA	286
#define	TOMBRA	287
#define	TCMBRA	288
#define	TOLBRA	289
#define	TCLBRA	290
#define	TSEMI	291
#define	TNUMBER	292
#define	TFLOAT	293
#define	TLONG	294
#define	TNOT	295
#define	TAND	296
#define	TOVERE	297
#define	TILLIDENT	298
#define	TONECMT	299
#define	TMULCMT	300
#define	TIDENT	301
#define	TGREATE	302
#define	LOWER_THAN_ELSE	303

#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

int type_int =0;
int type_void=0;


extern reporterror();
extern yylex();
extern yyerror(char *s);


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



#define	YYFINAL		163
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 94)

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
    46,    47,    48
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    53,    55,    56,    58,    62,    65,    70,    75,    77,
    78,    80,    83,    87,    91,    93,    97,    99,   103,   105,
   110,   115,   117,   118,   120,   121,   123,   126,   128,   130,
   132,   134,   136,   139,   142,   144,   145,   151,   159,   165,
   169,   171,   173,   177,   181,   185,   189,   193,   197,   199,
   203,   205,   209,   211,   215,   219,   221,   225,   229,   233,
   237,   239,   243,   247,   249,   253,   257,   261,   263,   266,
   269,   272,   275,   277,   282,   287,   290,   293,   295,   296,
   298,   300,   304,   306,   308
};

static const short yyrhs[] = {    50,
     0,    51,     0,    50,    51,     0,    52,     0,    67,     0,
    46,    36,     0,    46,     1,     0,    53,    64,     0,    53,
    36,     0,    53,     1,     0,    54,    59,    60,     0,    55,
     0,    56,     0,    55,    56,     0,    57,     0,    58,     0,
     3,     0,     6,     0,     8,     0,    46,     0,    29,    61,
    30,     0,    62,     0,     0,    63,     0,    62,    31,    63,
     0,    54,    70,     0,    32,    65,    72,    33,     0,    32,
    65,    72,     1,     0,    66,     0,     0,    67,     0,    66,
    67,     0,    54,    68,    36,     0,    54,    68,     1,     0,
    69,     0,    68,    31,    69,     0,    70,     0,    70,    15,
    37,     0,    46,     0,    46,    34,    71,    35,     0,    46,
    34,    71,     1,     0,    37,     0,     0,    73,     0,     0,
    74,     0,    73,    74,     0,    64,     0,    75,     0,    77,
     0,    78,     0,    79,     0,    76,    36,     0,    80,     1,
     0,    80,     0,     0,     5,    29,    80,    30,    74,     0,
     5,    29,    80,    30,    74,     4,    74,     0,     9,    29,
    80,    30,    74,     0,     7,    76,    36,     0,    81,     0,
    82,     0,    88,    15,    81,     0,    88,    16,    81,     0,
    88,    17,    81,     0,    88,    18,    81,     0,    88,    19,
    81,     0,    88,    20,    81,     0,    83,     0,    82,    21,
    83,     0,    84,     0,    83,    41,    84,     0,    85,     0,
    84,    22,    85,     0,    84,    23,    85,     0,    86,     0,
    85,    25,    86,     0,    85,    24,    86,     0,    85,    47,
    86,     0,    85,    26,    86,     0,    87,     0,    86,    10,
    87,     0,    86,    11,    87,     0,    88,     0,    87,    12,
    88,     0,    87,    13,    88,     0,    87,    14,    88,     0,
    89,     0,    11,    88,     0,    40,    88,     0,    27,    88,
     0,    28,    88,     0,    93,     0,    89,    34,    80,    35,
     0,    89,    29,    90,    30,     0,    89,    27,     0,    89,
    28,     0,    91,     0,     0,    92,     0,    81,     0,    92,
    31,    81,     0,    46,     0,    37,     0,    29,    80,    30,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    29,    31,    32,    34,    35,    36,    37,    42,    43,    44,
    51,    53,    55,    56,    58,    59,    61,    63,    64,    67,
    78,    80,    81,    83,    84,    86,    88,    89,    95,    96,
    98,    99,   101,   105,   113,   114,   116,   117,   119,   128,
   138,   143,   144,   146,   147,   149,   150,   152,   153,   154,
   155,   156,   158,   159,   165,   166,   168,   169,   171,   173,
   175,   177,   178,   179,   180,   181,   182,   183,   185,   186,
   188,   189,   191,   192,   193,   195,   196,   197,   198,   199,
   201,   202,   203,   205,   206,   207,   208,   210,   211,   212,
   213,   214,   216,   217,   218,   219,   220,   222,   223,   225,
   227,   228,   230,   236,   237
};

static const char * const yytname[] = {   "$","error","$undefined.","TCONST",
"TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TPLUS","TMINUS","TSTAR","TSLASH",
"TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN",
"TOR","TEQUAL","TNOTEQU","TLESS","TOVER","TLESSE","TINC","TDEC","TOSBRA","TCSBRA",
"TCOMMA","TOMBRA","TCMBRA","TOLBRA","TCLBRA","TSEMI","TNUMBER","TFLOAT","TLONG",
"TNOT","TAND","TOVERE","TILLIDENT","TONECMT","TMULCMT","TIDENT","TGREATE","LOWER_THAN_ELSE",
"mini_c","translation_unit","external_dcl","function_def","function_header",
"dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","formal_param","opt_formal_param","formal_param_list","param_dcl",
"compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    51,    51,    51,    51,    52,    52,    52,
    53,    54,    55,    55,    56,    56,    57,    58,    58,    59,
    60,    61,    61,    62,    62,    63,    64,    64,    65,    65,
    66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
    70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
    74,    74,    75,    75,    76,    76,    77,    77,    78,    79,
    80,    81,    81,    81,    81,    81,    81,    81,    82,    82,
    83,    83,    84,    84,    84,    85,    85,    85,    85,    85,
    86,    86,    86,    87,    87,    87,    87,    88,    88,    88,
    88,    88,    89,    89,    89,    89,    89,    90,    90,    91,
    92,    92,    93,    93,    93
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     3,     1,     0,     1,     3,     2,     4,     4,     1,     0,
     1,     2,     3,     3,     1,     3,     1,     3,     1,     4,
     4,     1,     0,     1,     0,     1,     2,     1,     1,     1,
     1,     1,     2,     2,     1,     0,     5,     7,     5,     3,
     1,     1,     3,     3,     3,     3,     3,     3,     1,     3,
     1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
     1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
     2,     2,     1,     4,     4,     2,     2,     1,     0,     1,
     1,     3,     1,     1,     3
};

static const short yydefact[] = {     0,
    17,    18,    19,     0,     1,     2,     4,     0,     0,    12,
    13,    15,    16,     5,     7,     6,     3,    10,    30,     9,
     8,    39,     0,     0,    35,    37,    14,     0,    45,    29,
    31,    43,    23,    11,    34,     0,    33,     0,    39,     0,
    56,     0,     0,     0,     0,     0,   104,     0,   103,    48,
     0,    44,    46,    49,     0,    50,    51,    52,     0,    61,
    62,    69,    71,    73,    76,    81,    84,    88,    93,    32,
    42,     0,     0,     0,    22,    24,    36,    38,     0,     0,
    55,     0,    89,    91,    92,     0,    90,    28,    27,    47,
    53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    96,    97,    99,     0,    41,    40,    26,    21,     0,
     0,    60,     0,   105,    70,    84,    72,    74,    75,    78,
    77,    80,    79,    82,    83,    85,    86,    87,    63,    64,
    65,    66,    67,    68,   101,     0,    98,   100,     0,    25,
    56,    56,    95,     0,    94,    57,    59,   102,    56,    58,
     0,     0,     0
};

static const short yydefgoto[] = {   161,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    23,
    34,    74,    75,    76,    50,    29,    30,    14,    24,    25,
    26,    72,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
   146,   147,   148,    69
};

static const short yypact[] = {     3,
-32768,-32768,-32768,    36,     3,-32768,-32768,    35,   -36,   112,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   112,-32768,
-32768,    82,   -12,    43,-32768,     9,-32768,   -19,    41,   112,
-32768,    -6,   112,-32768,-32768,   -19,-32768,     4,    49,    56,
     5,    60,     5,     5,     5,     5,-32768,     5,-32768,-32768,
    79,    41,-32768,-32768,    65,-32768,-32768,-32768,    74,-32768,
    87,    62,    16,    66,   111,   116,    78,     1,-32768,-32768,
-32768,    12,   -19,    89,   100,-32768,-32768,-32768,     5,   101,
-32768,     5,-32768,-32768,-32768,   106,-32768,-32768,-32768,-32768,
-32768,-32768,     5,     5,     5,     5,     5,     5,     5,     5,
     5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
     5,-32768,-32768,     5,     5,-32768,-32768,-32768,-32768,   112,
   108,-32768,   109,-32768,    62,-32768,    16,    66,    66,   111,
   111,   111,   111,   116,   116,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   110,-32768,   113,   107,-32768,
    77,    77,-32768,     5,-32768,   137,-32768,-32768,    77,-32768,
   143,   145,-32768
};

static const short yypgoto[] = {-32768,
-32768,   141,-32768,-32768,   -18,-32768,   138,-32768,-32768,-32768,
-32768,-32768,-32768,    29,   139,-32768,-32768,    -5,-32768,   114,
    80,-32768,-32768,-32768,   -52,-32768,   115,-32768,-32768,-32768,
   -39,   -88,-32768,    58,    61,    37,    27,    33,   -40,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		156


static const short yytable[] = {    90,
    28,    81,    83,    84,    85,     1,    86,    87,     2,    22,
     3,    28,   116,    31,    73,    43,    33,   139,   140,   141,
   142,   143,   144,    38,    70,   145,    39,   112,   113,   114,
    71,    44,    45,    46,   115,    18,    15,    95,    96,   121,
    78,    47,   123,    35,    48,    40,   117,    41,     4,    42,
    49,    43,   126,   126,   126,   126,   126,   126,   126,   126,
   126,   126,   136,   137,   138,   158,    19,    44,    45,    46,
    20,    16,    19,    36,    92,   149,   -56,    47,    37,    88,
    48,    40,    32,    41,    79,    42,    49,    43,    82,    97,
    98,    99,   106,   107,   108,   109,   110,   111,   156,   157,
    91,    73,    94,    44,    45,    46,   160,    93,    19,   -55,
   -20,    89,   100,    47,     1,    32,    48,     2,   119,     3,
   101,   102,    49,   130,   131,   132,   133,   103,   104,   105,
   120,   128,   129,   134,   135,   124,   122,   151,   152,   153,
   159,   155,   162,   154,   163,    17,    21,    27,   150,    77,
   125,     0,   118,     0,   127,    80
};

static const short yycheck[] = {    52,
    19,    41,    43,    44,    45,     3,    46,    48,     6,    46,
     8,    30,     1,    19,    33,    11,    29,   106,   107,   108,
   109,   110,   111,    15,    30,   114,    46,    27,    28,    29,
    37,    27,    28,    29,    34,     1,     1,    22,    23,    79,
    37,    37,    82,     1,    40,     5,    35,     7,    46,     9,
    46,    11,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   154,    32,    27,    28,    29,
    36,    36,    32,    31,     1,   115,    36,    37,    36,     1,
    40,     5,    34,     7,    29,     9,    46,    11,    29,    24,
    25,    26,    15,    16,    17,    18,    19,    20,   151,   152,
    36,   120,    41,    27,    28,    29,   159,    21,    32,    36,
    29,    33,    47,    37,     3,    34,    40,     6,    30,     8,
    10,    11,    46,    97,    98,    99,   100,    12,    13,    14,
    31,    95,    96,   101,   102,    30,    36,    30,    30,    30,
     4,    35,     0,    31,     0,     5,     8,    10,   120,    36,
    93,    -1,    73,    -1,    94,    41
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
#line 37 "parser.y"
{
                 yyerrok;
                 reporterror(wrong_st);
           ;
    break;}
case 10:
#line 45 "parser.y"
{
                    look_tmp->type=0;
                    yyerrok;
                    reporterror(wrong_funcdef);    
                  ;
    break;}
case 18:
#line 63 "parser.y"
{type_int=1;;
    break;}
case 19:
#line 64 "parser.y"
{type_void=1;;
    break;}
case 20:
#line 69 "parser.y"
{
                  if(look_id->type==0||look_id->type==5){
                        look_id->type=4;
                        type_int=0;
                        type_void=0;
                        look_tmp=look_id;
                  }
;
    break;}
case 28:
#line 90 "parser.y"
{
                        yyerrok;
                        reporterror(nobrace);
                  ;
    break;}
case 33:
#line 101 "parser.y"
{
                        type_int=0;
                        type_void=0;
                  ;
    break;}
case 34:
#line 105 "parser.y"
{
                        look_tmp->type=0;
                        yyerrok;
                        type_int=0;
                        type_void=0;
                        reporterror(nosemi);
                  ;
    break;}
case 39:
#line 119 "parser.y"
{
                  if(look_id->type==0){
                        if(type_int==1)
                              look_id->type=1;
                        else if(type_void==1)
                              look_id->type=2;
                  }
                  look_tmp=look_id;
            ;
    break;}
case 40:
#line 129 "parser.y"
{
                  if(look_id->type==0){
                        look_id->type=3;
                       
                  }

                   look_tmp=look_id;

            ;
    break;}
case 41:
#line 138 "parser.y"
{
                  yyerrok;
                  reporterror(nobracket);
            ;
    break;}
case 54:
#line 160 "parser.y"
{
                        yyerrok;
                        reporterror(nosemi);
                  ;
    break;}
case 103:
#line 231 "parser.y"
{
                  if(look_id->type=0)
                        look_id->type=5;

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
#line 239 "parser.y"


