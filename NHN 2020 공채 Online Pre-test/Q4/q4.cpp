#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int r[1000000];

int main()
{
	int n, g, m;
	cin >> n >> g >> m; // 거리, 기름 초기값, 주유소 개수
	vector<int> s(m);
	for (int i = 0; i < m; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> r[s[i]];
	}

	int cur = 0;
	int left = g;
	int cnt = 0;

	while (true)
	{
		if (n - cur - left > 0)
		{
			// 주유소 들러야 함
			int max = 0;
			int index = 0;

			for (int i = cur + 1; i <= cur + left; i++)
			{
				if (max < r[i])
				{
					max = r[i];
					index = i;
				}
			}

			if (max == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
			else
			{
				left = left + r[index] - (index - cur);
				cur = index;
				cnt++;
			}
		}
		else
		{
			cout << cnt << '\n';
			return 0;
		}
	}
}