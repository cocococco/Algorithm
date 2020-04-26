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
		//if (d[0] != 1) break; // 1 2 3 4 �� 2 3 4 1 �̳� �Ȱ����Ƿ�
		// ù��° �������� Ȯ���ϰ� �������� Ȯ���� �ʿ䰡 ����
		// => O(N!)���� �ð����⵵ ����
		// �̰� �� �ȵǴ��� �� �𸣰ڴ�

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
	// ���������� 1 2 3 4 �� 2 3 4 1 �̳� �Ȱ����Ƿ�
	// ù��°�� �����ϰ� �� �ڷθ� ������ ã�Ƽ� Ȯ���Ѵ�
	// O(N!)

	printf("%d\n", ans);
	return 0;
}