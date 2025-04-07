#include<stdio.h>
#define MAX 1000

void main() {
    int i,j,n,adj[20][20],src;

    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    printf("Enter the cost to each node\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(i==j) {
                adj[i][j]=0;
            }
            else {
                printf("Enter the cost from %d to %d: ",i,j);
                scanf("%d",&adj[i][j]);
            }
        }
    }

    int dist[n],visited[n],nxthop[n];

    for(i=0;i<n;i++) {
        dist[i]=MAX;
        visited[i]=0;
        nxthop[i]=0;
    }
    
    printf("\nEnter the source node: ");
    scanf("%d",&src);
    dist[src]=0;


    for(int round=0;round<n-1;round++) {
        int min=MAX, min_index;

        for(int v=0;v<n;v++) {
            if(!visited[v] && dist[v]<min) {
                min = dist[v];
                min_index = v;
            }
        }
        visited[min_index]=1;

        for(int d=0;d<n;d++) {
            if(!visited[d] &&
                dist[min_index]!=MAX &&
                adj[min_index][d] &&
                adj[min_index][d]+dist[min_index]<dist[d]) {
                    dist[d] = adj[min_index][d]+dist[min_index];
                    if(min_index!=src) {
                        nxthop[d] = min_index+1;
                    }
            } 
        }

        if(min_index==src) {
            printf("\nRounting table of %d\n",src);
            printf("Destination\tCost\tNext Hop\n");
            for(i=0;i<n;i++) {
                if(dist[i]==0) {
                    printf("%d\t\t-\t-\n",i);
                }
                else {
                    printf("%d\t\t%d\t-\n",i,dist[i]);
                }
            }
        }
    }
    printf("After applying dijkstra's algorithm\n");
    printf("Routong table of %d\n",src);
    printf("Destination\tCost\tNext Hop\n");
    for(i=0;i<n;i++) {
        printf("%d\t\t%d\t",i,dist[i]);
        if(nxthop[i]==0) {
            printf("-\n");
        }
        else {
            printf("%d\n",nxthop[i]);
        }
    }

    for(i=0;i<n;i++) {
        printf("Distance from %d -> %d: %d\n",src,i,dist[i]);
    }

}