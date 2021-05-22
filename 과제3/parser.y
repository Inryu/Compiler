%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
/* yacc source for Mini C */

int type_int =0;
int type_void=0;

void line(int n);
extern printError();
extern yylex();
extern yyerror(char *s);

%}
%token TCONST TELSE TIF TINT TRETURN  TVOID TWHILE
%token TPLUS TMINUS TSTAR TSLASH TMOD TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSGIN TOR TEQUAL TNOTEQU TLESS TOVER TLESSE TINC TDEC
%token TOSBRA TCSBRA TCOMMA TOMBRA TCMBRA TOLBRA TCLBRA TSEMI
%token TNUMBER TFLOAT TLONG TNOT TAND TOVERE TILLIDENT TONECMT TMULCMT
%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE


%%
mini_c 			: translation_unit 
			;			
translation_unit 	: external_dcl				
			| translation_unit external_dcl
			;
external_dcl 		: function_def			
		  	| declaration
			;				
function_def 		: function_header compound_st
			;		
function_header 	: dcl_spec function_name formal_param	
			;
dcl_spec 		: dcl_specifiers	
			;	
dcl_specifiers 		: dcl_specifier			
		 	| dcl_specifiers dcl_specifier	
			;
dcl_specifier 		: type_qualifier		
			| type_specifier
			;			
type_qualifier 		: TCONST
			;				
type_specifier 		: TINT				
		 	| TVOID
			;
					
function_name 	: TIDENT
		;				
formal_param 		: TOSBRA opt_formal_param TCSBRA 
			;	
opt_formal_param 	: formal_param_list		
		   	|	
			;			
formal_param_list 	: param_dcl			
		    	| formal_param_list TCOMMA param_dcl 	
			;
param_dcl 		: dcl_spec declarator	
			;	
compound_st 		: TOMBRA opt_dcl_list opt_stat_list TCMBRA
			;
opt_dcl_list 		: declaration_list	
			|	
			;			
declaration_list 	: declaration			
			| declaration_list declaration 
			;	
declaration 		: dcl_spec init_dcl_list TSEMI
			;
init_dcl_list 		: init_declarator			
			| init_dcl_list ',' init_declarator 
			;	
init_declarator 	: declarator				
		 	| declarator TASSIGN TNUMBER	
			;
declarator 		: TIDENT					
	     		| TIDENT TOLBRA opt_number TCLBRA	
			;
opt_number 		: TNUMBER			
	     		|	
			;			
opt_stat_list 		: statement_list		
		 	|	
			;			
statement_list 		: statement			
		 	| statement_list statement 	
			;
statement 		: compound_st			
	   		| expression_st			
	   		| if_st				
	   		| while_st				
	   		| return_st			
	   		;
expression_st 	: opt_expression 
		;	
opt_expression 	: expression				
		|
		;					
if_st 			: TIF TOSBRA expression TCSBRA statement  TMODprec LOWER_THAN_ELSE
			| TIF TOSBRA expression TCSBRA statement TELSE statement
			;
while_st 		: TWHILE TOSBRA expression TCSBRA statement 	
			;
return_st 		: TRETURN opt_expression TSEMI
			;
expression 		: assignment_exp	
			;	
assignment_exp 	: logical_or_exp			
		| unary_exp TASSIGN assignment_exp
		| unary_exp TADDASSIGN assignment_exp 	
		| unary_exp TSUBASSIGN assignment_exp 	
		| unary_exp TMULASSIGN assignment_exp 	
		| unary_exp TDIVASSIGN assignment_exp 	
		| unary_exp TMODASSIGN assignment_exp 	
		;
logical_or_exp 	: logical_and_exp			
		| logical_or_exp TOR logical_and_exp 	
		;
logical_and_exp 	: equality_exp				
		 	| logical_and_exp TAND equality_exp 
			;	
equality_exp 		: relational_exp			
			| equality_exp TEQUAL relational_exp 	
			| equality_exp TNOTEQU relational_exp 
			;	
relational_exp 	: additive_exp 			
		| relational_exp TOVER additive_exp 	
		| relational_exp TLESS additive_exp 	
		| relational_exp TGREATE additive_exp 	
		| relational_exp TLESSE additive_exp 
		;	
additive_exp 	: multiplicative_exp			
		| additive_exp TPLUS multiplicative_exp 	
		| additive_exp TMINUS multiplicative_exp 	
		;
multiplicative_exp 	: unary_exp				
		    	| multiplicative_exp TSTAR unary_exp 	
		    	| multiplicative_exp TSLASH unary_exp 	
		    	| multiplicative_exp TMOD unary_exp 	
			;
unary_exp 		: postfix_exp				
	   		| TMINUS unary_exp				
	   		| TNOT unary_exp				
	   		| TINC unary_exp			
	   		| TDEC unary_exp
			;			
postfix_exp 		: primary_exp				
	      		| postfix_exp TOLBRA expression TCLBRA 	
	      		| postfix_exp TOSBRA opt_actual_param TCSBRA 	
	      		| postfix_exp TINC
	      		| postfix_exp TDEC
			;			
opt_actual_param 	: actual_param				
		  	|		
			;			
actual_param 		: actual_param_list	
			;		
actual_param_list 	: assignment_exp			
		   	| actual_param_list TCOMMA assignment_exp 	
			;
primary_exp 		: TIDENT				
	     		| TNUMBER				
	     		| TOSBRA expression TCSBRA
			;
%%
void line(int n)
{	
	printf("\t %d \t",n);
}