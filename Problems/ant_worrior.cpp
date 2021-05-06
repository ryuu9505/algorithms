#include <iostream>
#include <vector>
using namespace std;

int d[100];
vector<int> arr;

int main()
{
	int n;
	cin >> n;

	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr.push_back(x);
	}

	// DP (bottom-up)
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; i++)
	{
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);
	}
	cout << d[n - 1] << endl;

	return 0;
}