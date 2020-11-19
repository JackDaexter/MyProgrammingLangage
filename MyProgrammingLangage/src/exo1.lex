%{ 
	#include <stdio.h>
	#include "table-symbol.h"
	#include "exo1.tab.h"
	#define MAXNAME 32
	int lineno = 1;
%}

%option noinput
%option nounput
%x commentaire
%%

\n lineno++;
<*><<EOF>> return 0;


"/*" BEGIN(commentaire);
<commentaire>[^*\n]*
<commentaire>"*"+[^*/\n]*
<commentaire>\n lineno++;
<commentaire>"*"+"/" BEGIN(INITIAL);


" " ;
[\t] ;
void 			{yylval.type = 3; return VOID;}
const 			{return CONST;}
readc 			{return READC;}
reade  			return READE;
while  			return WHILE;
print  			return PRINT;
if  			return IF;
[0-9]+ 			{yylval.value = atoi(yytext); return NUM;}
else 			return ELSE;
"+"|"-"			{yylval.caractere = yytext[0]; return ADDSUB;}
int 			{yylval.type = 4;return TYPE;}
char 			{yylval.type = 1; return TYPE;}
long			{yylval.type = 8; return TYPE;}
"=="|"!="	return EQ;
">" 	{strncpy(yylval.name,yytext,MAXNAME);return ORDERC;}
"<"		{strncpy(yylval.name,yytext,MAXNAME);return ORDERC;}
"<="	{strncpy(yylval.name,yytext,MAXNAME);return ORDERC;}
">="	{strncpy(yylval.name,yytext,MAXNAME);return ORDERC;}
"{"		{return RACC;}
"}"		{return LACC;}
"("		{return PO;}
")"		{return PF;}
"="		{return EQUAL;}
"*"|"/"|"%" 	{yylval.caractere = yytext[0]; return DIVSTAR;}
"||" 			return OR; 
"&&" 			return AND;
return 			return RETURN;

'[a-zA-Z]'  { yylval.type = 1;strncpy(yylval.carac,yytext,MAXNAME);return CARACTERE;}
([a-zA-Z]|_)([a-zA-Z]|[0-9]|_)*   { strncpy(yylval.name,yytext,MAXNAME); return IDENT;}
! return '!';
. {return yytext[0];}

%%
