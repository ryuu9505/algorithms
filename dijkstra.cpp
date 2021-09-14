#include <iostream> 
#define MAX_N 25 
#define INF 2100000000 

using namespace std; 

int N, weight[MAX_N][MAX_N], dist[MAX_N], prev[MAX_N];
// dist: minimum distance from start to vertice
// prev: 최단 경로에서의 이전 정점

void Dijkstra(int start);
int getMinimumVertex(bool visited[]);

void Dijkstra(int start) 
{
	bool visited[MAX_N] = { false };  // is the vertex visited in this algorithm? 
	for (int i = 0; i < N; ++i)
	{
		prev[i] = -1;
		dist[i] = INF;
	}

	dist[start] = 0; 

	for (int i = 0; i < N; ++i)  //[1]
	{
		int min_vertex = getMinimumVertex(visited);
		visited[min_vertex] = true;

		
		for (int j = 0; j < N; ++j) 
		{
            // min_vertex를 거쳐서 가는 거리가 더 짧다면 갱신
			if (dist[j] > dist[min_vertex] + weight[min_vertex][j]) 
			{
				prev[j] = min_vertex;  // 각 정점을 도착지로 하는 최단 경로에서의 도착 직전 정점을 기록함으로써 경로를 기억하는 방식
				dist[j] = dist[min_vertex] + weight[min_vertex][j];
			}
		}
	}
}

// get vertex having minimum distance from start
int getMinimumVertex(bool visited[])
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


/*
[1]
그래프의 정의에 따라 간선이 없는 정점은 없고 모든 정점 사이에는 경로가 존재한다.
다익스트라 알고리즘은 (미방문 최단거리 정점 선택 - 모든 인접 정점까지의 거리와 비교)의 과정이 반복되므로
정점의 개수만큼 반복 수행하면 반드시 전체 과정이 끝나게 된다.
그러므로 별도의 예외 처리는 필요하지 않다.
*/

// start로부터의 거리가 기록된다 
// INF의 거리는 갈 수 없는, 즉 인접하지 않다는 의미이다. 


// min_vertex를 찾아서 방문 
// min_vertex를 거쳐서 갈 때 거리가 더 단축되는 경우 경로를 갱신 (못가던 곳을 갈 수 있게 되는 것도 포함)   

// min_vertex를 먼저 방문하는 이유  
// 방문한 정점을 거쳐서 가는 최단 경로를 찾았는데  
// 이후에 방문한 정점까지의 거리가 최적의 경로가 아니었다면 그 정점을 거쳐가는 경로들이 다 최적의 경로가 아니게 된다. 
// start_vertex로부터의 최단 거리인 정점(min_vertex)부터 방문하면  
// 이후에 start-다른정점-min_vertex 경로가 최단거리가 되어 갱신되는 일은 일어날 수 없다. (이미 start-다른정점 이 start-min_vertex보다 멀기 때문에) 
// 이 규칙을 지키는 가운데 하나 하나 방문하며 각 정점까지의 최단거리를 갱신해 나가면 시작 정점에서 각 정점으로 가는 최단 경로를 모두 구할 수 있다. 