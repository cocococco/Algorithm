/*
�ʹ� ��ƴ�...
1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
*/

#include <iostream>

using namespace std;

bool c[10]; // check. ����ߴ��� ���ߴ��� Ȯ��
int a[10]; // ����� ����� �迭

void go(int index, int n, int m)
{
	if (index == m) // m�� ���� �Ϸ�Ǹ� ������ ���
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) // ���� 1���� n���� ������� Ž��
	{
		if (c[i]) continue; // ����ߴ��� Ȯ��
		c[i] = true; // ��� �������� true�� �ٲ��ְ�
		a[index] = i; // �� ������ ��� �迭�� �߰�
		go(index + 1, n, m); // ���� ���� ã�� ���� index�� ���� ��ġ�� �Ű��ְ� �ٽ� ������� Ž����
		c[i] = false; // �� ��ġ�� �Դٴ� ���� ���� i�� �� ����ߴٴ� ���̹Ƿ� false�� �ٲ��ְ� ���� i�� �Ѿ
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	go(0, n, m);

	return 0;
}