#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 4

using namespace std;

bool desc(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}

}

int main()
{
	vector<pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("수지", make_pair(1994, 8452)));
	v.push_back(pair<string, pair<int, int>>("혜리", make_pair(1994, 1287)));
	v.push_back(pair<string, pair<int, int>>("제니", make_pair(1996, 3542)));
	v.push_back(pair<string, pair<int, int>>("사나", make_pair(1996, 5412)));
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second.first << " " <<v[i].second.second << endl;
	cout << endl;

	sort(v.begin(), v.end(), desc);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second.first << "-" << v[i].second.second << endl;
	cout << endl;
}