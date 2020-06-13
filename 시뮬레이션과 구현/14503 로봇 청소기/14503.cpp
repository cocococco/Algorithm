#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[50][50];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int x = c;
	int y = r;
	int dir = d;
	int cnt = 0;
	int clean = 1;
	a[y][x] = 2;

	while (true)
	{
		dir - 1 < 0 ? dir = 3 : dir -= 1;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (a[ny][nx] == 0)
		{
			a[ny][nx] = 2;
			x = nx;
			y = ny;
			clean++;
			cnt = 0;
		}
		else
		{
			cnt++;
			if (cnt > 3)
			{
				x -= dx[dir];
				y -= dy[dir];
				cnt = 0;

				if (a[y][x] == 1)
				{
					cout << clean << '\n';
					break;
				}
			}
		}
	}

	return 0;
}