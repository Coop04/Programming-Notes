#include<stdio.h> 
#include<string.h> 
char op[2],arg1[5],arg2[5],result[5]; 
void main(){ 
 
    FILE *f1,*f2; 
    f1=fopen("input1.txt","r"); 
    f2=fopen("output1.txt","w"); 
    fscanf(f1,"%s%s%s%s",op,arg1,arg2,result); 
    while(!feof(f1)){ 
        if(strcmp(op,"+")==0) 
        { 
        
           fprintf(f2,"\nMOV R0,%s",arg1); 
           fprintf(f2,"\nADD R0,%s",arg2); 
           fprintf(f2,"\nMOV %s,R0",result); 
        
        } 
        if(strcmp(op,"*")==0) 
        { 
        
           fprintf(f2,"\nMOV R0,%s",arg1); 
           fprintf(f2,"\nMUL R0,%s",arg2); 
           fprintf(f2,"\nMOV %s,R0",result); 
        
        } 
         
        if(strcmp(op,"-")==0) 
        { 
        
           fprintf(f2,"\nMOV R0,%s",arg1); 
           fprintf(f2,"\nSUB R0,%s",arg2); 
           fprintf(f2,"\nMOV %s,R0",result); 
        
        } 
         
        if(strcmp(op,"/")==0) 
        { 
        
           fprintf(f2,"\nMOV R0,%s",arg1); 
           fprintf(f2,"\nDIV R0,%s",arg2); 
           fprintf(f2,"\nMOV %s,R0",result); 
        
        } 
            if(strcmp(op,"=")==0) 
        { 
        
        fprintf(f2,"\nMOV R0,%s",arg1); 
        fprintf(f2,"\nMOV %s,R0",result);   
        } 
        fscanf(f1,"%s%s%s%s",op,arg1,arg2,result); 
        }
    fclose(f1);fclose(f2); 
}