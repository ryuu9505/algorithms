/*

*/
#include <iostream>
#include <vector>
using namespace std;

int units[100];
int d[10001];
//vector<int> arr;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> units[i];
	// cin >> x;
	// arr.push_back(x);

	for (int i = 1; i <= m; i++)
		d[i] = m+1;
	// vector<int> = (m+1,m+1);


	// DP
	d[0] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - units[j] >= 0)
				d[i] = min(d[i], d[i - units[j]] + 1);
		}
	}

	if (d[m] == m + 1)
		cout << "-1";
	else
		cout << d[m];

	return 0;
}