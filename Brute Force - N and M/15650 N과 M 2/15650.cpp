/*
너무 어렵다 정말루..
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열(오름차순)
*/

#include <iostream>

using namespace std;

// 방법 1
/*
bool c[10];
int a[10];

void go(int index, int start, int n, int m)
{
	if (index == m) // 출력
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		if (c[i]) continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, i + 1, n, m);
		c[i] = false;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	return 0;
}
*/

int a[10];

void go(int index, int selected, int n, int m)
{
	// 출력
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	if (index > n) return;

	a[selected] = index;
	go(index + 1, selected + 1, n, m);
	a[selected] = 0;
	go(index + 1, selected, n, m);
}

int main()
{
	int n, m;
	cin >> n >> m;
	go(1, 0, n, m);

	return 0;
}