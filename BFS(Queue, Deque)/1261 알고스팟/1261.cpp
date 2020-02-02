#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

// check �迭 �����ϰ� dist -1�� Ȯ����
int d[555][555]; // distance
int a[555][555]; // map
int n, m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	// �� ���� �Է¹ޱ�
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
			// %1d�� ���ӵ� ���ڹ��ڿ��� ���� 1�ڸ��� �Է¹��� �� �ְ� ����
			d[i][j] = -1; // dist initialization
		}
	}
	// ť 2�� ��� / �� ���
	// �ʱⰪ
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

		for (int k = 0; k < 4; k++) // �����¿� 4����
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (d[nx][ny] == -1) // �湮x�� ��
				{
					if (a[nx][ny] == 0) // ��ĭ�� ��
					{
						d[nx][ny] = d[x][y]; // Ƚ�� �߰�x
						//q.push(make_pair(nx, ny)); // ���� ť�� ����
						q.push_front(make_pair(nx, ny));
					}
					else // �� �μ���� �� ��
					{
						d[nx][ny] = d[x][y] + 1; // �� �μ��� Ƚ�� �߰� + 1
						//next_queue.push(make_pair(nx, ny)); // ���� ť�� ����
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
		//if (q.empty()) // ���� ť�� ��ü
		//{
		//	q = next_queue;
		//	next_queue = queue<pair<int, int>>();
		//}
	}
	printf("%d\n", d[n - 1][m - 1]);
	return 0;
}