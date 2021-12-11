#include <vector>
using namespace std;

// asc
void selection_sort(vector<int> list)
{
    for(int i = 0; i < list.size() - 1; i++)
    {
        int least = i;

        // search(select) least element 
        for (int j = i + 1; j < list.size(); j++)
        {
            if(list[j] < list[least])
                least = j;
        }

        // swap
        if (i != least)
        {
            int temp = list[i];
            list[i] = list[least];
            list[least] = temp;
        }
    }
}