#include <iostream>

using namespace std;

int main()
{
	long n, m;
	cin >> n >> m;
	int ans;

	if (n >= 3)
	{
		if (m >= 7) ans = m - 2;
		else if (m >= 4) ans = 4;
		else if (m >= 3) ans = 3;
		else if (m >= 2) ans = 2;
		else ans = 1;
	}
	else if (n >= 2)
	{
		if (m >= 7) ans = 4;
		else if (m >= 5) ans = 3;
		else if (m >= 3) ans = 2;
		else ans = 1;
	}
	else ans = 1;

	cout << ans << '\n';
}