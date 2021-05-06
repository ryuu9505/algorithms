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
    ////////////////////////////////////////
    // initialization
    ////////////////////////////////////////

    vector<int> v;
    printv(v);

    vector<int> v_direct = { 1, 2, 3, 4, 5, 6 };
    printv(v_direct);

    vector<int> v_zeros(5);
    printv(v_zeros);

    vector<int> v_arr[] = { {1, 2}, {1, 2, 3}, {1, 2, 3, 4} };
    printv(v_arr[0]);
    printv(v_arr[1]);
    printv(v_arr[2]);

    vector<vector<int>> v_double = { {6, 7}, {6, 7, 8}, {6, 7, 8, 9} };
    printv(v_double[0]);
    printv(v_double[1]);
    printv(v_double[2]);

    ////////////////////////////////////////
    // assignment
    ////////////////////////////////////////

    v.assign(3, 7);
    printv(v);


    /// <algorithm> find( )
    v = {6, 4, 1, 2, 4};
    vector<int>::iterator it = find_if(v.begin(), v.end(), 4);
    if (it == v.end()) { cout << "X"; }
    else { cout << "find at " << it - v.begin() << endl; }
}