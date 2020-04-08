#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}

	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n && j < m)
	{
		if (a[i] <= b[j])
		{
			c[k++] = a[i++]; // 배열 a에 있는 수가 더 작으면 a를 결과 배열에 넣고
		}
		else
		{
			c[k++] = b[j++]; // 배열 b에 있는 수가 더 작으면 b를 결과 배열에 넣는다
		}
	}

	while (i < n)
	{
		c[k++] = a[i++]; // 배열 a에 수가 남아있으면 나머지를 결과 배열에 넣고
	}
	while (j < m)
	{
		c[k++] = b[j++]; // 배열 b에 수가 남아있으면 나머지를 결과 배열에 넣는다
	}

	for (int i = 0; i < n + m; i++)
	{
		printf("%d ", c[i]);
	}
	puts("");

	return 0;
}