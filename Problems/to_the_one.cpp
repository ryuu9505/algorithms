#include <iostream>
#include <vector>
using namespace std;

int d[30001];
vector<int> arr;

int main()
{
	int n;
	cin >> n;

	// DP (bottom-up)
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;

		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
		if (i % 5 == 0)
			d[i] = min(d[i], d[i / 5] + 1);

	}
	cout << d[n] << endl;

	return 0;
}