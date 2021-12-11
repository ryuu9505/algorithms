#include <iostream>
#include <vector>

using namespace std;

// nCr = n-1Cr + n-1Cr-1 을 활용
template <typename T>
void Combination(T set, T comb, int r, int comb_idx, int set_idx)
{
	if (r == 0)
	{
		// print
		for (int i = 0; i < comb.size(); i++)
			cout << comb[i] << " ";
		cout << endl;
	}
	else if (set_idx == set.size())
	{
		return;
	}
	else 
	{
		comb[comb_idx] = set[set_idx];

		// include the element (포함시키고 이후에 n-1Cr-1개의 경우의 수가 존재)
		Combination(set, comb, r - 1, comb_idx + 1, set_idx + 1);  // comb_idx + 1
		
		// not include the element (포함시키지 않고 이후에 n-1Cr개의 경우의 수가 존재)
		Combination(set, comb, r, comb_idx, set_idx + 1);  // comb_idx (덮어쓰기)
		
	}
}

int main()
{
	vector<int> set = { 1, 2, 3, 4, 5 };

	int r = 3;
	vector<int> combination(r);
	Combination<vector<int>>(set, combination, r, 0, 0);

}