#include <iostream>

using namespace std;

bool broken[10];

int possible(int c)
{
	if (c == 0)
	{
		if (broken[0])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	// 10으로 나누면서 숫자를 한자리씩 떼어 확인함
	// len으로 몇 자리수인지 저장함
	int len = 0;
	while (c > 0)
	{
		if (broken[c % 10])
		{
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		broken[x] = true;
	}

	int ans = n - 100;
	if (ans < 0)
	{
		ans = -ans;
	}

	// 모든 수를 다 탐색
	for (int i = 0; i <= 100000; i++)
	{
		int c = i;
		int len = possible(c);
		if (len > 0)
		{
			int press = c - n;
			if (press < 0)
			{
				press = -press;
			}

			// 최소값 찾기
			if (ans > len + press)
			{
				ans = len + press;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}