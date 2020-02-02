#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int d[200][200];
int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };

int main()
{
	int n, r1, r2, c1, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	q.push(make_pair(r1, c1));
	d[r1][c1] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 6; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n)
			{
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << d[r2][c2] << '\n';
	return 0;
}