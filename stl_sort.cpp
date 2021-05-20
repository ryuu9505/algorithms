#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

#define MAX_SIZE 10
using namespace std;

void print_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	cout << endl;
}

bool desc(int a, int b)
{
	return a > b; 
}

int main()
{
	int i;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	int arr_int[MAX_SIZE];
	for (i = 0; i < MAX_SIZE; i++)
		arr_int[i] = dis(gen);

	print_array(arr_int, MAX_SIZE);

	sort(arr_int, arr_int + MAX_SIZE);
	cout << "Ascending Sorted" << endl;
	print_array(arr_int, MAX_SIZE);

	sort(arr_int, arr_int + MAX_SIZE, desc);
	cout << "Descending Sorted" << endl;
	print_array(arr_int, MAX_SIZE);


	/*
	vector<int> arr_vector;
	for (i = 0; i < MAX_SIZE; i++)
		arr_vector.push_back(dis(gen));

	cout << "arr_vector" << endl;
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr_vector[i]);
	cout << endl;

	sort(arr_vector.begin(), arr_vector.end());

	cout << "arr_vector (ascending sorted)" << endl;
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr_vector[i]);
	cout << endl;
	*/
}