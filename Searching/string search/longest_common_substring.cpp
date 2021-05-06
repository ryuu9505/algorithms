#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int dt[100][100];

void lcs(string str1, string str2)
{
	int max1 = 0, tmpi = 0;

	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dt[i][j] = dt[i - 1][j - 1] + 1;
			}
			if (dt[i][j] > max1)
			{
				max1 = dt[i][j];
				tmpi = i;
			}
		}
	}

	cout << max1 << endl;
	for (int i = max1; i >= 0; i--)
	{
		cout << str1[tmpi - i];
	}
	cout << endl;
} // T_n = O(n^2)

int main()
{
	string str1 = "BCBBBC";
	string str2 = "CBBBCC";
	lcs(str1, str2);
    // output : 5 (maximum length)
    // output : CBBBC
}