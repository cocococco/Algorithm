//#define _CRT_SECURE_NO_WARNINGS
//
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//int map[30][30];
//int cnt = 0;
//int houses[25 * 25];
//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, -1, 0, 1 };
//int n;
//
//void bfs(int x, int y)
//{
//	map[x][y] = 0; // check 배열을 사용하지 않고 map 정보를 0으로 바꾸는 것으로 방문 확인을 함
//	houses[cnt - 1]++; // 집의 수 증가
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx >= 0 && nx < n && ny >= 0 && ny < n) // 맵을 넘어가지 않도록 조건 꼭 추가해주기
//		{
//			if (map[nx][ny] == 1)
//			{
//				bfs(nx, ny);
//			}
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			// 정수 하나씩 입력받기 위해 %1d를 사용함!!
//			// scanf에서 & 빼먹지 않도록 주의
//			scanf("%1d", &map[i][j]);
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (map[i][j] == 1)
//			{
//				cnt++; // 단지 수 증가
//				bfs(i, j);
//			}
//		}
//	}
//
//	sort(houses, houses + cnt); // 단지 수만큼의 houses 값들을 오름차순으로 sorting
//	printf("%d\n", cnt);
//
//	for (int i = 0; i < cnt; i++)
//	{
//		printf("%d\n", houses[i]);
//	}
//
//	return 0;
//}