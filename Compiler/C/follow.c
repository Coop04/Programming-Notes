#include<stdio.h>
#include<ctype.h>
#include<string.h>

char p[10][10], first[10], follow[10];
int nf=0,n,nfl=0;

void fir(char c);
void fol(char c);
int inc(char c);
int incfl(char c);

void main() {
    int i;
    char ch,choice=0;

    printf("Enter no. of productions: ");
    scanf("%d",&n);

    printf("Enter Expressions:\n");
    for(i=0;i<n;i++) {
        scanf("%s",p[i]);
    }

    printf("Enter the character: ");
    scanf(" %c",&ch);

    do {
        nfl=0,nf=0; // reset both indices for checking new character
        fol(ch);

        printf("\nfollow(%c)={",ch);
        for(i=0;i<nfl;i++) {
            if(i!=nfl-1) {
                printf("%c, ",follow[i]);
            }
            else {
                printf("%c}",follow[i]);
            }
        }
        printf("Enter 1 to continue: ");
        scanf("%d",&choice);
        if(choice==1) {
            printf("\n\nEnter next character: ");
            scanf(" %c",&ch);
        }
    } while(choice==1);
}

void fir(char c) {
    if(!isupper(c)) { // character itself
        if(!inc(c)) {
            first[nf++]=c;
        }
    }
    for(int i=0;i<n;i++) {
        if(p[i][0]==c) {
            if(p[i][2]=='$') { // if 3rd letter is $ (add it to first[])
                if(!inc('$')) {
                    first[nf++]='$';
                }
            }
            if (!isupper(p[i][2])) { // if 3rd letter is terminal (add it to first[])
                if(!inc(p[i][2])) {
                    first[nf++]=p[i][2];
                }
            }
            else { // if 3rd letter is non terminal (call its first)
                fir(p[i][2]);
            }
        }
    }
}

void fol(char c) {
    if(p[0][0]==c) { // if start symbol (add $ to follow)
        if(!incfl('$'))
            follow[nfl++]='$'; 
    }

    for(int i=0;i<n;i++) {
        for(int j=2;j<strlen(p[i]);j++) {
            
            if(p[i][j]==c) { // if p[i][j] is c the do
                int k=j+1;
                while(k<strlen(p[i])) {
                    if(!isupper(p[i][k])) { // if terminal symbol (add to follow[])
                        if(!incfl(p[i][k])) {
                            follow[nfl++]=p[i][k];
                        }
                        break; // stop, since a terminal was found
                    }
                    else { // if non-terminal (find first and copy to follow except $)
                        nf=0;
                        fir(p[i][k]);
                        int eps=0;
                        for(int x=0;x<nf;x++) {
                            if(first[x]!='$') { // if first[] is not $ copy to follow[]
                                if(!incfl(first[x])) {
                                    follow[nfl++]=first[x];
                                }
                            }
                            else 
                                eps=1;
                        }
                        if(eps==1) { // if $ was found
                            k++;
                        }
                        else{
                            break;
                        }

                    }
                }
                if(k==strlen(p[i])&&p[i][0]!=c) { // if k exceeded the length of p[i] (find fol(p[i][0]))
                    fol(p[i][0]);
                }
            }
        }
    }
}

int inc(char c) {
    for(int i=0;i<nf;i++) {
        if(first[i]==c)
            return 1;
    }
    return 0;
}
int incfl(char c) {
    for(int i=0;i<nfl;i++) {
        if(follow[i]==c)
            return 1;
    }
    return 0;
}


// Enter no. of productions: 3
// Enter Expressions:
// E=TR
// R=+TR
// R=$