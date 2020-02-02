/*
�ʹ� ��ƴ� ������..
1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����(��������)
*/

#include <iostream>

using namespace std;

// ��� 1
/*
bool c[10];
int a[10];

void go(int index, int start, int n, int m)
{
	if (index == m) // ���
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
	// ���
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