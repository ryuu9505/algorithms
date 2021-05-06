/*
타일링 문제
*/
#include <iostream>
#define MAX_SIZE 1000001
using namespace std;

int dp[MAX_SIZE];

// by 1x2, 2x1
int tile(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (dp[n] != 0) return dp[n]; 
    return dp[n] = (tile(n - 1) + tile(n - 2)) % 10007;
}

// by 1x2, 2x1, 2x2
int tile(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (dp[n] != 0) return dp[n]; 
    return dp[n] = (tile(n - 1) + 2 * tile(n - 2)) % 10007;
}

// by 
int tile(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 3;
    if (dp[n] != 0) return dp[n]; 
    int result = 3 * tile(n - 2);
    for (int i = 4; i <= n; i += 2)
    {
        result += 2 * tile(n - i);
    }
    return dp[n] = result;
}

int main()
{
    int n;
    cin >> n;
    cout << dp_tile(n) << endl;
    return 0;
}