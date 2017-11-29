const int N = 1e5;
int parent[N];
int depth[N];
int nDiff = ?;

void make(int a)
{
	parent[a] = a;
	depth[a] = 0;
}

int find(int a) 
{
	if (a == parent[a]) return a;

	return parent[a] = find(parent[a]);
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		--nDiff;
		if (depth[a] < depth[b]) swap(a, b);

		parent[b] = a;
		if (depth[a] == depth[b]) ++depth[a];
	}
}