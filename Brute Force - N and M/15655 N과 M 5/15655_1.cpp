/*
N개의 서로 다른 자연수 중에서 M개를 고른 수열 (오름차순)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int a[10];
int p[10];

void go(int index, int selected, int n, int m)
{
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	if (index >= n) return;

	a[selected] = p[index];
	go(index + 1, selected + 1, n, m);

	go(index + 1, selected, n, m);
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	sort(p, p + n);

	go(0, 0, n, m);

	return 0;
}