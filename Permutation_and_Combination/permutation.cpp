#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

int n, m, r;
vector<int> arr; // 각각의 벡터(노드)에 연결된 (최대 2개의) 노드 정보를 넣기 위해 벡터 배열을 선언
vector<int> temp;
vector<vector<int>> permutations;
bool visited[MAX_SIZE]; // index 노드의 탐색을 기록

// 재귀
void permutation(int index, int depth)
{
    temp.push_back(arr[index]);
    if (depth == r)
    {
        permutations.push_back(temp);
        return;
    }
        
    for (int i = index + 1; i < arr.size(); i++)
    {
        int next = i;

        if (!visited[next])
            permutation(next, depth + 1);
    }
}

#include <algorithm>

// default
template <class BidirectionalIterator>
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);

// custom
template <class BidirectionalIterator, class Compare>
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);;


#include <algorithm>

// default
template <class BidirectionalIterator>
bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last);

// custom
template <class BidirectionalIterator, class Compare>
bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);;


// Parameters
// Iterator
// Compare 함수

// Return value
// 다음 순서의 순열로 정렬이 완료되면 true 그렇지 않으면 false

// default는 오름차순이므로 
// 최초에 컨테이너를 오름차순으로 정렬해 두어야 모든 순열을 만들 수 있음 
// sort()를 사용하면 됨

next_permutation



int main()
{
    permutation(0, 0);
    
    for (int i = 0; i < permutations.size(); i++)
    {
        for (int j = 0; j < permutations[i].size(); j++)
        {
            cout << permutations[i][j];
        }
        cout << endl;
    }

    
    return 0;
}