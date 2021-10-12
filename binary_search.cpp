#include <vector>

using namespace std;

int binary_search(vector<int>& list, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (list[mid] == target) return mid;   // 끝점을 변경하여 좌측 범위에서 다시 탐색
        else if (list[mid] > target) end = mid - 1;   // 시작점을 변경하여 우측 범위에서 다시 탐색
        else start = mid + 1;
    }
    return -1; // not searched
}