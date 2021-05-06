#include <iostream>
#include <vector>
using namespace std;

int d[20][20];

int main()
{
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				cin >> d[j][k];

		int left_up, left, left_down;
		for (int k = 1; k < m; k++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == 0)
				{
					left_up = 0;
					left_down = d[j + 1][k - 1];
				}
				else if (j == n - 1)
				{
					left_up = d[j - 1][k - 1];
					left_down = 0;
				}
				else
				{
					left_up = d[j - 1][k - 1];
					left_down = d[j + 1][k - 1];
				}
				left = d[j][k - 1];
				d[j][k] += max(max(left_up, left), left_down);
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++)
		{
			result = max(result, d[i][m - 1]);
		}
		cout << result;
	}
	return 0;
}