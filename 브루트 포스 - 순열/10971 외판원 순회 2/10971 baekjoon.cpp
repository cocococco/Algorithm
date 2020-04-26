#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int w[20][20];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &w[i][j]);
		}
	}

	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		d[i] = i;
	}

	int ans = 2147483647;

	do
	{
		//if (d[0] != 1) break; // 1 2 3 4 나 2 3 4 1 이나 똑같으므로
		// 첫번째 시작점만 확인하고 나머지는 확인할 필요가 없다
		// => O(N!)으로 시간복잡도 감소
		// 이건 왜 안되는지 잘 모르겠다

		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (w[d[i]][d[i + 1]] == 0)
			{
				ok = false;
			}
			else
			{
				sum += w[d[i]][d[i + 1]];
			}
		}

		if (ok && w[d[n - 1]][d[0]] != 0)
		{
			sum += w[d[n - 1]][d[0]];

			if (ans > sum) ans = sum;
		}
	}// while (next_permutation(d.begin(), d.end()));
	while (next_permutation(d.begin() + 1, d.end()));
	// 마찬가지로 1 2 3 4 나 2 3 4 1 이나 똑같으므로
	// 첫번째만 고정하고 그 뒤로만 순열을 찾아서 확인한다
	// O(N!)

	printf("%d\n", ans);
	return 0;
}