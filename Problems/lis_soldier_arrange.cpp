/*


LIS알고리즘
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
int d[2000];
vector<int> v;

int main()
{
	cin >> n;

	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++)
		d[i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] < v[j])
				d[i] = max(d[i], d[j] + 1);
		}
	}
	cout << n - d[n - 1];

}