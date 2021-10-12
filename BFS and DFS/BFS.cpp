#include <queue>
#include <vector>
#define MAX_SIZE 1000

using namespace std;

vector<int> graph[MAX_SIZE];  // 각각의 벡터(노드)에 연결된 (최대 2개의) 노드 정보를 넣기 위해 벡터 배열을 선언

// by Queue
void BFS(int root)
{
    queue<int> q;
    bool visited[MAX_SIZE] = {false};  // is the node visited?

    q.push(root);  // 탐색 시작 위치를 push
    visited[root] = true;  // 방문 기록

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        //  printf("%d ", curr);  // process the node
        
        for (int i = 0; i < graph[curr].size(); i++)
        {
            int next = graph[curr][i];  // adjacent node

            if (!visited[next])  // add necessary conditions
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}