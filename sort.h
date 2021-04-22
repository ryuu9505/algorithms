#ifndef SORT_H
#define SORT_H

#define MAX_SIZE 10000

inline void swap(int& a, int& b) 
{
    int temp = a; a = b; b = temp;
}

void bubble_sort(int list[], int n)
{
    int i, j;

    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (list[j] > list[j + 1])
            {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

void insertion_sort(int list[], int n)

{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (list[j] > key)
                list[j + 1] = list[j];
            else
                break;
        }
        list[j + 1] = key;
    }
}

void selection_sort(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0; i < n - 1; i++)
    {
        least = i;

        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[least])
                least = j;
        }

        if (i != least)
        {
            swap(list[i], list[least]);
        }
    }
}

int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    // merge two divided and sorted lists
    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // merge lefts
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

    // copy
    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
    if (left >= right) return; // base condition

    int mid;

    mid = (left + right) / 2; // divide
    merge_sort(list, left, mid); // conquer (left)
    merge_sort(list, mid + 1, right); // conquer (right)
    merge(list, left, mid, right); // combine
}


void quick_sort(int list[], int left, int right)
{
    if (left >= right) return; // base condition

    // divide
    int i = left;
    int& pivot = list[right];
    for (int j = left + 1; j < right; j++)
    {
        if (list[j] < pivot)
            swap(list[i++], list[j]);
    }
    swap(list[i], pivot);
     
    // conquer
    quick_sort(list, left, i - 1);
    quick_sort(list, i + 1, right);
}

#endif SORT_H