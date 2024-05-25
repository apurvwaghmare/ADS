// PRIMS ADJACCENCY 
// matrix


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

int minkey(int key[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void prims(int graph[][V]) {
    int visited[V], key[V], parent[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0; // Consider 0th vertex first
    parent[0] = -1; // Set parent of 0th vertex to -1

    for (int i = 0; i < V - 1; i++) {
        int u = minkey(key, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prims(graph);
    return 0;
}

/*

999 2 2 4 999
2 999 999 3 999
2 999 999 9 1 
4 3 9 999 6 
999 999 1 6 999


Iteration 1:

Pick vertex 0.
Update key values and parent pointers of adjacent vertices.
key[] = {0, 2, 2, 4, 999}
parent[] = {-1, 0, 0, 0, -1}
Iteration 2:

Pick vertex 1 (with the minimum key).
Update key values and parent pointers of adjacent vertices.
key[] = {0, 2, 2, 3, 999}
parent[] = {-1, 0, 0, 1, -1}
Iteration 3:

Pick vertex 2 (with the minimum key).
Update key values and parent pointers of adjacent vertices.
key[] = {0, 2, 2, 3, 1}
parent[] = {-1, 2, 0, 1, -1}
Iteration 4:

Pick vertex 3 (with the minimum key).
Update key values and parent pointers of adjacent vertices.
key[] = {0, 2, 2, 3, 1}
parent[] = {3, 2, 0, 1, -1}
Iteration 5:

All vertices are visited. The algorithm terminates.

*/


// PRIMS ADJACENCY LIST 

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #include <stdbool.h>

// #define I 999

// struct Edge {
//     int weight;
//     int vertex;
//     struct Edge* next;
// };

// struct Vertex {
//     struct Edge* head;
// };

// struct Graph {
//     int num_vertex;
//     struct Vertex* array;
// };

// // Function to create an edge
// struct Edge* createEdge(int vertex, int weight) {
//     struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
//     newEdge->vertex = vertex;
//     newEdge->weight = weight;
//     newEdge->next = NULL;
//     return newEdge;
// }

// // Function to create the graph
// struct Graph* createGraph(int vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->num_vertex = vertices;
//     graph->array = (struct Vertex*)malloc(vertices * sizeof(struct Vertex));
//     for (int i = 0; i < vertices; i++) {
//         graph->array[i].head = NULL;
//     }
//     return graph;
// }

// // Function to add an edge to the graph
// void addEdge(struct Graph* graph, int src, int dest, int weight) {
//     struct Edge* newEdge = createEdge(dest, weight);
//     newEdge->next = graph->array[src].head;
//     graph->array[src].head = newEdge;

//     newEdge = createEdge(src, weight);
//     newEdge->next = graph->array[dest].head;
//     graph->array[dest].head = newEdge;
// }

// // Function to find the Minimum Spanning Tree (MST) using Prim's algorithm
// void primMST(struct Graph* graph) {
//     int vertices = graph->num_vertex;
//     int parent[vertices];
//     int key[vertices];
//     bool mst[vertices];
//     for (int i = 0; i < vertices; i++) {
//         key[i] = INT_MAX;
//         mst[i] = false;
//     }
//     key[0] = 0;
//     parent[0] = -1;
//     int count;
//     for (count = 0; count < vertices - 1; count++) {
//         int u;
//         int minKey = I;
//         for (int v = 0; v < vertices; v++) {
//             if (mst[v] == false && key[v] < minKey) {
//                 minKey = key[v];
//                 u = v;
//             }
//         }
//         mst[u] = true;
//         struct Edge* current = graph->array[u].head;
//         while (current) {
//             int v = current->vertex;
//             int weight = current->weight;
//             if (mst[v] == false && weight < key[v]) {
//                 parent[v] = u;
//                 key[v] = weight;
//             }
//             current = current->next;
//         }
//     }
//     for (int i = 1; i < vertices; i++) {
//         printf("%d -> %d (weight: %d)\n", parent[i], i, key[i]);
//     }
// }

// int main() {
//     int numVertices = 5;

//     struct Graph* graph = createGraph(numVertices);

//     int cost[][5] = {
//         {I, 5, I, I, 4},
//         {5, I, 6, 3, 1},
//         {I, 6, I, 8, I},
//         {I, 3, 8, I, 2},
//         {4, 1, I, 2, I},
//     };

//     for (int i = 0; i < numVertices; i++) {
//         for (int j = i; j < numVertices; j++) {
//             if (cost[i][j] != I) {
//                 addEdge(graph, i, j, cost[i][j]);
//             }
//         }
//     }

//     printf("Minimum Spanning Tree (Prim's algorithm):\n");
//     primMST(graph);

//     return 0;
// }

/*

Initialization:

Start with an empty MST.
Choose an arbitrary starting vertex to begin the MST construction.
Initialize an array key[] to store the minimum weight of edges connecting vertices to the MST. Initialize all keys to infinity, except the key of the starting vertex, which is set to 0.
Initialize an array parent[] to store the parent (predecessor) of each vertex in the MST. Initialize all parents to -1.
Initialize a boolean array mstSet[] to keep track of vertices included in the MST. Initialize all values to false.
MST Construction:

Repeat the following steps until all vertices are included in the MST:
Select the vertex u that is not yet in the MST and has the minimum key value. Initially, this will be the starting vertex.
Include vertex u in the MST (mstSet[u] = true).
Update the key values and parent pointers of all adjacent vertices of u that are not yet included in the MST:
For each adjacent vertex v, if v is not in the MST (mstSet[v] == false) and the weight of the edge (u, v) is less than key[v], update key[v] to the weight of (u, v) and set parent[v] = u.
Output MST:

Once all vertices are included in the MST, the parent[] array will contain the edges of the MST.
Each edge (parent[v], v) represents an edge in the MST.
Print or process the MST according to the requirements.
Complexity:

The time complexity of Prim's algorithm depends on the data structure used for the key values. When using a binary heap or Fibonacci heap, the time complexity is O(V log V + E), where V is the number of vertices and E is the number of edges.
*/
