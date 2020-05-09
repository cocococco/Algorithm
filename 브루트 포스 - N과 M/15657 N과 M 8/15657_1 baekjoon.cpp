/*
N���� ���� �ٸ� �ڿ��� �߿��� M���� �� ����
(�ߺ� ����, �񳻸�����)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int cnt[10]; // ���� �� ������ �� �����Ƿ� ���� cnt �迭
int num[10];

// �����ϴ� ���, ���ϴ� ���� ������ ���
void go(int index, int selected, int n, int m)
{
	if (selected == m) // selected�� �ε�����
	{
		// 0��° �ε������� n-1��°����
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= cnt[i]; j++)
			{
				cout << num[i] << ' ';
				// �ش� i �ε����� ����ִ� cnt ������ŭ
				// num�� i �ε����� �ִ� ���ڸ� �����
			}
		}
		cout << '\n';
		return;
	}

	if (index >= n) return; // �Ұ����� ���

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
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);

	go(0, 0, n, m);

	return 0;
}