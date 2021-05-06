/*
미로 탈출
https://www.youtube.com/watch?v=7C9RgOcvkvo
*/
#include <iostream>
#include <cstdio>
#include <queue>
#define MAX_SIZE 1001
using namespace std;

int n, m;
int graph[MAX_SIZE][MAX_SIZE];
// Direction (R, D, L, U)
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // 연결된 노드 검사
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) 
                continue;            
            if (graph[nx][ny] == 0)
                continue;
            if (graph[nx][ny] == 1)
            {
                graph[nx][ny] = graph[x][y] + 1;
                q.push([nx][ny]);
            }
        }
    }
}