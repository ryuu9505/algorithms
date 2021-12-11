#include <stdio.h>
#include <vector>
using namespace std;


void bubble_sort(vector<int> list)  // with vector<int>
{
	for (int i = list.size() - 1; i > 0; i--)  // i : 원소를 삽입 할 위치
	{ 
		for (int j = 0; j < i; j++)  // 0 부터 i 까지 차근차근
		{
            // 바로 옆 원소와 비교하여 조건에 더 가까운 원소를 i 의 방향으로 이동시킴
			if (list[j] > list[j + 1])  
			{ 
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}