#include <iostream>
#include "for_graph.h"

using namespace std; 


void Dijkstra(int start) 
{
    // parameters
    int N;
    int weight[MAX_N][MAX_N];
    int dist[MAX_N];  // minimum distance from start
    int prev[MAX_N];  // prev vertex in shortest path
	bool visited[MAX_N] = { false };  // is the vertex visited in this algorithm?

    // initialize parameters
	for (int i = 0; i < N; ++i)
	{
		prev[i] = -1;
		dist[i] = INF;
        for (int j = 0; j < N; ++j)
            weight[i][j] = INF;
	}

    // assign weights from argument
    /*for (auto elem : vector) ex) 원소가 {정점1, 정점2, 가중치} 인 2차원 벡터
	{
        // 정점 사이에 여러개의 길이 있을 수 있는 경우 최소 가중치의 간선 선택
        if (weight[elem[0]][elem[1]] > elem) 
        {
            weight[elem[0]][elem[1]] = elem[2];
            weight[elem[1]][elem[0]] = elem[2]; // 방향성이 없는 그래프인 경우
        }
	}*/  

    // calculate minimum distance
	dist[start] = 0; 
	for (int i = 0; i < N; ++i)  //[1]
	{
		int min_vertex = getMinimumVertex(visited, dist, N);  //[2]
		visited[min_vertex] = true;

		for (int j = 0; j < N; ++j) 
		{
			if (dist[j] > dist[min_vertex] + weight[min_vertex][j])  // min_vertex를 거쳐서 가는 거리가 더 짧다면 갱신
			{
				prev[j] = min_vertex;  // 각 정점을 도착지로 하는 최단 경로에서의 도착 직전 정점을 기록함으로써 경로를 기억하는 방식
				dist[j] = dist[min_vertex] + weight[min_vertex][j];
			}
		}
	}
}


// get vertex having minimum distance from start
int getMinimumVertex(bool visited[], int dist[], int N)
{
	int min_dist = INF;
	int min_vertex = 0; 
	for (int i = 0; i < N; ++i)  //[1]
	{
		if (!visited[i] && dist[i] < min_dist) 
		{
			min_dist = dist[i];
			min_vertex = i;
		}
	}
	return min_vertex;
}

// 정점에 대한 번호가 0~N-1 이므로 1~N 인 경우 weight로 가중치 정보를 옮길 때 인덱스에 -1을 하고 옮겨야함.

/*
[1] 예외처리
그래프의 정의에 따라 간선이 없는 정점은 없고 모든 정점 사이에는 경로가 존재한다.
다익스트라 알고리즘은 (미방문 최단거리 정점 선택 - 모든 인접 정점까지의 거리와 비교)의 과정이 반복되므로
정점의 개수만큼 반복 수행하면 반드시 전체 과정이 끝나게 된다.
그러므로 별도의 예외 처리는 필요하지 않다.
*/

/*
[2] 최단거리의 정점을 먼저 방문하는 이유  
방문한 정점을 거쳐서 가는 최단 경로를 찾았는데  
이후에 방문한 정점까지의 거리가 최적의 경로가 아니었다면 
그 정점을 거쳐가는 경로들이 다 최적의 경로가 아니게 된다. 
start로부터의 최단 거리인 정점(min_vertex)부터 방문하면  
이후에 start-다른정점-min_vertex 경로가 최단거리가 되어 갱신되는 일은 일어날 수 없다. 
(이미 start-다른정점 이 start-min_vertex보다 멀기 때문에) 
이 규칙을 지키는 가운데 하나 하나 방문하며 각 정점까지의 최단거리를 갱신해 나가면 
시작 정점에서 각 정점으로 가는 최단 경로를 모두 구할 수 있다. 
*/


void FloydWarshall() 
{
    int N;
    int dist[MAX_N][MAX_N];  // minimum distance between two vertice

    // initialize dist[][]    
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            if (i == j) dist[i][j] = 0; 
            else dist[i][j] = INF; 
        } 
    } 

    // assign weights from argument
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
	    { 
            dist[i][j] = /*arg*/;
        } 
    }

    // Floyd-Warshall Algorithm 
    for (int bridge = 0; bridge < N; bridge++) 
    { 
        for (int i = 0; i < N; i++) 
        { 
            for (int j = 0; j < N; j++) 
            {
                //핵심// bridge를 거쳐서 i에서 j로 가는 경로가 존재하고 그 경로가 기존 경로보다 가중치가 작은 경우 
                if (dist[i][bridge] < INF && dist[bridge][j] < INF && dist[i][j] > dist[i][bridge] + dist[bridge][j])  
                { 
                        dist[i][j] = dist[i][bridge] + dist[bridge][j]; // 최소 가중치 갱신
                } 
            } 
        } 
    }

    // Result (return, print ...)
}
// 조건 두 dist 값의 합이 INF를 넘으면 안됨 (Overflow)

bool Compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

int Kruskal()
{
    int N;

	// init edges
	Edge edges[MAX_N * (MAX_N - 1) / 2];
	int edge_cnt;
	/*assign edges and edge_cnt*/ 
	sort(edges, edges+edge_cnt, Compare);

	// init set
	int parent[MAX_N];
	for (int i = 0; i < N; ++i)  // make set 
		parent[i] = i;

	// make MST
	int sum_cost = 0, select_cnt = 0;
	for (int i = 0; i < edge_cnt; ++i)
	{
		// condition
		int u = edges[i].u, v = edges[i].v;
		if (FindSet(u) == FindSet(v)) continue;  //[*] Cycle	
		else parent[FindSet(u)] = FindSet(v);  // Union

		sum_cost += edges[i].weight;

		// terminate
		if (++select_cnt >= N - 1) break;  // number of edges of MST
	}

	return sum_cost;
}

/* Cycle
하나의 간선이 연결하는 두 정점이 동일한 그래프에 속한다는 것은 두 정점이 이미 이어져 있다는 의미이다.
그러므로 간선을 추가하게 되면 사이클이 생긴다.
(두 점 사이에 둘 이상의 경로가 있으면 순환한다.)
*/

int Prim()
{  
    int N, parent[MAX_N];
	int graph[MAX_N][MAX_N]; // actual weight between the two indexies
	int weight[MAX_N]; // weight between the 'first node' and 'index'

	for (int i = 0; i < N; ++i)
		weight[i] = -1; // -1 : It hasn't been checked yet
	     
	weight[0]/*first vertex*/ = 0;
	for (int k = 1; k < N; ++k) // N-1 : number of edges in Spanning Tree
	{
		int min_weight = INF, min_vertex, min_parent;
		for (int i = 0; i < N; ++i) 
		{
			if (weight[i] < 0) continue; // i : node included in the curr tree
			for (int j = 0; j < N; ++j)
			{
				if (weight[j] >= 0) continue; // j : node aren't included in the curr tree
				if (graph[i][j] < min_weight) 
				{
					min_vertex = j;
					min_parent = i;
					min_weight = graph[i][j];
				}
			}
		}
		parent[min_vertex] = min_parent;
		weight[min_vertex] = min_weight;
	}

	int sum_cost = 0;
	for (int i = 0; i < N; ++i) 
		sum_cost += weight[i];

	return sum_cost;
}


// TOP�� �ּ� ���� ���� PQ�� �̿��ؼ� ���� �����ϰ� ���� ����
int prim_pq()
{
    int N, graph[MAX_N][MAX_N];
	bool visited[MAX_N] = { false };
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	visited[0] = true;
	for (int next = 0; next < N; ++next)
		pq.push(make_pair(graph[0][next], next));

	int sum_cost = 0;
	while (!pq.empty())
	{
		int curr = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (visited[curr]) continue;
		visited[curr] = true;
		sum_cost += weight;

		for (int next = 0; next < N; ++next)
			pq.push(make_pair(graph[curr][next], next));
	}

	return sum_cost;
}