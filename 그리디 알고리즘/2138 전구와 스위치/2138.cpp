#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int n;

void push(vector<int> &a, int x)
{
	if (x != 0)
	{
		a[x - 1] = 1 - a[x - 1];
	}
	if (x != n - 1)
	{
		a[x + 1] = 1 - a[x + 1];
	}
	a[x] = 1 - a[x];
}

pair<bool, int> change(vector<int> a, vector<int> b)
{
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] != b[i - 1])
		{
			push(a, i);
			cnt++;
		}
	}
	if (a == b) return make_pair(true, cnt);
	else return make_pair(false, -1);
}

int main()
{
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &b[i]);
	}

	auto f = change(a, b);

	push(a, 0);
	auto p = change(a, b);
	p.second++;

	if (f.first && p.first)
	{
		printf("%d\n", f.second > p.second ? p.second : f.second);
	}
	else if (f.first)
	{
		printf("%d\n", f.second);
	}
	else if (p.first)
	{
		printf("%d\n", p.second);
	}
	else
	{
		printf("-1\n");
	}

	return 0;
}