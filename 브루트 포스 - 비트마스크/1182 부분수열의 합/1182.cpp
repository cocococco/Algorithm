// 뭔지 진짜 모르겠다
#include <iostream>

using namespace std;

int a[20];

int main()
{
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 1; i < (1 << n); i++) // 부분수열을 만듦
	{
		int sum = 0;

		// 수열 내에 해당 숫자가 있는지 검사
		for (int k = 0; k < n; k++)
		{
			if (i & (1 << k))
			{
				sum += a[k];
			}
		}
		if (sum == s)
		{
			ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;
}