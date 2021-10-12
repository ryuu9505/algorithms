#include <stack>
#include <vector>
#define MAX_N 1000

using namespace std;


vector<int> graph[MAX_N];
bool visited[MAX_N] = {false};


// by Stack 
void DFS(int root)
{
    stack<int> s;
    bool visited[MAX_N] = {false};

    s.push(root);
    visited[root] = true;

    while (!s.empty())  
    {  
        int curr = s.top();
        s.pop(); 

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int next = graph[curr][i];  // adjacent node

            if (!visited[next])  // add necessary conditions
            {
                visited[next] = true;
                s.push(next);
            } 
        } 
    } 
}


// by Recursion
void DFS(int curr)
{
    visited[curr] = true;
    // process the node printf("%d ",curr);
    
    for(int i = 0; i < graph[curr].size(); i++)
    { 
        int next = graph[curr][i];
    
        if(!visited[next])  // add necessary conditions
            DFS(next);
    }
}


int main() 
{

    // node releations 
    for(int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
  
    DFS(0);
}