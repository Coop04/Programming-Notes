#include<stdio.h>
#define size 10

int a[size][3], b[size][3], s[size][3], i = 0, j = 0, k = 0;

// Returns the number of non-zero elements
int countNo(int p[][5], int r, int c) 
{ 
    int n = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (p[i][j] != 0) {
                n++;
            }
        }
    }
    return n;
}

void printmat(int p[][3])
{
    int i, j;
    int n = p[0][2];
    for (i = 0; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}

void SparseAdd()
{
    int i = 1, j = 1, k = 1;
    if (a[0][0] == b[0][0] && a[0][1] == b[0][1]) {
        s[0][0] = a[0][0];
        s[0][1] = a[0][1];
        printf("Matrix 1\n");
        printmat(a);
        printf("Matrix 2\n");
        printmat(b);
        while (i <= a[0][2] && j <= b[0][2]) {
            if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) // both row & column same
            {
                s[k][0] = a[i][0];
                s[k][1] = a[i][1];
                s[k][2] = a[i][2] + b[j][2];
                i++, j++, k++;
            }
            else if (a[i][0] == b[j][0]) // row same, column different
            {
                if (a[i][1] < b[j][1]) // a smaller
                {
                    s[k][0] = a[i][0];
                    s[k][1] = a[i][1];
                    s[k][2] = a[i][2];
                    i++, k++;
                }
                else // b smaller
                {
                    s[k][0] = b[j][0];
                    s[k][1] = b[j][1];
                    s[k][2] = b[j][2];
                    j++, k++;
                }
            }
            else // row different
            {
                if (a[i][0] < b[j][0]) // a smaller
                {
                    s[k][0] = a[i][0];
                    s[k][1] = a[i][1];
                    s[k][2] = a[i][2];
                    i++, k++;
                }
                else // b smaller
                {
                    s[k][0] = b[j][0];
                    s[k][1] = b[j][1];
                    s[k][2] = b[j][2];
                    j++, k++;
                }
            }
        }
        s[0][2] = k - 1;
        printf("Resultant Matrix\n");
        printmat(s);
    }
    else
        printf("Matrix Addition not Possible!");
}

void MATRIX(int q[][5], int r, int c)
{
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d\t", q[i][j]);
        printf("\n");
    }
}

void main()
{
    int s1[5][5], s2[5][5];
    int i, j, k, r, c, m, n;
    int n1, n2;
    printf("Enter the order of matrix 1:\n");
    scanf("%d%d", &r, &c);
    printf("Enter matrix 1:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &s1[i][j]);
        }
    }
    printf("Enter the order of matrix 2:");
    scanf("%d%d", &m, &n);
    printf("Enter matrix 2:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &s2[i][j]);
        }
    }
    printf("Matrix 1:\n");
    MATRIX(s1, r, c);
    printf("Matrix 2:\n");
    MATRIX(s2, m, n);
    n1 = countNo(s1, r, c);
    n2 = countNo(s2, m, n);
    // Converting s1 to tuple form & store in a
    a[0][0] = r, a[0][1] = c, a[0][2] = n1, k = 1;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (s1[i][j] != 0) {
                a[k][0] = i;
                a[k][1] = j;
                a[k][2] = s1[i][j];
                k++;
            }
        }
    }
    // Converting s2 to tuple form & store in b
    b[0][0] = m, b[0][1] = n, b[0][2] = n2, k = 1;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (s2[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = s2[i][j];
                k++;
            }
        }
    }
    SparseAdd();
}
