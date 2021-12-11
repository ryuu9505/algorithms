#include <stdio.h>
#include <vector>
using namespace std;


// with vector<int>
void insertion_sort (vector<int> list)  
{
	int j;

	for (int i = 1; i < list.size(); i++)
	{
		int key = list[i];
    
		for (j = i - 1; j >= 0 && list[j] > key; j--) 
			list[j + 1] = list[j]; 
		list[j + 1] = key; // [j]가 key 보다 작으면 [j+1]에 key 넣기
	}
  
}