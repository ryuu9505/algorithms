#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i;
    vector<int> set = { 2, 3, 5, 7 };
    int n = set.size();
    //int set[] = { 2, 3, 5, 7, 11 };
    //int n = sizeof(set) / sizeof (set[0]);

    for (int num = 0; num < (1 << n); num++)
    {
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
                cout << set[i] << " ";
        }
        cout << endl;
    }
}