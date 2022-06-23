#pragma once
#include<iostream>

int least_road_sum();

// a structure to represent a weighted edge in graph 
class Edge
{
public:
	int src, dest, weight;
};

// a structure to represent a connected, undirected 
// and weighted graph 
class Graph
{
public:
	// V-> Number of vertices, E-> Number of edges 
	int V, E;

	// graph is represented as an array of edges. 
	// Since the graph is undirected, the edge 
	// from src to dest is also edge from dest 
	// to src. Both are counted as 1 edge here. 
	Edge* edge;
};
class subset
{
public:
	int parent;
	int rank;
};
int myComp(const void* a, const void* b);
void KruskalMST(Graph* graph);
void Union(subset subsets[], int x, int y);
int find(subset subsets[], int i);
int Minimum_Spanning_Tree_main();