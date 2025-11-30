// First

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char p[10][10], first[10];
int n=0, nf=0;

int inc(char c); // checks if charecter c is already included. 
void fir(char c);

void main() {
    int choice=0;
    char c,ch;
    printf("Enter the number of productions: ");
    scanf("%d",&n);

    printf("Enter productions (epsilon->$):\n");
    for(int i=0;i<n;i++)
        scanf("%s",p[i]);

    printf("Enter char: ");
    scanf(" %c", &c); // important to leave space (reason below)

    do {
        nf=0;
        fir(c);
        printf("first(%c)={",c);
        for(int i=0;i<nf;i++) {
            if(i!=nf-1)
                printf("%c, ",first[i]);
            else
                printf("%c}",first[i]);
        }
        printf("\nEnter 1 to continue: ");
        scanf("%d",&choice);
        if(choice==1) {
            printf("Enter next character: ");
            scanf(" %c",&c); // important to leave space (reason below)
        }
    } while(choice==1);
}

void fir(char c) {
    if(!isupper(c)) // if the charater is a terminal the add itself to first[].
        if(!inc(c))
            first[nf++]=c;

    for(int i=0;i<n;i++) {
        if(p[i][0]==c) {
            if(p[i][2]=='$') { // if RHS is epsilon
                if(!inc(p[i][2]))
                    first[nf++]=p[i][2];
            }
            else if(!isupper(p[i][2])) { // if RHS is a terminal (like a b c etc) or a symbol (like + *)
                if(!inc(p[i][2])) {
                    first[nf++]=p[i][2];
                }
            }
            else { // if RHS is a non terminal
                fir(p[i][2]);
            }
        }
    }
}

int inc(char c) {
    for(int i=0;i<nf;i++) {
        if(c==first[i])
            return 1;
    }
    return 0;
}


// ⚙️ Why we use a space before %c:
//
// When we mix scanf calls like %d or %s with %c, 
// a leftover newline '\n' or space remains in the input buffer 
// after pressing Enter for the previous input.
//
// For example:
//   scanf("%d", &x);   // reads only the number, leaves '\n' in buffer when enter is pressed
//   scanf("%c", &ch);  // reads that leftover '\n' immediately instead of reading the actual character (since appearing after \n)
//
// Writing " %c" (with a space) tells scanf to ignore any whitespace 
// (spaces, tabs, newlines) before reading the next visible character.
//
// 🧠 This issue mainly occurs when mixing %d, %f, %s with %c,
// because those format specifiers skip whitespace automatically.
// But %c does NOT skip whitespace — it reads everything literally, including '\n'.
// When using only %d or only %s repeatedly, this problem doesn’t occur.


// Safe habit: Use " %c" by default (always) unless you specifically need to capture whitespace characters.