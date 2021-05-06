#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

int n, m, r;
vector<int> arr; // 각각의 벡터(노드)에 연결된 (최대 2개의) 노드 정보를 넣기 위해 벡터 배열을 선언
vector<int> temp;
vector<vector<int>> permutations;
bool visited[MAX_SIZE]; // index 노드의 탐색을 기록

// 재귀
void permutation(int index, int depth)
{
    temp.push_back(arr[index]);
    if (depth == r)
    {
        permutations.push_back(temp);
        return;
    }
        
    for (int i = index + 1; i < arr.size(); i++)
    {
        int next = i;

        if (!visited[next])
            permutation(next, depth + 1);
    }
}

int main()
{
    permutation(0, 0);
    
    for (int i = 0; i < permutations.size(); i++)
    {
        for (int j = 0; j < permutations[i].size(); j++)
        {
            cout << permutations[i][j];
        }
        cout << endl;
    }

    
    return 0;
}