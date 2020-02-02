#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[10][10]; // 초기 맵 저장
int b[10][10];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs()
{
	queue<pair<int, int>> q;

	// 바이러스가 있는 위치를 큐에 넣음
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			b[i][j] = a[i][j];
			if (b[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				// 빈칸일 때에만 바이러스로 바꾸고 큐에 넣음
				if (b[nx][ny] == 0)
				{
					b[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	// 바이러스가 퍼지지 않은 안전 영역의 크기 세기
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 0)
			{
				cnt += 1;
			}
		}
	}
	return cnt;
}

int main()
{
	// 맵 정보 입력받음
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int ans = 0;
	// 순서대로 벽 한번씩 세우기
	for (int x1 = 0; x1 < n; x1++) // 벽1
	{
		for (int y1 = 0; y1 < m; y1++)
		{
			// 빈칸이 아니면 넘어감
			if (a[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < n; x2++) // 벽2
			{
				for (int y2 = 0; y2 < m; y2++)
				{
					if (a[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < n; x3++) // 벽3
					{
						for (int y3 = 0; y3 < m; y3++)
						{
							if (a[x3][y3] != 0) continue;
							// 같은 곳에 벽 세우지 않기
							if (x1 == x2 && y1 == y2) continue;
							if (x1 == x3 && y1 == y3) continue;
							if (x2 == x3 && y2 == y3) continue;
							// 다 걸렀으면 벽 세우기
							a[x1][y1] = 1;
							a[x2][y2] = 1;
							a[x3][y3] = 1;
							int cur = bfs(); // 벽 3개 다 세운 후 BFS
							if (ans < cur) ans = cur; // 안전영역 크기의 최대값 저장
							// 벽 위치 초기화
							a[x1][y1] = 0;
							a[x2][y2] = 0;
							a[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}