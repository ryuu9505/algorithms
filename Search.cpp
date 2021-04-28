#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

int n, m;
vector<int> v[MAX_SIZE]; // 각각의 벡터(노드)에 연결된 (최대 2개의) 노드 정보를 넣기 위해 벡터 배열을 선언
bool check_dfs[MAX_SIZE]; // index 노드의 탐색을 기록
bool check_bfs[MAX_SIZE]; // index 노드의 탐색을 기록

void DFS(int index)
{
    check_dfs[index] = true; // 방문 기록
    printf("%d ", index);
        
    for (int i = 0; i < v[index].size(); i++)
    {
        int next = v[index][i]; // 연결된 노드들

        if (!check_dfs[next]) // 해당 연결된 노드에 방문하지 않았다면
            DFS(next);
    }

}

void BFS()
{
    queue<int> q; // 

    q.push(0); // 탐색 시작 위치(root)를 push
    check_bfs[0] = true; // 방문 기록

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        printf("%d ", current);
        
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i]; // 연결된 노드들

            if (!check_bfs[next]) // 해당 연결된 노드에 방문하지 않았다면
            {
                check_bfs[next] = true; // 방문 기록
                q.push(next); // push
            }
        }
    }
}



int main()
{


    return 0;
}