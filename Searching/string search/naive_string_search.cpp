#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void find_pattern(const string& str, const string& ptn)
{
	int i, j;
	const int str_size = str.size();
	const int ptn_size = ptn.size();
	bool unmatched_flag = true;

	cout << "target : "<< str << endl;
	cout << "pattern : "<< ptn << endl;

	for (i = 0; i < str_size - ptn_size + 1; i++)
	{
		for (j = 0; j < ptn_size; j++)
		{
			if (str[i + j] == ptn[j])
			{
				continue;
			}
			else
			{
				break;
			}
		}

		if (j == ptn_size)
		{
			printf("matched at [%d]\n", i);
			unmatched_flag = false;
		}
	}

	if (unmatched_flag)
	{
		cout << "unmatched" << endl;
	}
}

int main()
{
	const string str = "tomatomatomato";
	const string ptn = "tomato";
	find_pattern(str, ptn);
    // output : matched at [0] [4] [8]
}