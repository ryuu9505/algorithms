#include <stdio.h>
 
#define MAX_STRING_LENGTH 10
 
int stackTop = 0;
char combinationStack[MAX_STRING_LENGTH];
 
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void permutation(char *str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = l; i <= r; i++) 
        {
            swap((str+l), (str+i));
            permutation(str, l+1, r);
            swap((str+l), (str+i)); //backtrack
        }
    }
}
 
void push(char ch) 
{
    combinationStack[stackTop++] = ch;
    combinationStack[stackTop] = '\0';
}
 
void pop() 
{
    combinationStack[--stackTop] = '\0';
}
 
void combination(const char* str, int length, int offset, int k) 
{
    if (k == 0) 
    {
        printf("%s\n", combinationStack);
        return;
    }
    for (int i = offset; i <= length - k; ++i) 
    {
        push(str[i]);
        combination(str, length, i+1, k-1);
        pop();
    }
}
 
int main()
{
    int N, K, T;
    char str[MAX_STRING_LENGTH];
    scanf("%d", &T);
 
    for (int test_case = 1; test_case <= T; test_case++) 
    {
        scanf("%s%d%d", str, &N, &K);
        str[N] = 0;
        printf("#%d\n", test_case);
 
        permutation(str, 0, N-1);
        combination(str, N, 0, K);
    }
 
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printv(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
}

int main()
{
    vector<int> v, v_temp;

    // 순열 (next_permutation( ) 활용)
    v = { 1, 2, 3 };
    do
    {
        printv(v);
    } while (next_permutation(v.begin(), v.end())); // <algorithm> next_permutation( )
    cout << endl;

    // 순열 (prev_permutation( ) 활용)
    v = { 3, 2, 1 };
    do
    {
        printv(v);
    } while (prev_permutation(v.begin(), v.end())); // <algorithm> prev_permutation( )
    cout << endl;

    // 조합 5C3 (next_permutation 활용)
    v = { 1, 2, 3, 4, 5 };
    v_temp = { 0, 0, 0, 1, 1 };
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v_temp[i] == 0)
                cout << v[i];
        }
        cout << endl;
    } while (next_permutation(v_temp.begin(), v_temp.end())); // <algorithm> next_permutation( )
    cout << endl;

    // 조합 5C3 (prev_permutation 활용)
    v = { 1, 2, 3, 4, 5 };
    v_temp = { 1, 1, 1, 0, 0 };
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v_temp[i] == 1)
                cout << v[i];
        }
        cout << endl;
    } while (prev_permutation(v_temp.begin(), v_temp.end())); // <algorithm> prev_permutation( )
    cout << endl;

    return 0;
}


<algorithm> next_permutation(), prev_permutation()
https://twpower.github.io/82-next_permutation-and-prev_permutation
*/
