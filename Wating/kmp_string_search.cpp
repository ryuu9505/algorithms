#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

/*
	Brute-Force ����� �˻縦 ������ ������ �������� ���� �˻籸���� �����ϴµ�
	KMP Algorithm�� ����ġ�� ������ �������� ���� �˻籸���� �����Ѵ�.
*/


vector<int> KMP_Preprocess(string p)
{
	vector<int> next(p.length(), 0); // next[i] : p[0] ~ p[i-1]�� suffix/postfix �ִ���ġ��
	next[0] = -1;

	int i = 0, // i : index of postfix
		j = -1; // j : index of suffix 
	while (i < p.length()) 
	{
		while (j >= 0 && p[i] != p[j])
		{
			j = next[j]; /* the same principle as the KMP algorithm */
		}
		next[++i] = ++j;
	}	
	return next;
}

/*
	suffix�� postfix�� ����(i - j)�� Ŀ���鼭 �����
	����ġ�ϸ� suffix�� �ε����� j�� next�� ���� �ִ� ó�� �������� ���ư��Ƿ�
*/


/*
	t[x]�� p[i]�� ����ġ�� ��� �߰� ������ �ǳʶٰ� t[x]�� p[next[i]]�� ���ϸ� ��
	suffix/postfix �ִ���ġ���� ��������� ��ġ�� suffix �ٷ� �� ������ �ε����� �����Ƿ�
	�� �ൿ�� pattern�� suffix�� text�� postfix�� ��Ī�Ǵ� �������� �ǳʶٰ� ��
*/

/*
	j = next[j]; // the same principle as the KMP algorithm

	next�� ����� ���������� KMP�� ���� ������ ���� ��
	postfix�� text�̰� suffix�� pattern�̶�� �����ϸ� ��
	i�� �ٽ� �ʱ�ȭ�ϰ� ���� ĭ���� ���� �ʿ� ����
	KMP���� ����ġ ������ m�� ��� �߰� ������ �ǳʶٰ� t[m]��  p[next[m]]�� �񱳺��� �����ϸ� �ǵ���
	���⼭�� p[i]�� p[next[j]]�� ���ϴ� ������ ��ġ�Ͽ� �ð��� �����ϴ� ���̴�.
*/

/*
	next[++i] = ++j;

	j = 0 �� ��Ȳ���� ��ġ�ߴٴ� ���� ���� 1�� suffix�� postfix�� ��ġ�ߴٴ� �ǹ��̹Ƿ� j + 1�� ����
	i������ �κ� ���ڿ��� ���� ����̹Ƿ� next�� ���ǿ� ���� next[i+1]�� ���� ����
*/


void KMP(string t, string p)
{
	vector<int> next = KMP_Preprocesst(p);
	int i = 0, // index of text
		j = 0; // index of pattern

	while (i < t.length())
	{
		while (j >= 0 && t[i] != p[j])
		{
			j = next[j];
		}

		if (j == p.length() - 1)
		{
			printf("matched at t[%d]\n", i - j);
			j = next[j];
		}
		else
		{
			i++; j++;
		}
	}
}


int main()
{
	KMP("abacaaba", "aba");
	KMP("ababacabacaabacaaba", "abacaaba"); // 6
}