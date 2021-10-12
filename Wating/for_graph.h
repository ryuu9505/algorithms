#ifndef _FOR_GRAPH_H
#define _FOR_GRAPH_H

#include <algorithm>
#include <queue>
#include <string> 
#include <vector>
#include "union_find.h"
#define MAX_N 25 
#define INF 2147483647 

struct Edge
{
	int u, v, weight;
};

int getMinimumVertex(bool visited[]);
void Dijkstra(int start);
void FloydWarshall();
int Kruskal();
int prim();

#endif
