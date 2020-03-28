#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int map[30][30];
int cnt = 0;
int houses[25 * 25];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n;
queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		// 단지 내 집의 개수를 셀 때에는 push를 할 때에나 pop을 할 때에나 상관은 없음
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (map[nx][ny] == 1)
				{
					map[nx][ny] = 0;
					houses[cnt - 1]++;
					// push를 할 때 방문 체크를 해줘야 함. 그렇지 않으면 다음 겹치는 위치에서 또 방문을 하게 되므로 개수를 더 세게 됨.
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 정수 하나씩 입력받기 위해 %1d를 사용함!!
			// scanf에서 & 빼먹지 않도록 주의
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				cnt++; // 단지 수 증가
				map[i][j] = 0;
				houses[cnt - 1]++;
				q.push(make_pair(i, j));
				bfs();
			}
		}
	}

	sort(houses, houses + cnt); // 단지 수만큼의 houses 값들을 오름차순으로 sorting
	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++)
	{
		printf("%d\n", houses[i]);
	}

	return 0;
}