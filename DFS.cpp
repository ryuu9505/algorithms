#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

int n, m;
vector<int> arr[MAX_SIZE]; // 각각의 벡터(노드)에 연결된 (최대 2개의) 노드 정보를 넣기 위해 벡터 배열을 선언
bool visited[MAX_SIZE]; // index 노드의 탐색을 기록

// 재귀
void DFS(int index)
{
    visited[index] = true; // 방문 기록
    printf("%d ", index);
        
    for (int i = 0; i < arr[index].size(); i++)
    {
        int next = arr[index][i]; // 연결된 노드들

        if (!visited[next]) // 해당 연결된 노드에 방문하지 않았다면
            DFS(next);
    }
}

int main()
{


    return 0;
}