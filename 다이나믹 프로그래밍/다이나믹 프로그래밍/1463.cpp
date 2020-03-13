#include <iostream>

using namespace std;

int memo[1000001];

int dp(int n)
{
	if (n == 1) return 0;

	if (memo[n] > 0) return memo[n];
	else
	{
		memo[n] = dp(n - 1) + 1;

		if (n % 3 == 0)
		{
			int tmp = dp(n / 3) + 1;
			if (memo[n] > tmp)
			{
				memo[n] = tmp;
			}
		}
		if (n % 2 == 0)
		{
			int tmp = dp(n / 2) + 1;
			if (memo[n] > tmp)
			{
				memo[n] = tmp;
			}
		}
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