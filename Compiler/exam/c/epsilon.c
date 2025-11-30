#include <stdio.h>
int n, nt;
int ep[10][10];
int vis[10];
void closure(int state) {
vis[state] = 1;
for (int i = 0; i < n; i++) {
if (ep[state][i] == 1 && vis[i] == 0) {
closure(i);
}
}
}
int main() {
int i, j, from, to;
printf("Enter number of states: ");
scanf("%d", &n);
printf("Enter number of epsilon transitions: ");
scanf("%d", &nt);
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
ep[i][j] = 0;
printf("Enter epsilon transitions (from_state to_state):\n");
for (i = 0; i < nt; i++) {
scanf("%d%d", &from, &to);
ep[from][to] = 1;
}
printf("\n--- Epsilon Closures ---\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++)
vis[j] = 0;
closure(i);
printf("E-closure(%d): { ", i);
for (j = 0; j < n; j++) {
if (vis[j] == 1)
printf("%d ", j);
}
printf("}\n");
}
return 0;
}

