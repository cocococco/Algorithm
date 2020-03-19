#include <iostream>

using namespace std;

int d[1001];

int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (d[n] > 0) return d[n];
	else
	{
		d[n] = (dp(n - 1) + dp(n - 2)) % 10007;
		return d[n];
	}
}

int main()
{
	int n;
	cin >> n;
	cout << dp(n) << '\n';
	return 0;
}