// BFS Traversal Adjacency matrix


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int num) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = num;
    }
    else {
        rear++;
        queue[rear] = num;
    }
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    else if (front == rear) {
        int temp = queue[front];
        front = rear = -1;
        return temp;
    }
    else {
        return queue[front++];
    }
}

bool emptyqueue() {
    if (front == -1 && rear == -1) {
        return true;
    }
    else {
        return false;
    }
}

void BFS(int G[10][10], int n) {
    int Visited[n], u, start, i;
    for (i = 0; i < n; i++) {
        Visited[i] = 0;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);
    enqueue(start);
    Visited[start] = 1;

    while (!emptyqueue()) {
        int node = dequeue();
        printf("%d ", node);

        for (int j = 0; j < n; j++) {
            if (G[node][j] == 1 && Visited[j] == 0) {
                enqueue(j);
                Visited[j] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int G[10][10];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    BFS(G, n);

    return 0;
}


/*
5 

1 1 1 0 0 
1 1 1 1 1
1 1 1 0 1
0 1 0 1 1
0 0 1 1 1

*/



// BFS ADJACCENCY LIST



// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// struct Node {
//     int vertex;
//     struct Node* next;
// };

// struct Graph {
//     int numVertices;
//     struct Node** adjLists;
// };

// struct Node* createNode(int v) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }

// struct Graph* createGraph(int vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->numVertices = vertices;

//     graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

//     for (int i = 0; i < vertices; i++) {
//         graph->adjLists[i] = NULL;
//     }

//     return graph;
// }

// void addEdge(struct Graph* graph, int src, int dest) {
//     struct Node* newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;

//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }

// void BFS(struct Graph* graph, int start) {
//     bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
//     for (int i = 0; i < graph->numVertices; i++) {
//         visited[i] = false;
//     }

//     int queue[graph->numVertices];
//     int front = 0, rear = 0;

//     queue[rear++] = start;
//     visited[start] = true;

//     while (front < rear) {
//         int vertex = queue[front++];
//         printf("%d ", vertex);

//         struct Node* temp = graph->adjLists[vertex];
//         while (temp != NULL) {
//             int adjVertex = temp->vertex;
//             if (!visited[adjVertex]) {
//                 queue[rear++] = adjVertex;
//                 visited[adjVertex] = true;
//             }
//             temp = temp->next;
//         }
//     }

//     free(visited);
// }

// int main() {
//     int n;
//     printf("Enter the number of vertices: ");
//     scanf("%d", &n);

//     struct Graph* graph = createGraph(n);

//     printf("Enter the number of edges: \n");
//     int edges;
//     scanf("%d", &edges);

//     printf("Enter the source and destination: \n");
//     for (int i = 0; i < edges; i++) {
//         int src, dest;
//         scanf("%d %d", &src, &dest);
//         addEdge(graph, src, dest);
//     }

//     int start;
//     printf("Enter start vertex for BFS: ");
//     scanf("%d", &start);

//     printf("BFS Traversal: ");
//     BFS(graph, start);
//     printf("\n");

//     return 0;
// }

/* INPUT
5
6
0 1
1 3
3 4
4 2
2 1
2 0
*/

/*
Logic:

We create a new node for the destination vertex (dest) using the createNode() function.
Then, we insert this new node at the beginning of the adjacency list of the source vertex (src). This ensures constant-time insertion.
Since the graph is undirected, we repeat the above steps to add an edge from dest to src as well.
Pseudo-code:

c
Copy code
create a new node with destination vertex 'dest'
insert the new node at the beginning of the adjacency list of vertex 'src'
create another new node with destination vertex 'src'
insert this new node at the beginning of the adjacency list of vertex 'dest'

Example:
Suppose we want to add an edge from vertex 0 to vertex 1.

We create a new node with destination vertex 1.
We insert this new node at the beginning of the adjacency list of vertex 0.
We create another new node with destination vertex 0.
We insert this new node at the beginning of the adjacency list of vertex 1.

*/
