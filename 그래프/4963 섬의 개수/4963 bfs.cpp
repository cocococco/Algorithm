#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int map[55][55];
queue<pair<int, int>> q;
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int h, w;
// (w, h), (x, y), (i, j) 순서 조심하기

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < h && ny >= 0 && ny < w)
			{
				if (map[nx][ny] == 1)
				{
					map[nx][ny] = 0;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	cin >> w >> h;
	if (h == 0 && w == 0) return 0;

	do
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1)
				{
					map[i][j] = 0;
					cnt++;
					q.push(make_pair(i, j));
					bfs();
				}
			}
		}
		cout << cnt << '\n';

		cin >> w >> h;
	} while (h != 0 && w != 0);
}