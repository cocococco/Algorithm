#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

// check 배열 사용안하고 dist -1로 확인함
int d[555][555]; // distance
int a[555][555]; // map
int n, m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	// 맵 형태 입력받기
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
			// %1d는 연속된 숫자문자열을 정수 1자리씩 입력받을 수 있게 해줌
			d[i][j] = -1; // dist initialization
		}
	}
	// 큐 2개 사용 / 덱 사용
	// 초기값
	//queue<pair<int, int>> q;
	//queue<pair<int, int>> next_queue;
	//q.push(make_pair(0, 0));
	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	d[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		//q.pop();
		q.pop_front();

		for (int k = 0; k < 4; k++) // 상하좌우 4방향
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (d[nx][ny] == -1) // 방문x일 때
				{
					if (a[nx][ny] == 0) // 빈칸일 때
					{
						d[nx][ny] = d[x][y]; // 횟수 추가x
						//q.push(make_pair(nx, ny)); // 현재 큐에 넣음
						q.push_front(make_pair(nx, ny));
					}
					else // 벽 부수어야 할 때
					{
						d[nx][ny] = d[x][y] + 1; // 벽 부수는 횟수 추가 + 1
						//next_queue.push(make_pair(nx, ny)); // 다음 큐에 넣음
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
		//if (q.empty()) // 다음 큐로 교체
		//{
		//	q = next_queue;
		//	next_queue = queue<pair<int, int>>();
		//}
	}
	printf("%d\n", d[n - 1][m - 1]);
	return 0;
}