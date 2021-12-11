#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


vector<vector<int>> ans;
vector<int> num;
vector<int> temp;
vector<int> temp2;

void getCombination(vector<int> arr, int r)
{
	if (temp.size() == r)
	{
		ans.push_back(temp2);
	}
	
	int lastIndex = temp.size() == 0 ? -1 : temp[temp.size() - 1];
	for (int i = lastIndex + 1; i < arr.size(); i++)
	{
		temp.push_back(num[i]);
		temp2.push_back(arr[i]);
		getCombination(arr, r);
		temp.pop_back();
		temp2.pop_back();
	}
}

// recursive combination
#define N 5
#define R 3
int an[N] = { 1, 2, 3, 4, 5 };
int tr[R];
void comb(int n, int r)
{
	if (r == 0)
	{
		for (int i = 0; i < R; i++)
		{
			cout << tr[i] << " ";
		}
		cout << endl;
	}
	else if (n < r)
	{
		return;
	}
	else
	{
		tr[r - 1] = an[n - 1];
		comb(n - 1, r - 1);
		comb(n - 1, r);
	}
}




int main()
{
	vector<int> arr = { 3, 6, 8, 9 };
	for (int i = 0; i < arr.size(); i++)
	{
		num.push_back(i);
	}
	
	getCombination(arr, 3);
	arr.clear();


	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << ans.size();


	comb(N, R);
}






// string 한정
void combination(string src, string crs, int depth) {
    if (crs.size() == depth) combi[crs]++;

    else for (int i = 0; i < src.size(); i++)
        combination(src.substr(i+1), crs+src[i], depth);
}