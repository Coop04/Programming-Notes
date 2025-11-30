#include<stdio.h>
#include<string.h>
#include<ctype.h>

char p[10][10], first[10];
int n = 0, nf = 0;

int inc(char c) {
    for(int z = 0; z < n; z++)
        if(c == first[z])
            return 1;
    return 0;
}

void fir(char c) {
    if(!isupper(c))
        first[n++] = c;

    for(int i = 0; i < nf; i++) {
        if(p[i][0] == c) {
            if(p[i][2] == '$')
                first[n++] = '$';
            else if(islower(p[i][2]))
                first[n++] = p[i][2];
            else
                fir(p[i][2]);
        }
    }
}

void main() {
    char c;
    char ch;
    printf("Enter no of productions:\n");
    scanf("%d", &nf);

    printf("Enter productions (epsilon=$)\n");
    for(int i = 0; i < nf; i++)
        scanf("%s%c", p[i], &ch);

    int choice = 0;
    printf("Enter char :\n");
    scanf("%c", &c);

    do {
        n = 0;
        fir(c);

        printf("first(%c)={", c);
        for(int i = 0; i < n; i++) {
            if(i != n - 1)
                printf("%c, ", first[i]);
            else
                printf("%c }", first[i]);
        }

        printf("do you want to continue(press 1) and enter next char\n");
        scanf("%d%c", &choice, &c);

    } while(choice == 1);
}
