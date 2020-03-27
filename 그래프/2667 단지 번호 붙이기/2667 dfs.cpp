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
//	map[x][y] = 0; // check �迭�� ������� �ʰ� map ������ 0���� �ٲٴ� ������ �湮 Ȯ���� ��
//	houses[cnt - 1]++; // ���� �� ����
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx >= 0 && nx < n && ny >= 0 && ny < n) // ���� �Ѿ�� �ʵ��� ���� �� �߰����ֱ�
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
//			// ���� �ϳ��� �Է¹ޱ� ���� %1d�� �����!!
//			// scanf���� & ������ �ʵ��� ����
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
//				cnt++; // ���� �� ����
//				bfs(i, j);
//			}
//		}
//	}
//
//	sort(houses, houses + cnt); // ���� ����ŭ�� houses ������ ������������ sorting
//	printf("%d\n", cnt);
//
//	for (int i = 0; i < cnt; i++)
//	{
//		printf("%d\n", houses[i]);
//	}
//
//	return 0;
//}