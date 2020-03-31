#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int map[100][100];
	queue<pair<int, int>> q;
	int n, m;
	int cnt = 1;
	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, -1, 0, 1 };

	scanf("%d %d", &n, &m); // n : 높이, m : 너비

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int size = q.size();
		cnt++;

		for (int i = 0; i < size; i++)
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx == n - 1 && ny == m - 1)
				{
					printf("%d\n", cnt);
					return 0;
				}

				if (!(nx == 0 && ny == 0) && nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1)
				{
					map[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	printf("%d\n", map[n - 1][m - 1]);

	return 0;
}