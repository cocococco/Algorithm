/*
N개의 서로 다른 자연수 중에서 M개를 고른 수열 모두
*/
#include <iostream>
#include <algorithm>

using namespace std;

int a[10];
int c[10];
int num[10];

void go(int index, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (c[i]) continue;
		c[i] = true;
		a[index] = num[i];
		go(index + 1, n, m);
		c[i] = false;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);

	go(0, n, m);

	return 0;
}