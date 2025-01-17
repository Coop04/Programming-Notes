#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node *link;
};

struct Graph {
    int numberOfvertices;
    struct Node **adjLists;
}*graph;


struct Q{
    int info;
    struct Q *link;
}*front = NULL,*rear = NULL;

void createGraph(int vertices){
    graph = malloc(sizeof(struct Graph));
    graph->numberOfvertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for(int i = 0; i < vertices; i++){
        graph->adjLists[i] = NULL;
    }
}

void addEdge(int src, int dest) {
    
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->link = NULL;
    newNode->vertex = dest;
    newNode->link = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->link = NULL;
    newNode->vertex = src;

    newNode->link = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}




void enqueue(struct Node **queue, int vertex) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->link = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else {
        struct Node *last = *queue;
        while (last->link != NULL) {
            last = last->link;
        }
        last->link = newNode;
    }
}

void BFS(int start) {
    bool *visited = malloc(graph->numberOfvertices * sizeof(bool));

    for (int i = 0; i < graph->numberOfvertices; i++) {
        visited[i] = false;
    }

    struct Node *queue = NULL;

    visited[start] = true;
    printf("%d ", start);
    enqueue(&queue, start);

    while (queue != NULL) {
        struct Node *current = queue;
        queue = queue->link;

        int vertex = current->vertex;
        struct Node *temp = graph->adjLists[vertex];

        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                printf("%d ", temp->vertex);
                visited[temp->vertex] = true;
                enqueue(&queue, temp->vertex);
            }
            temp = temp->link;
        }
        free(current);
    }
    free(visited);
}

void DFS(int start, bool *visited){
    

    visited[start] = true;
    printf("%d ",start);

    struct Node *temp = graph->adjLists[start];

    while(temp != NULL){
        if(!visited[temp->vertex]){
            
            visited[temp->vertex] = true;
            DFS(temp->vertex,visited);
        }
        temp = temp->link;
    }
      
    }




int main(){

    int src,dest,edges,start,size;

    printf("Enter the number of vertices : ");
    scanf("%d",&size);

    createGraph(size);

    printf("Enter number of edges");
    scanf("%d",&edges);

    for(int i = 0; i < edges; i++){
        printf("Enter edge in the format (src destination)");
        scanf("%d %d",&src,&dest);

        addEdge(src,dest);
    }

    printf("Enter startinf destination for traveral");
    scanf("%d",&start);

    printf("BFS traversal: ");
    BFS(start);
    printf("\n");

    bool *visited = malloc(graph->numberOfvertices * sizeof(bool));

    for(int i = 0; i < graph->numberOfvertices; i++){
        visited[i] = false;
    }

    printf("DFS traversal: ");
    DFS(start,visited);
    printf("\n");

    free(visited);

    return 0;
}