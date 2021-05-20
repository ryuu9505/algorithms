#include <vector>
#include <climits>
#define MAX_SIZE 100
using namespace std;

int d[MAX_SIZE];
int p[MAX_SIZE];

void dijkstra(vector<int> graph, int r)
{
    // g : 
    // r : root
    // s : selected node set
    for (int i = 0; i < graph.size(); i++)
    {
        d[i] = INT_MAX;
        p[i] = 0; //
    }
    d[r] = 0;

    while (s != )
}