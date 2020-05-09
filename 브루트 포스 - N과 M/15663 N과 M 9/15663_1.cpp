/*
N���� �ڿ��� �߿��� M���� �� ���� ���
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10];
int num[10];
int cnt[10]; // ������ ���� �� �� �־������� ����

void go(int index, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (cnt[i] > 0)
			// �ش� �ε����� ���� ���� ����� �� ������
		{
			cnt[i] -= 1; // ����� ������ �ϳ��� ����
			a[index] = i; // �ε����� �迭 a�� ����
			go(index + 1, n, m); // ���� ���
			cnt[i] += 1; // ����� �������� �ٽ� ������
			// ���� ���� ������ �°� ������ �� �ְ� ��
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int temp[10];
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i]; // temp �迭�� ���� �Է¹���
	}
	sort(temp, temp + n); // ������������ ����

	int k = 0;
	int x = temp[0]; // �Է¹��� ù ��° ��
	int c = 1;

	for (int i = 1; i < n; i++)
	{
		if (x == temp[i])
			// ���� ���� ���� �ε����� ����� ���� ������
		{
			c += 1; // �ߺ��Ǵ� ���� ������ �����ϱ� ����
					// ���� c�� ������Ŵ
		}
		else // ���� ���� ���� �ε����� ����� ���� �ٸ���
		{
			num[k] = x; // �� ���ڸ� num �迭�� ����
			cnt[k] = c; // ������ cnt �迭�� ����
			k += 1; // �ε��� ������Ŵ
			x = temp[i]; // ���� ���� ������ ����
			c = 1; // ���� �ʱ�ȭ
		}
	}

	// ������ ���� ���� �������Ƿ�
	num[k] = x;
	cnt[k] = c;
	n = k + 1;
	go(0, n, m);

	return 0;
}