//DFS Adjacency Matrix



#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE]; // Adjacency matrix
int visited[MAX_SIZE]; // Array to keep track of visited vertices
int numVertices; // Number of vertices in the graph

// Depth First Search function
void DFS(int vertex) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Traverse all the adjacent vertices of the current vertex
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i); // Recursive call for unvisited adjacent vertices
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to store visited information
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth First Search Traversal:\n");
    DFS(startVertex);

    return 0;
}

/*
5
1 1 1 0 0 
1 1 1 1 0
1 1 1 0 1
0 1 0 1 1
0 0 1 1 1 
0 

ans 0 1 2 4 3
*/


// DFS Adjacency list 


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define MAX_SIZE 100

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* adjList[MAX_SIZE];
// int visited[MAX_SIZE];

// void DFS(int vertex) {
//     visited[vertex] = 1;
//     printf("%d ", vertex);

//     struct Node* current = adjList[vertex];
//     while (current != NULL) {
//         int adjVertex = current->data;
//         if (!visited[adjVertex]) {
//             DFS(adjVertex);
//         }
//         current = current->next;
//     }
// }

// void addEdge(int src, int dest) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = dest;
//     newNode->next = NULL;

//     if (adjList[src] == NULL) {
//         adjList[src] = newNode;
//     } else {
//         struct Node* current = adjList[src];
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
// }

// int main() {
//     int numVertices, numEdges;
//     printf("Enter the number of vertices: ");
//     scanf("%d", &numVertices);

//     printf("Enter the number of edges: ");
//     scanf("%d", &numEdges);

//     for (int i = 0; i < MAX_SIZE; i++) {
//         adjList[i] = NULL;
//         visited[i] = 0;
//     }

//     printf("Enter edges (source destination):\n");
//     for (int i = 0; i < numEdges; i++) {
//         int src, dest;
//         scanf("%d %d", &src, &dest);
//         addEdge(src, dest);
//     }

//     int startVertex;
//     printf("Enter the starting vertex for DFS: ");
//     scanf("%d", &startVertex);

//     printf("Depth First Search Traversal:\n");
//     DFS(startVertex);

//     return 0;
// }

/*

5
6 
0 1 
1 3 
3 4 
4 2 
2 1 
2 0

0 

*/ 

/*
Initialize the adjacency list:

Initialize an array of pointers to struct Node to represent the adjacency list.
Initialize an array to keep track of visited vertices.
Add edges to the adjacency list:

For each edge (u, v), create a new node with data v and add it to the adjacency list of u.
DFS traversal:

Start DFS from a given starting vertex.
Mark the starting vertex as visited and print it.
Traverse the adjacency list of the current vertex:
For each adjacent vertex (v) that has not been visited, recursively call DFS on that vertex.
*/