/*
2차원 영역을 탐색하며
값에 따라 구분되어있는 각각의 영역들을 
*/
#include <vector>
using namespace std;


vector<vector<int>> Board;  // inactive = 0, active = 1
int M, N;  // max of row and col
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};  // U, D, L, R
bool Visited[100][100] = {false,};

int DFS(int x, int y)
{
    if (x < 0 || x >= M || y < 0 || y >= N || Board[x][y] != 1)
        return 0;   
    
    // visited
    Visited[x][y] = true;

    //
    int num = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        num += DFS(nx, ny);
    }

    return num;
}
int main()
{



}

// 
// inactive = 0, active = 1~
int DFS(int x, int y, int area)
{
    if (x < 0 || x >= M || y < 0 || y >= N || Board[x][y] != area)
        return 0;   
    
    Board[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        area += DFS(nx, ny, pic);
    }
    return area;
}


