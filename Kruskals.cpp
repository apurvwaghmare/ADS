// KRUSKALS ADJACCENCY 
// matrix


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define V 5
//find parent 
int parent[V];
int find(int i){
	while(parent[i]!=i){
		i=parent[i];
	}
	return i;
}
void union1(int i,int j){
	int a=find(i);
	int	b=find(j);
	parent[a]=b;
}
void kruskals(int cost[][V]){
	int mincost=0;
	//initialize the set of disjoint set
	for(int i=0;i<V;i++){
		parent[i]=i;
	}
	//include<minimum weight edges
	int edge_count=0;
	while(edge_count<V-1){
		int min=INT_MAX;
		int a=-1;
		int b=-1;
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(find(i)!=find(j) && cost[i][j] < min){
					min=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
		union1(a,b);
		 printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min);
        mincost+=min;
	}
	printf("\nMin cost = %d \n",mincost);
}
int main(){
	int cost[][V] = {
        { INT_MAX, 2, INT_MAX, 6, INT_MAX },
        { 2, INT_MAX, 3, 8, 5 },
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
        { 6, 8, INT_MAX, INT_MAX, 9 },
        { INT_MAX, 5, 7, 9, INT_MAX },
    };
    kruskals(cost);
}

/*
Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. The minimum spanning tree of a graph is the tree that connects all the vertices together with the minimum possible total edge weight.

Here's a brief overview of how Kruskal's algorithm works:

Sort Edges by Weight: First, all the edges of the graph are sorted in non-decreasing order of their weights.

Initialize: Initialize an empty set to store the edges of the minimum spanning tree.

Iterate Through Edges: Starting with the edge of minimum weight, iterate through the sorted list of edges.

Add Edges: For each edge, if adding it to the set of chosen edges doesn't create a cycle, add it to the set. To check for cycles, a disjoint-set data structure (often implemented using arrays) is used.

Repeat Until Spanning Tree is Formed: Repeat step 4 until there are 
V−1 edges in the set, where V is the number of vertices in the graph. At this point, the set of edges forms a minimum spanning tree.

Output MST: Output the edges of the minimum spanning tree.

*/

// Kruskals Adjacency List 

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #define I 999

// struct Edge {
//     int vertex;
//     int weight;
//     struct Edge* next;
// };

// struct Vertex {
//     struct Edge* head;
// };

// struct Graph {
//     int num_vertex;
//     struct Vertex* array;
// };

// int numvertices = 5;
// int cost[5][5] = {{I, 2, I, 6, I},
// 		 {2,I,3,8,5}, 
// 		 {I,3,I,I,7 },
// 		 {6,8,I,I,9 },
// 		 {I,5,7,9,I}};

// int parent[5];

// struct Edge* createEdge(int vertex, int weight) {
//     struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
//     newEdge->vertex = vertex;
//     newEdge->weight = weight;
//     newEdge->next = NULL;
//     return newEdge;
// }

// struct Graph* createGraph(int vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->num_vertex = vertices;
//     graph->array = (struct Vertex*)malloc(vertices * sizeof(struct Vertex));
//     int i;
//     for (i = 0; i < vertices; i++) {
//         graph->array[i].head = NULL;
//     }
//     return graph;
// }

// void addEdge(struct Graph* graph, int src, int dest, int weight) {
//     struct Edge* newEdge = createEdge(dest, weight);
//     newEdge->next = graph->array[src].head;
//     graph->array[src].head = newEdge;

//     newEdge = createEdge(src, weight);
//     newEdge->next = graph->array[dest].head;
//     graph->array[dest].head = newEdge;
// }

// int findparent(int i) {
//     while (parent[i] != i) {
//         i = parent[i];
//     }
//     return i;
// }

// int unionn(int i, int j) {
//     if (i != j) {
//         parent[j] = i;
//         return 1;
//     }
//     return 0;
// }

// int main() {
//     int n = numvertices;
//     int i, j;
//     struct Graph graph;
//     graph.num_vertex = n;
//     graph.array = (struct Vertex*)malloc(n * sizeof(struct Vertex));

//     for (i = 0; i < n; i++) {
//         graph.array[i].head = NULL;
//     }

//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             if (cost[i][j] != I) {
//                 addEdge(&graph, i, j, cost[i][j]);
//             }
//         }
//     }

//     for (i = 0; i < n; i++) {
//         parent[i] = i;
//     }

//     int ne = 1;
//     int cost1 = 0;
//     while (ne < n) {
//         int min = I, a = -1, b = -1;
//         for (i = 0; i < n; i++) {
//             for (j = 0; j < n; j++) {
//                 if (cost[i][j] < min && findparent(i) != findparent(j)) {
//                     min = cost[i][j];
//                     a = i;
//                     b = j;
//                 }
//             }
//         }

//         int u = findparent(a);
//         int v = findparent(b);

//         if (unionn(u, v) != 0) {
//             printf("%d -> %d\n", a, b);
//             cost1 += min;
//         }

//         cost[a][b] = cost[b][a] = I;
//         ne++;
//     }
//     printf("\nMinimum cost of the tree is %d\n", cost1);

//     return 0;
// }

/*
Kruskal's Algorithm Implementation:

Loop until the number of edges in the minimum spanning tree equals numvertices - 1:
Find the minimum weight edge that does not create a cycle. This is achieved by iterating through the adjacency matrix.
Check if adding the edge creates a cycle using the disjoint-set data structure (findparent and unionn functions).
If the edge does not create a cycle, add it to the minimum spanning tree, update the total cost, and mark the edge as visited by setting its weight to I.
Repeat this process until all vertices are included in the minimum spanning tree.
*/