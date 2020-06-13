/*메모리 초과 나옴. 백준에서. 왜그런지 모르겠음*/
#include <iostream>
#include <queue>

using namespace std;

int dist[101];
int nxt[101];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 101; i++)
	{
		dist[i] = -1;
	}

	for (int i = 0; i < 101; i++)
	{
		nxt[i + 1] = i + 1;
	}

	for (int i = 0; i < n + m; i++)
	{
		int x, y;
		cin >> x >> y;
		nxt[x] = y;
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) // *100
	{
		int x = q.front();
		q.pop();

		for (int i = 6; i >= 1; i--) // *6
		{
			int nx = x + i;

			if (dist[nx] = -1 && nx <= 100)
			{
				nx = nxt[nx];
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}

	cout << dist[100] << '\n';
	return 0;
}