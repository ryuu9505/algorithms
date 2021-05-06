/*
음료수 얼려 먹기
https://www.youtube.com/watch?v=7C9RgOcvkvo
*/

#include <iostream>
#include <cstdio>
#define MAX_SIZE 1001
using namespace std;

int n, m;
int graph[MAX_SIZE][MAX_SIZE];

bool dfs(int x, int y)
{
    // out of range 
    // node value is 1
    if (x < 0 || x >= n || y < 0 || y >= n || graph[x][y] == 1)
        return false;

    // node value is 0
    // 1. 해당 노드를 1로 변경 
    // 2. 재귀 호출을 통해 주위 노드를 전부 1로 바꾼 후에 
    // 3. return true to main function
    if (graph[x][y] == 0)
    {
        graph[x][y] = 1;

        // recursive call nodes of other directions
        dfs(x + 1, y    ); // right
        dfs(x    , y + 1); // down
        dfs(x - 1, y    ); // left
        dfs(x    , y - 1); // up
        return true;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &graph[i][j]); // 그래프가 띄어쓰기 없는 문자열로 입력되므로 1개의 문자씩 입력되도록 하는 서식을 사용 
        }
    }

    int result = 0;
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(i, j))
                result++;
        }
    }

    cout << result << endl;
}