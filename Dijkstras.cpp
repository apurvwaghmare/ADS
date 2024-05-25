//Dijkstras

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <stdbool.h>

#define V 9
int min(int dist[],bool sptset[]){
	int min=INT_MAX;
	int index;
	for(int i=0;i<V;i++){
		if(sptset[i]==false && dist[i] <= min){
			min=dist[i];
			index=i;
		}
	}
	return index;
}
void print(int parent[]){
	printf("Vertex \t dist from src\n");
	
	for(int i=0;i<V;i++){
		printf("%d \t\t%d\n",i,parent[i]);	
	}
}
void dij(int graph[][V],int src){
	int dist[V];
	bool sptset[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		sptset[i]=false;
	}
	dist[0]=0;
	int count=0;
	for(count=0;count<V-1;count++){
		int u=min(dist,sptset);
		sptset[u]=true;
		for(int v=0;v<V;v++){
			if(graph[u][v] && !sptset[v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] <dist[v]){
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	print(dist);
}
int main(){
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dij(graph,0);
}

/*
Given a weighted graph and a source vertex in the graph, find the shortest paths from the source to all the other vertices in the given graph.

Note: The given graph does not contain any negative edge.


The provided code implements Dijkstra's algorithm to find the shortest paths from a given source vertex to all other vertices in a weighted graph. Let's break down the logic and sequence of execution:

Function Definitions:

min(int dist[], bool sptset[]): Finds the vertex with the minimum distance value from the source vertex among the vertices not yet included in the shortest path tree (SPT). It returns the index of that vertex.
print(int parent[]): Prints the shortest distances of vertices from the source vertex.
dij(int graph[][V], int src): Performs Dijkstra's algorithm to find the shortest paths.
Initialization:

Initialize arrays dist[] and sptset[]. dist[] holds the shortest distance from the source vertex to each vertex, initialized to INT_MAX (infinity), and sptset[] is a boolean array indicating whether a vertex is included in the shortest path tree, initialized to false.
Set the distance of the source vertex (src) to itself as 0.
Main Loop:

The loop runs V-1 times, where V is the number of vertices in the graph. In each iteration, one vertex is added to the shortest path tree.
Selecting Vertex:

Find the vertex u with the minimum distance value among the vertices not yet included in the shortest path tree (sptset[] is false).
Updating Distances:

For each vertex v adjacent to u, if it is not already in the shortest path tree (sptset[v] is false) and if there is a shorter path from src to v through u, update the distance of v as dist[v] = dist[u] + graph[u][v].
Printing Results:

After the loop, print the shortest distances of vertices from the source vertex (src) using the print() function.
Main Function:

Initialize the weighted graph represented by an adjacency matrix.
Call dij() function with the graph and the source vertex (src) as arguments to find the shortest paths from the source vertex to all other vertices.
*/


// Adjacency List 

// #include<stdio.h>
// #include<stdlib.h>
// #include<limits.h>
// #include <stdbool.h>

// #define V 9

// // Structure to represent an edge in the graph
// struct Edge {
//     int dest;
//     int weight;
//     struct Edge* next;
// };

// // Structure to represent a vertex in the graph
// struct Vertex {
//     struct Edge* head;
// };

// // Structure to represent the entire graph
// struct Graph {
//     int num_vertices;
//     struct Vertex* array;
// };

// // Function to create a new edge
// struct Edge* createEdge(int dest, int weight) {
//     struct Edge* new_edge = (struct Edge*)malloc(sizeof(struct Edge));
//     new_edge->dest = dest;
//     new_edge->weight = weight;
//     new_edge->next = NULL;
//     return new_edge;
// }

// // Function to create a graph with a given number of vertices
// struct Graph* createGraph(int num_vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->num_vertices = num_vertices;
//     graph->array = (struct Vertex*)malloc(num_vertices * sizeof(struct Vertex));
//     for (int i = 0; i < num_vertices; ++i)
//         graph->array[i].head = NULL;
//     return graph;
// }

// // Function to add an edge to the graph
// void addEdge(struct Graph* graph, int src, int dest, int weight) {
//     // Add edge from src to dest
//     struct Edge* new_edge = createEdge(dest, weight);
//     new_edge->next = graph->array[src].head;
//     graph->array[src].head = new_edge;

//     // Add edge from dest to src (if the graph is undirected)
//     // new_edge = createEdge(src, weight);
//     // new_edge->next = graph->array[dest].head;
//     // graph->array[dest].head = new_edge;
// }

// // Function to find the vertex with the minimum distance value
// int minDistance(int dist[], bool spt_set[]) {
//     int min = INT_MAX, min_index;
//     for (int v = 0; v < V; v++)
//         if (spt_set[v] == false && dist[v] <= min)
//             min = dist[v], min_index = v;
//     return min_index;
// }

// // Function to print the distances from the source vertex
// void printSolution(int dist[]) {
//     printf("Vertex \t Distance from Source\n");
//     for (int i = 0; i < V; i++)
//         printf("%d \t %d\n", i, dist[i]);
// }

// // Function to implement Dijkstra's algorithm
// void dijkstra(struct Graph* graph, int src) {
//     int dist[V];     // The output array. dist[i] will hold the shortest distance from src to i
//     bool spt_set[V]; // spt_set[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized

//     // Initialize all distances as INFINITE and sptSet[] as false
//     for (int i = 0; i < V; i++) {
//         dist[i] = INT_MAX;
//         spt_set[i] = false;
//     }

//     // Distance of source vertex from itself is always 0
//     dist[src] = 0;

//     // Find shortest path for all vertices
//     for (int count = 0; count < V - 1; count++) {
//         // Pick the minimum distance vertex from the set of vertices not yet processed.
//         // u is always equal to src in the first iteration.
//         int u = minDistance(dist, spt_set);

//         // Mark the picked vertex as processed
//         spt_set[u] = true;

//         // Update dist value of the adjacent vertices of the picked vertex.
//         struct Edge* edge = graph->array[u].head;
//         while (edge != NULL) {
//             int v = edge->dest;

//             // Update dist[v] only if it's not in spt_set, there is an edge from u to v,
//             // and total weight of path from src to v through u is smaller than current value of dist[v]
//             if (!spt_set[v] && edge->weight && dist[u] != INT_MAX && dist[u] + edge->weight < dist[v])
//                 dist[v] = dist[u] + edge->weight;

//             edge = edge->next;
//         }
//     }

//     // Print the constructed distance array
//     printSolution(dist);
// }

// int main() {
//     // Create the graph
//     struct Graph* graph = createGraph(V);

//     // Add edges to the graph
//     addEdge(graph, 0, 1, 4);
//     addEdge(graph, 0, 7, 8);
//     addEdge(graph, 1, 2, 8);
//     addEdge(graph, 1, 7, 11);
//     addEdge(graph, 2, 3, 7);
//     addEdge(graph, 2, 5, 4);
//     addEdge(graph, 2, 8, 2);
//     addEdge(graph, 3, 4, 9);
//     addEdge(graph, 3, 5, 14);
//     addEdge(graph, 4, 5, 10);
//     addEdge(graph, 5, 6, 2);
//     addEdge(graph, 6, 7, 1);
//     addEdge(graph, 6, 8, 6);
//     addEdge(graph, 7, 8, 7);

//     // Run Dijkstra's algorithm from vertex 0
//     dijkstra(graph, 0);

//     return 0;
// }

/*  

Initialization:

Initialize an array dist[] to store the shortest distance from the source vertex to each vertex in the graph. Initialize another boolean array spt_set[] to keep track of vertices included in the shortest path tree (SPT).
Initially, set all distances in dist[] to infinity (INT_MAX) and mark all vertices as not yet processed (set spt_set[] to false).
Start from the Source:

Set the distance of the source vertex (src) to itself as 0. This vertex will be the starting point for finding the shortest paths to other vertices.
Main Loop:

The loop runs V-1 times, where V is the number of vertices in the graph. In each iteration, one vertex is added to the shortest path tree (SPT).
Selecting Vertex:

Find the vertex u with the minimum distance value among the vertices not yet included in the shortest path tree (spt_set[] is false). This step ensures that we select the vertex with the shortest known distance from the source.
Update Distances:

For each vertex v adjacent to u, if v is not already in the shortest path tree (spt_set[v] is false) and if there is a shorter path from the source to v through u, update the distance of v as dist[v] = dist[u] + weight(u, v), where weight(u, v) is the weight of the edge from u to v.
This step ensures that we continually update the shortest distances to all vertices as we expand the shortest path tree.
Mark Vertex as Processed:

Mark the selected vertex u as processed by setting spt_set[u] to true. This ensures that u will not be considered again in subsequent iterations.
Repeat:

Repeat steps 4-6 until all vertices are included in the shortest path tree.
Print Results:

After the loop, print the shortest distances of vertices from the source vertex (src) using the printSolution() function.
The sequence of execution follows these steps to iteratively find the shortest paths from the source vertex to all other vertices in the graph. The algorithm guarantees that after each iteration of the main loop, the shortest path to at least one additional vertex is finalized, ultimately resulting in the shortest paths to all vertices.

*/