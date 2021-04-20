#ifndef MATH_H
#define MATH_H

// sum of 1~n
int recursiveSum(int n)
{
    if (n == 1) return 1;
    return n + recursiveSum(n-1);
}

int sum(int n)
{
    int sum = 0;
    for (int i = 1 ; i <= n; i++)
        sum += i;
}
#endif