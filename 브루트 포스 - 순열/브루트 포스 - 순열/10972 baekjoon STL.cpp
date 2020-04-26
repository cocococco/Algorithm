#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 7 2 3 6 5 4 1
// 7 2(3)6 5 4 1
// 7 2 3 6 5(4)1
// 7 2(4)6 5(3)1
// 7 2 4(1 3 5 6)

// ���� next_permutation �Լ��� ������ �����ϸ� �̷��� ��
bool next_permutation(int *a, int n)
{
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	// i-1��°�� i��°���� �۾����� �� out
	// a[i-1] : 3, a[i] : 6

	if (i <= 0) return false;
	// ������ ������ ���

	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;
	// j��°�� i-1��°���� Ŀ���� �� out
	// a[j] : 4

	swap(a[i - 1], a[j]);
	// �ϴ� i-1��°�� j��°�� ������ �ٲ�

	j = n - 1;

	while (i < j)
	{
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	// ���� ���������̾����� �ݴ�� swap�ϸ� ���������� ��

	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (next_permutation(a.begin(), a.end()))
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
	}
	else
	{
		cout << "-1";
	}

	cout << '\n';
	return 0;
}