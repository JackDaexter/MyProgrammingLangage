#include "table-symbol.h"
#define  STmax 800 /* maximum size of symbol table */


int SizeVarLocal = 0; /* size of symbol table */
int SizeVarGlobal = 0;

int SizeFunct = 0;

int addFunction (Function *functionTable, const char name[], int type,int position){
    int count;
  
    for (count = 0; count < SizeFunct; count++) {
        if (!strcmp(functionTable[count].vfunction.name,name)) {
				        fprintf(stderr,"Semantic error, redfinition of function %s\n",name);
            		return 1;
        }
    }

    if (++SizeFunct>STmax) {
        fprintf(stderr,"Error : oo many variables\n");
        exit(1);
    }
    strcpy(functionTable[SizeFunct-1].vfunction.name, name);
    functionTable[SizeFunct-1].vfunction.type = type;
    functionTable[SizeFunct-1].vfunction.position = position;	
    functionTable[SizeFunct-1].vfunction.valeur = 0;
}

int addArgument(Function *funct, const char name[],int type,char *arg){
  int i = 0;
  int valeur;
  for(i = 0; i < SizeFunct;i++){
      if(!strcmp(funct[i].vfunction.name,name)){
          funct[i].vfunction.argument[valeur].type = type;
          valeur = funct[i].vfunction.nbargs;
          strncpy(funct[i].vfunction.argument[valeur].arg,arg,strlen(arg));
          funct[i].vfunction.argument[valeur].value = funct[i].vfunction.nbargs;
          funct[i].vfunction.nbargs +=1;
      }
  }

}

void alloueEspace(FILE *out,STentry *alloue,int position){
  int i = 0;
  for (i = 0; i < SizeVarLocal; i++) {
        if(position == alloue[i].variableLocal.position){
          if(alloue[i].variableLocal.type == 8){
             fprintf(out,"\t mov QWORD [rsp - %d] \n",alloue[i].variableLocal.adresse);
          }
          else if(alloue[i].variableLocal.type == 4)
            fprintf(out,"\t mov DWORD [rsp - %d] \n",alloue[i].variableLocal.adresse);
          else
            fprintf(out,"\t mov BYTE [rsp - %d] \n",alloue[i].variableLocal.adresse);

        }

   } 
}
int getadress(STentry *local,const char name[]){
  int i = 0;
   for (i = SizeVarLocal-1; i >= 0; i--) {
          if (!strcmp(local[i].variableLocal.name, name)){
              return local[i].variableLocal.adresse;
          }
   } 

   for (i = SizeVarGlobal-1; i >= 0; i--) {
          if (!strcmp(local[i].variableGlobal.name, name)){
              return -2;
          }
   } 
   return -1;

}

int nbValue(){
  return SizeVarLocal;
}

void analyse(Variable value1, Variable value2){

}


void declareGlobal(FILE *out,STentry *symbolTable){
    int i = 0;
    fprintf(out,"section .bss\n");
    for(i = 0; i < SizeVarGlobal; i++){
        if(symbolTable[i].variableGlobal.isConst == 0){
          if(symbolTable[i].variableGlobal.type == VALUE_LONG)
           fprintf(out,"\t %s resq 1\n",symbolTable[i].variableGlobal.name);
          else if(symbolTable[i].variableGlobal.type == VALUE_INT)
           fprintf(out,"\t %s resd 1\n",symbolTable[i].variableGlobal.name);
          else if(symbolTable[i].variableGlobal.type == VALUE_CHAR)
           fprintf(out,"\t %s resb 1\n",symbolTable[i].variableGlobal.name);
       }
    }
    fprintf(out,"section .data\n");
    for(i = 0; i < SizeVarGlobal; i++){
        if(symbolTable[i].variableGlobal.isConst == 3){

          if(symbolTable[i].variableGlobal.type == VALUE_LONG)
           fprintf(out,"\t %s EQU %d\n",symbolTable[i].variableGlobal.name,symbolTable[i].variableGlobal.valeur);
          else if(symbolTable[i].variableGlobal.type == VALUE_INT)
           fprintf(out,"\t %s EQU %d\n",symbolTable[i].variableGlobal.name,symbolTable[i].variableGlobal.valeur);
          else if(symbolTable[i].variableGlobal.type == VALUE_CHAR)
           fprintf(out,"\t %s EQU %c\n",symbolTable[i].variableGlobal.name,symbolTable[i].variableGlobal.valeur);
       }
    }

    fprintf(out,"\t printf_char db \"%%c\", 10,0\n");
    fprintf(out,"\t printf_long db \"%%ld\", 10,0\n");
    fprintf(out,"\t printf_int db \"%%d\", 10,0\n");
    fprintf(out,"\t read_long db \"%%ld\" ,10,0 \n");
    fprintf(out,"\t read_char db \"%%c\" ,10,0 \n");
    fprintf(out,"\t read_int db \"%%d\" ,10,0 \n");
    

    
}
/* is_global : La variable is_global permet de savoir si une variable est local ou global
   	       et dans le cas échéant on le stocke dans la bonne structure

   position: Permet de vérifier si il ya une redéfinition de variable dans 
	     une fonction ou parmis les variables globales*/

int addVar(STentry *symbolTable, const char name[], int type,int position,int is_global,int isConst,int valeur){
  int count;
  int taille = type * SizeVarLocal;
  for (count = 0; count < SizeVarLocal; count++) {
  	
  	if(is_global == 0){
    		if (!strcmp(symbolTable[count].variableLocal.name,name) ) {
    		   if(symbolTable[count].variableLocal.position == position){
    			    fprintf(stderr,"Semantic error, redfinition of variable %s\n",name);
    		    	return 1;
    		   }
    		}
  	}
    if(taille == symbolTable[count].variableLocal.adresse){
        taille += taille;
    }
  }

  for(count = 0; count < SizeVarGlobal; count++){
  	if (!strcmp(symbolTable[count].variableGlobal.name,name) ) {
  		if(symbolTable[count].variableGlobal.position == position){
  			  fprintf(stderr,"Semantic error, redfinition of variable %s\n",name);
  		    return 1;
  			}
  		}
    }
     
  
    if(is_global == 0){
	    if (++SizeVarLocal>STmax) {
       		 fprintf(stderr,"Error : Too many variables\n");
        	 exit(1);
    	    }
      

	    strcpy(symbolTable[SizeVarLocal-1].variableLocal.name, name);
	    symbolTable[SizeVarLocal-1].variableLocal.type = type;
	    symbolTable[SizeVarLocal-1].variableLocal.position = position;
      symbolTable[SizeVarLocal-1].variableLocal.adresse = taille;
      symbolTable[SizeVarLocal-1].variableLocal.isConst = isConst;
    }	
    else if(is_global == 1){
	    if (++SizeVarGlobal>STmax) {
        	fprintf(stderr,"Error too many variables\n");
        	exit(1);
   	    }
	    strcpy(symbolTable[SizeVarGlobal-1].variableGlobal.name, name);
	    symbolTable[SizeVarGlobal-1].variableGlobal.type = type;
	    symbolTable[SizeVarGlobal-1].variableGlobal.position = position;
		  symbolTable[SizeVarGlobal-1].variableGlobal.adresse = type * SizeVarGlobal;
      if(isConst == 3){
       symbolTable[SizeVarGlobal-1].variableGlobal.isConst = isConst;
       symbolTable[SizeVarGlobal-1].variableGlobal.valeur = valeur;
      }
    }	
}


int lookup(STentry *symbolTable, const char name[],int position,int lineno){
    int count,verify = 0;

    for (count = 0; count < SizeVarGlobal; count++) {
        if (!strcmp(symbolTable[count].variableGlobal.name,name)) {
              if ((symbolTable[count].variableGlobal.position == position || symbolTable[count].variableGlobal.position == 0)){
            	     verify = 1;
	                 break;
	            }
        }
    }

    if(verify == 0){
        for (count = 0; count < SizeVarLocal; count++) {
            if (!strcmp(symbolTable[count].variableLocal.name,name)) {
                  if ((symbolTable[count].variableLocal.position == position || symbolTable[count].variableLocal.position == 0)){
                       verify = 1;
                       break;
                  }
            }
        }
    }

    if(verify == 0){
		  fprintf(stderr,"Error : line %d : error, this variable wasn't declared  \n",lineno);
		  return 1;
    }
    
}


int lookupFunction(Function *symbolTable, const char name[]){
   int count,verify = 0;
   	
   for (count = 0; count <= SizeFunct; count++) {
       if (!strcmp(symbolTable[count].vfunction.name,name)) {
            	verify = 1;
              return 1;
	   	}
       
    }
    
   if(verify == 0 && !strcmp(name,"main")){
  		fprintf(stderr,"Semantic error : There is no 'main' function \n");
  		return 1;
    }
    return 0;
    
}

STentry *searchIdLocal(STentry *symbolTable, const char name[],int position,int is_global){
    int i;


      for (i = SizeVarLocal-1; i >= 0; i--) {
        
          if (!strcmp(symbolTable[i].variableLocal.name, name)){
  	         if((symbolTable[i].variableLocal.position == position) || symbolTable[i].variableLocal.position == 0)
            	  return &symbolTable[i];
  	     
    	    }
      }
    
   
    return NULL;
    
}

STentry *searchIdGlobal(STentry *symbolTable, const char name[],int position,int is_global){
    int i;


   for (i = SizeVarGlobal -1 ; i >= 0; i--) {
          if (!strcmp(symbolTable[i].variableGlobal.name, name)){
             if((symbolTable[i].variableGlobal.position == position) || symbolTable[i].variableGlobal.position == 0)
                return &symbolTable[i];
         
        }
    }

    
    return NULL;
    
}

int getNbArgument(Function * funct, const char name[]){
    int i;
    int j;
    int var;
    for(i = SizeFunct - 1 ; i >= 0; i--){
       if (!strcmp(funct[i].vfunction.name, name)){
          return funct[i].vfunction.nbargs;
       }
    }
    return -1;
}


int getArgument(Function * funct, const char name[],const char namearg[]){
    int i;
    int j;
    int var;
    for(i = SizeFunct - 1 ; i >= 0; i--){
       if (!strcmp(funct[i].vfunction.name, name)){
          var = funct[i].vfunction.nbargs;
          for(j = var - 1 ; j >= 0; j--){
            if(!strcmp(funct[i].vfunction.argument[j].arg,namearg)){
                return funct[i].vfunction.argument[j].value;
            }
          }
       }
    }
    return -1;
}


char * returnString(Function *value,char name[]){
   int count = 0;
   for (count = 0; count < SizeFunct; count++) {
   
       if (!strcmp(value[count].vfunction.name,name)) {
              if(!strcmp(name,"main"))
                return "_start";
              else
                return name;

      }
       
    }

}