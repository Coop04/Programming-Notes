#include<stdio.h>
#define MAX 1000

void main() {
    int i,j,n,adj[50][50],round,src;

    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    printf("Enter the cost to each node:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(i==j) {
                adj[i][j]=0;
            }
            else {
                printf("Cost from %d -> %d: ",i,j);
                scanf("%d",&adj[i][j]);
            }
        }
    }

    int dist[n],visited[n],nexthop[n];
    for(i=0;i<n;i++) {
        dist[i]=MAX;
        visited[i]=0;
        nexthop[i]=0;
    }

    printf("Enter the source node: ");
    scanf("%d",&src);
    dist[src]=0;

    for(round=0;round<n-1;round++) {
        int min=MAX,min_index;

        for(int v=0;v<n;v++) {
            if(!visited[v] && dist[v]<min) { // used to find the unvisited node with the smallest distance from the source node
                min=dist[v];
                min_index=v;
            }
        }
        visited[min_index]=1;

        for(int d=0;d<n;d++) {
            if(!visited[d] &&
                dist[min_index]!=MAX &&
                adj[min_index][d] && // means min_index and d are coonected
                adj[min_index][d]+dist[min_index]<dist[d]) {
                    dist[d] = adj[min_index][d]+dist[min_index];
                    if(min_index!=src) {
                        nexthop[d]=min_index+1;
                    }
            }
        }

        if (min_index == src) { 
            printf("\nRouting Table of Node %d", src); 
            printf("\nDestination\tCost\tNext Hop\n"); 
            for (i = 0; i < n; i++) { 
                if (dist[i] == 0) 
                    printf("%d\t\t-\t-\n", i); 
                else 
                    printf("%d\t\t%d\t-\n", i, dist[i]); 
            } 
        } 
    }
    printf("\n"); 
    printf("\nAfter Applying Dijkstra's Algorithm:\n"); 
    printf("\nRouting Table of Node %d", src); 
    printf("\nDestination\tCost\tNext Hop\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d\t\t%d\t\t", i, dist[i]); 
        if (nexthop[i] == 0) 
            printf("-\n"); 
        else 
            printf("%d\n", nexthop[i]); 
    } 
    // prints the cost to each node from source node
    for (i = 1; i < n; i++) 
        printf("The cost of the shortest path from router %d to %d is %d\n", 
               src, i, dist[i]);

}