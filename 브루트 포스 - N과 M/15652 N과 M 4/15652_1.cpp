/*
1���� N���� �ڿ��� �߿��� M���� �� ����
(�ߺ� ����, �񳻸�����)
*/
#include <iostream>

using namespace std;

int cnt[10]; // ���� �� ������ �� �����Ƿ� ���� cnt �迭

// �����ϴ� ���, ���ϴ� ���� ������ ���
void go(int index, int selected, int n, int m)
{
	if (selected == m) // selected�� �ε�����
	{
		for (int i = 1; i <= n; i++) // �� �� �ִ� ���ڴ� 1~n
		{
			// �ش� ������ �ε����� ���� cnt �迭�� ����ִ�
			// ������ŭ �ش� ���ڸ� �����
			// cnt[1]���� 1�� �� �� �ִ��� �������
			for (int j = 1; j <= cnt[i]; j++)
			{
				cout << i << ' ';
			}
		} // �̰� n���� ���鼭 ã�� ���
		cout << '\n';
		return;
	}

	if (index > n) return; // �Ұ����� ���

	// ���� �� ���� �� ������ �� �����Ƿ� ������ �����
	// cnt �迭�� ����Ͽ� �����ϴ� ��츦 ������
	// 1 1 1�� 1 1 �� 1 1 1�� ������ �� �����Ƿ�
	// �Ųٷ� ������ Ÿ�� ��
	// i�� ���� ��ĭ�� ����, m ~ 1����
	for (int i = m - selected; i >= 1; i--)
	{
		// ������ ���
		cnt[index] = i; // cnt : i�� � �����ߴ��� ����
		go(index + 1, selected + i, n, m);
		// i��ŭ ���������Ƿ� selected�� i��ŭ ����
	}

	// �������� ���� ���
	cnt[index] = 0;
	go(index + 1, selected, n, m);
}

int main()
{
	int n, m;
	cin >> n >> m;

	go(1, 0, n, m);

	return 0;
}