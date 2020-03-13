#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main()
{
	int n, s;
	cin >> n >> s;
	int a[100000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > s) a[i] -= s;
		else a[i] = s - a[i];
	}

	int ans = a[0]; // 0���� �ʱ�ȭ���� �ʰ� a[0]���� �ʱ�ȭ�ϸ� �ڵ带 ���� �� ����
	for (int i = 1; i < n; i++) // n=1�̸� ������ �ݺ��� ����. n=2�̸� a[0]�� a[1]�� �ִ����� ���� �� ����
	{
		ans = gcd(ans, a[i]);
	}
	cout << ans << '\n';

	return 0;
}