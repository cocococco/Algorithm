/*
1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����(��������)
*/
#include <iostream>

using namespace std;

int a[10];

void go(int index, int start, int n, int m)
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

	// ���������̾�� �ϹǷ� start ������ �߰��Ͽ�
	// start ~ n ������ ���ڸ� �����Ѵ�.
	// ���⼭ index�� �ε�����, i. start�� ������!
	// check �迭�� �ʿ䰡 ������. ���������̹Ƿ� �ߺ� �Ұ�.
	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		go(index + 1, i + 1, n, m);
		// �� ������ i+1 �̻��� ���ڰ� �;� ��
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);

	return 0;
}