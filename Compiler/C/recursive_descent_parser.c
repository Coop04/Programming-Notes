#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> // for isalnum() function
char input[20];
int error=0,i=0;
void E(); 
void T(); 
void Eprime(); 
void Tprime(); 
void F(); 
void E() {
    T();
    Eprime();
}
void Eprime() {
    if(input[i]=='+') {
        i++;
        T();
        Eprime();
    }
}
void T() {
    F();
    Tprime();
}
void Tprime() {
    if(input[i]=='*') {
        i++;
        F();
        Tprime();
    }
}
void F() {
    if(isalnum(input[i]))
        i++;
    else if(input[i]=='(') {
        i++;
        E();
        if(input[i]==')')
            i++;
        else
            error = 1;
    }
    else 
        error = 1;
}

void main() {
    printf("Enter arithmetic expression: ");
    gets(input);
    E();
    if(strlen(input)==i &&error==0)
        printf("Accepted!");
    else    
        printf("Rejected!");
}

// a+b*c - Accepted
// a+b*  - Rejected