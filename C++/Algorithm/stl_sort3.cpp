#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 4

using namespace std;

bool desc(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{

}

int main()
{
	vector<pair<string, int>> v;
	v.push_back(pair<string, int>("설현", 1995));
	v.push_back(pair<string, int>("아린", 1999));
	v.push_back(pair<string, int>("태연", 1989));
	v.push_back(pair<string, int>("제니", 1996));
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << endl;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << endl;
}