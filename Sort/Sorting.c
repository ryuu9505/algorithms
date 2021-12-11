#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100


int sorted[MAX_SIZE];


void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);


int main()
{
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE];

	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	// insertion_sort(list, n);

	for (i = 0; i < n; i++)
		printf("%d\n", list[i]);
}


void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	// 중간을 기준으로 두개의 배열로 나누고 각 원소 값들을 하나씩 비교해 가며 임시 배열로 정렬
	while (i <= mid && j <= right) // 하나의 배열의 원소가 모두 정렬될 때까지
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남은 배열의 원소들은 임시 배열로 그대로 옮기기
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 임시 배열에서 배열로 옮기기
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // Divide
		merge_sort(list, left, mid); // Conquer
		merge_sort(list, mid + 1, right); // Conquer
		merge(list, left, mid, right); // Combine
	}
}





 

