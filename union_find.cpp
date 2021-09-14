#include "union_find.h"
#define MAX_SIZE 100

int parent[MAX_SIZE];

void InitSet()
{
	for (int i = 0; i < MAX_SIZE; ++i)
		parent[i] = -1;
}

int FindSet(int v)
{
	if (v < parent[v]) return v;
	return FindSet(parent[v]);
}

int getSetSize(int v)
{
	return -parent[FindSet(v)];
}

void UnionSet(int u, int v)
{
	int root1 = FindSet(u);
	int root2 = FindSet(v);
	if (root1 == root2) return;

	parent[root1] += parent[root2];
	parent[root2] = root1;

/*
void MakeSet(int v)
{
	parent[v] = v;
}

int FindSet(int v)
{
	if (v == parent[v]) return v;
	return FindSet(parent[v]);
}

void UnionSet(int u, int v)
{
	parent[FindSet(v)] = FindSet(u);
}
*/