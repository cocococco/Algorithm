/*
N���� ���� �ٸ� �ڿ��� �߿��� M���� �� ����
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
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= cnt[i]; j++)
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
		return;
	}

	if (index > n) return; // �Ұ����� ���

	// ���� �� ���� �� ������ �� �����Ƿ� ������ �����
	// cnt �迭�� ����Ͽ� �����ϴ� ��츦 ������
	// 1 1 1�� 1 1 �� 1 1 1�� ������ �� �����Ƿ�
	// �Ųٷ� ������ Ÿ�� ��
	// ���� ��ĭ�� ���� ~ 1���� �߿��� ����
	for (int i = m - selected; i >= 1; i--)
	{
		// ������ ���
		cnt[index] = i; // cnt : i�� � �����ߴ��� ����
		go(index + 1, selected + i, n, m);
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