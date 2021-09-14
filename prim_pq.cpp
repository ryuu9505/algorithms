#include <iostream>
#include <queue>
#define MAX_N 25

using namespace std;

int N, weight[MAX_N][MAX_N];

// TOP�� �ּ� ���� ���� PQ�� �̿��ؼ� ���� �����ϰ� ���� ����
int prim()
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	bool visited[MAX_N] = { false };
	visited[0] = true;
	for (int next = 0; next < N; ++next)
		pq.push(make_pair(weight[0][next], next));

	int sum_cost;
	while (!pq.empty())
	{
		int curr = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (visited[curr]) continue;
		visited[curr] = true;
		sum_cost += weight;

		for (int next = 0; next < N; ++next)
			pq.push(make_pair(weight[curr][next], next));
	}
	return sum_cost;
}