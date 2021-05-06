#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& list, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (list[mid] == target) return mid;
        else if (list[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1; // no target
}