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

	int ans = a[0]; // 0으로 초기화하지 않고 a[0]으로 초기화하면 코드를 줄일 수 있음
	for (int i = 1; i < n; i++) // n=1이면 어차피 반복문 못들어감. n=2이면 a[0]과 a[1]의 최대공약수 구할 수 있음
	{
		ans = gcd(ans, a[i]);
	}
	cout << ans << '\n';

	return 0;
}