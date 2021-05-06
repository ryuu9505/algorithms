/*
    fibonacci series
    1. recursive function
    2. dynamic programming (top-down)
    3. dynamic programming (bottom-up)
*/
#include <iostream>
#define MAX_SIZE 100
using namespace std;

int recursive_fibonacci(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
} // T_n = O(2^n)

int m[MAX_SIZE];
int dp_fibonacci(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (m[n] != 0) return m[n]; 
    return m[n] = dp_fibonacci(n - 1) + dp_fibonacci(n - 2); // memoizing nth pibonacci number
} // T_n = O(n)

// return m[3] = dp_fibonacci(2) + dp_fibonacci(1); 에 도달하고 
// 빠져나오면서 만나는 dp_fibonacci(n - 2)는 
// 이미 dp_fibonacci(n - 1)을 계산하기 위해 memoized 상태 

long long d[MAX_SIZE];

int main()
{
    // recursive
    cout << recursive_fibonacci(10) << endl;

    // dp (top-down)
    cout << dp_fibonacci(10) << endl; 
   
    // dp (bottom-up)
    int n = 10;
    d[1] = 1; // bottom
    d[2] = 1; // bottom
    for (int i = 3; i <= n; i++)
        d[i] = d[i-1] + d[i-2];
    cout << d[n] << endl;
    
    return 0;
}



int main()
{

}