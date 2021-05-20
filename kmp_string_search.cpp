#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int pi[50];

vector<int> getPi(string pattern)
{
	int pattern_size = pattern.size();
	vector<int> pi(pattern_size, 0);
	int j = 0;

	for (int i = 1; i < pattern_size; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			pi[i] = ++j;
		}
	}

	return pi;
}

void KMP(string str, string pattern)
{
	vector<int> pi = getPi(pattern);
	int str_size = str.size();
	int pattern_size = pattern.size();
	int j = 0;

	for (int i = 0; i < str_size; i++)
	{
		while (j > 0 && str[i] != pattern[j])
		{
			j = pi[j - 1]; 
		}

		if (str[i] == pattern[j])
		{
			if (j == pattern_size - 1)
			{
				printf("matched at str[%d]\n", i - pattern_size + 1);
				j = pi[j];
			}
			else
			{
				j++;
			}
		}
	}
	  
}

int main()
{
	string str = "ababacabacaabacaaba";
	string pattern = "abacaaba";

	KMP(str, pattern);
}