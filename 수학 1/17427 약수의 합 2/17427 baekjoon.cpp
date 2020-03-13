#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ans += (n / i) * i;
		// n 이하의 자연수 중에서 i를 약수로 갖는 수의 개수는 n / i 개. i가 (n/i)번 더해지니 (n/i)*i임.
	}
	cout << ans << '\n';

	return 0;
}