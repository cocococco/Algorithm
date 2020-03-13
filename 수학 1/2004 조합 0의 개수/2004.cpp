#include <iostream>

using namespace std;

int f(long long n, int a)
{
	long long x = a;
	int ans = 0;
	while (x <= n)
	{
		ans += n / x;
		x *= a;
	}
	return ans;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	long long two = 0, five = 0;
	two = f(n, 2) - f(m, 2) - f(n - m, 2);
	five = f(n, 5) - f(m, 5) - f(n - m, 5);
	if (two > five) cout << five << '\n';
	else cout << two << '\n';

	return 0;
}