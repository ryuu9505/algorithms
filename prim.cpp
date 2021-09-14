#include <iostream>
#include <queue>
#define MAX_N 25
#define INF 2100000000

using namespace std;

int N, weight[MAX_N][MAX_N], parent[MAX_N], weight[MAX_N];
int prim()
{  
	for (int i = 0; i < N; ++i)
		weight[i] = -1;
	     
	weight[0] = 0;
	for (int i = 1; i < N; ++i) // N-1�� �ݺ�
	{
		int min_weight = INF, min_vertex, min_parent;
		for (int p = 0; p < N; ++p) // �̹� ���õ� ������ (�κ� �׷����� ���Ե� ������)
		{
			if (weight[p] < 0) continue; 
			for (int q = 0; q < N; ++q) // ���� ���õ��� ���� ������ (�κ� �׷����� ������ ������)
			{
				if (weight[q] >= 0) continue; 
				if (weight[p][q] < min_weight) // �ּ� ����ġ Ž��
				{
					min_vertex = q;
					min_parent = p;
					min_weight = weight[p][q];
				}
			}
		}
		parent[min_vertex] = min_parent;
		weight[min_vertex] = min_weight;
	}
	int sum_cost = 0;
	for (int i = 0; i < N; ++i) sum_cost += weight[i];
	return sum_cost;
}


int main()
{


}