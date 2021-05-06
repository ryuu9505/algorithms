#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> ans;
vector<int> temp;
vector<char> temp2;
vector<int> num;

void getCombination(vector<char> arr, int r)
{
	if (temp.size() == r)
	{
        string str;
        for(int i = 0; i < r; i++)
        {
            str += temp2[i];
        }
		ans.push_back(str);
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

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;
    vector<char> order;
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < orders[i].size(); j++)
        {
            order.push_back(orders[i][j]);
            num.push_back(j);
        }
        
        for (int j = 0; j < course.size(); j++)
        {
            sort(order.begin(), order.end());
            getCombination(order, course[j]);
        }
        
        sort(ans.begin(), ans.end());
        int k;
        for (int j = 0; j < ans.size(); j += k)
        {

            for (k = 1; j + k < ans.size();)
            {
                if (ans[j] == ans[j + k])
                {
                    if (k == 1)
                    {
                        answer.push_back(ans[j]);
                    }
                    k++;
                }
                else
                {
                    break;
                }
            }
        }
        order.clear();
        num.clear();  
        ans.clear();
    }
    
    
    
    
    return answer;
}