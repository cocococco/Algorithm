#include <cstdio>
#include <queue>

using namespace std;

int n, m;
int a[100][100];
bool check[100][100];
int dist[100][100];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	queue<pair<int, int>> q;

	q.push(make_pair(0, 0)); // 1. push
	check[0][0] = true; // 2. check
	dist[0][0] = 1; // 3. dist

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second; // 1. front
		q.pop(); // 2. pop

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (check[nx][ny] == false && a[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny)); // 1. push
					check[nx][ny] = true; // 2. check
					dist[nx][ny] = dist[x][y] + 1; // 3. dist
				}
			}
		}
	}

	printf("%d\n", dist[n - 1][m - 1]);
	return 0;
}