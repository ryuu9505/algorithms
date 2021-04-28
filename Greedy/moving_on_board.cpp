/*
2차원 이동 유형
*/
#include <iostream>
#include <stdio.h>
#include <string>
#define MAX_SIZE 100
using namespace std;

// Direction (R, D, L, U)
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
char direction[4] = {'R', 'D', 'L', 'U'};
string moves;

int main()
{
    int n, move[MAX_SIZE];
    int x = 1, y = 1;
    int next_x = -1, next_y = -1;
    
    cin >> n;
    cin.ignore(); // buffer 비우기
    getline(cin, moves); // 띄어쓰기로 구분 된 문자(이동 계획)을 하나씩 확인

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (moves == direction[j])
            {
                next_x = x + dx[j];
                next_y = y + dy[j];
            }
        }

        if (next_x < 1 || next_y < 1 || next_x > n || next_y > n) 
            continue;

        x = next_x;
        y = next_y;    
    }
}