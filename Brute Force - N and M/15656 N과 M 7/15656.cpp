/*
N���� ���� �ٸ� �ڿ��� �߿��� M���� �� ���� (�ߺ� ����)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int a[10];
int p[10];

void go(int index, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		a[index] = p[i];
		go(index + 1, n, m);
	}
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

	go(0, n, m);

	return 0;
}