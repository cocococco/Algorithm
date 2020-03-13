#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a = 5;
	int ans = 0;
	while (a < n)
	{
		ans += n / a;
		a *= 5;
	}
	cout << ans << '\n';
	return 0;
}