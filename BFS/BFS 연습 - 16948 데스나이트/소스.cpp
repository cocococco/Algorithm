#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dx[] = { 2,0,-2,-2,0,2 };
int dy[] = { -1,-2,-1,1,2,1 };
bool check[210][210]; // [y][x], [c][r]
int dist[210][210];

int main()
{
	int n, r1, r2, c1, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;

	queue<pair<int, int>> q;
	q.push(make_pair(r1, c1));
	dist[c1][r1] = 0;
	check[c1][r1] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!check[ny][nx] && nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				q.push(make_pair(nx, ny));
				check[ny][nx] = true;
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}
	if (!check[c2][r2])
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << dist[c2][r2] << '\n';
	}

	return 0;
}