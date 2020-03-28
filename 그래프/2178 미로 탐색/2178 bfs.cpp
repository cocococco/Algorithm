#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int map[111][111];
int n, m;
queue<pair<int, int>> q;
int check[111][111];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int cnt = 1;

void bfs(int x, int y)
{
	while (!q.empty())
	{
		int size = q.size();
		cnt++;

		for (int j = 0; j < size; j++)
		{
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (check[nx][ny] == false)
					{
						if (nx == n - 1 && ny == m - 1) return;

						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m); // 높이 : n, 너비 : m

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] == false)
			{
				check[i][j] = true;
				q.push(make_pair(i, j));
				bfs(i, j);
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}