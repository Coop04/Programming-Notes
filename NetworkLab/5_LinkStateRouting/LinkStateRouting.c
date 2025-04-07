#include <stdio.h> 
 
#define MAX 1000 
 
void main() { 
    int n, i, j, adj[50][50], d; 
     
    printf("\nEnter the Number of Nodes: "); 
    scanf("%d", &n); 
 
    printf("Enter the cost between Nodes:\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            if (i == j) 
                adj[i][j] = 0; 
            else { 
                printf("Cost from %d -> %d: ", i + 1, j + 1); 
                scanf("%d", &adj[i][j]); 
            } 
        } 
    } 
 
    int dist[n], visited[n],nxhop[n],round, v, src; 
 
    for (i = 0; i < n; i++) { 
        dist[i] = MAX; 
        visited[i] = 0;
        nxhop[i] = 0;
    }  
 
    printf("\nEnter the source Node: "); 
    scanf("%d", &src); 
    src -= 1; 
    dist[src] = 0; 
 
    for (round = 0; round < n - 1; round++) { 
        int min = MAX, min_index; 
 
        for (v = 0; v < n; v++) { 
            if (visited[v] == 0 && dist[v] < min) { 
                min = dist[v]; // in case of source node min becomes 0 (from dist[v] = 0 for src)
                min_index = v; 
            } 
        } 
 
        visited[min_index] = 1; 
 
        for (d = 0; d < n; d++) { 
            if (!visited[d] // means if node not visited
                && adj[min_index][d]  // means if it is an adjacent vertex of min_index
                && dist[min_index] != MAX // means if the distance to min_index is not MAX
                && dist[min_index] + adj[min_index][d] < dist[d]) { // means if the new distance is shorter
                dist[d] = dist[min_index] + adj[min_index][d]; 
                if (min_index != src) 
                    nxhop[d] = min_index + 1; 
            } 
        } 
        // The purpose of this block is to print the routing table for the source node immediately after it is processed. It does not aim to print the distances for all vertices in every iteration.
        if (min_index == src) { 
            printf("\nRouting Table of Node %d", src + 1); 
            printf("\nDestination\tCost\tNext Hop\n"); 
            for (i = 0; i < n; i++) { 
                if (dist[i] == 0) 
                    printf("%d\t\t-\t-\n", i + 1); 
                else 
                    printf("%d\t\t%d\t-\n", i + 1, dist[i]); 
            } 
        } 
    } 
 
    printf("\n"); 
    printf("\nAfter Applying Dijkstra's Algorithm:\n"); 
    printf("\nRouting Table of Node %d", src + 1); 
    printf("\nDestination\tCost\tNext Hop\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d\t\t%d\t\t", i + 1, dist[i]); 
        if (nxhop[i] == 0) 
            printf("-\n"); 
        else 
            printf("%d\n", nxhop[i]); 
    } 
    // prints the cost to each node from source node
    for (i = 1; i < n; i++) 
        printf("The cost of the shortest path from router %d to %d is %d\n", 
               src + 1, i + 1, dist[i]); 
} 


// Sample output

// Enter the Number of Nodes: 3
// Enter the cost between Nodes:
// Cost from 1 -> 2: 1
// Cost from 1 -> 3: 5
// Cost from 2 -> 1: 1
// Cost from 2 -> 3: 2
// Cost from 3 -> 1: 5
// Cost from 3 -> 2: 2

// Enter the source Node: 1

// Routing Table of Node 1
// Destination     Cost    Next Hop
// 1               -       -
// 2               1       -
// 3               5       -


// After Applying Dijkstra's Algorithm:

// Routing Table of Node 1
// Destination     Cost    Next Hop
// 1               0               -
// 2               1               -
// 3               3               2
// The cost of the shortest path from router 1 to 2 is 1
// The cost of the shortest path from router 1 to 3 is 3