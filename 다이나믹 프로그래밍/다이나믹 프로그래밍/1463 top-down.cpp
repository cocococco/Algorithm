#include <iostream>

using namespace std;

int memo[1000001];

int dp(int n)
{
	// ��ȭ�İ� ���� �ʴ� �ʱⰪ�� �� ��������
	if (n == 1) return 0;

	// �޸��� �� ������ �ִٸ� ����
	if (memo[n] > 0) return memo[n];
	// ���ٸ� ���
	else
	{
		// ���� �⺻������ 1�� ���� ��츦 �����س��´�.
		memo[n] = dp(n - 1) + 1;

		if (n % 3 == 0)
		{
			int tmp = dp(n / 3) + 1;
			// 3���� ���� ����� min�̸� memo�� ����
			if (memo[n] > tmp)
			{
				memo[n] = tmp;
			}
		}
		if (n % 2 == 0)
		{
			int tmp = dp(n / 2) + 1;
			// 2�� ���� ����� min�̸� memo�� ����
			if (memo[n] > tmp)
			{
				memo[n] = tmp;
			}
		}
		// �̷��� ��� ��츦 Ȯ���ϰ� min�� ������ ������ �ݷʿ� Ʋ������.
	}
	return memo[n];
}

int main()
{
	int n;
	cin >> n;
	cout << dp(n) << '\n';
	return 0;
}