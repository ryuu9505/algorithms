#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

/*
	Brute-Force 방식은 검사를 시작한 지점을 기준으로 다음 검사구간을 결정하는데
	KMP Algorithm은 불일치한 지점을 기준으로 다음 검사구간을 결정한다.
*/


vector<int> KMP_Preprocess(string p)
{
	vector<int> next(p.length(), 0); // next[i] : p[0] ~ p[i-1]의 suffix/postfix 최대일치수
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
	suffix와 postfix의 간격(i - j)이 커지면서 진행됨
	불일치하면 suffix의 인덱스인 j는 next에 의해 최대 처음 지점까지 돌아가므로
*/


/*
	t[x]와 p[i]가 불일치한 경우 중간 과정을 건너뛰고 t[x]와 p[next[i]]를 비교하면 됨
	suffix/postfix 최대일치수가 결과적으로 일치한 suffix 바로 뒷 문자의 인덱스와 같으므로
	위 행동이 pattern의 suffix와 text의 postfix가 매칭되는 순간으로 건너뛰게 함
*/

/*
	j = next[j]; // the same principle as the KMP algorithm

	next를 만드는 과정에서도 KMP와 같은 원리가 적용 됨
	postfix가 text이고 suffix가 pattern이라고 생각하면 됨
	i를 다시 초기화하고 다음 칸부터 비교할 필요 없이
	KMP에서 불일치 지점이 m인 경우 중간 과정을 건너뛰고 t[m]와  p[next[m]]의 비교부터 수행하면 되듯이
	여기서도 p[i]와 p[next[j]]를 비교하는 구간을 설치하여 시간을 단축하는 것이다.
*/

/*
	next[++i] = ++j;

	j = 0 인 상황에서 일치했다는 것은 길이 1의 suffix와 postfix가 일치했다는 의미이므로 j + 1을 대입
	i까지의 부분 문자열에 대한 결과이므로 next의 정의에 따라 next[i+1]에 값을 대입
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