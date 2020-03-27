#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[20001];
int color[20001];

void bfs(int node, int c)
{
	color[node] = c;

	for (vector<int>::size_type i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i]; // ���� node�� ����� ���� ��带 next�� ����
		if (color[next] == 0) // ���� �湮���� �ʾ�����
		{
			bfs(next, 3 - c); // 1�� 2�� �����ϱ� ���ؼ� 3���� ��. 1�̾����� ������ 2�� �ǰ� 2������ ������ 1�� ��
		}
	}
}

int main()
{
	int t;
	scanf("%d\n", &t);

	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		// �� �׽�Ʈ ���̽����� �ʱ�ȭ����
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			color[i] = 0;
		}

		// ������ ���� ������ �Է¹޾� a�� ����
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			a[u].push_back(v);
			a[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) // ������ ���� ������ �׷����� ���� �� �����Ƿ� ��� ��� �ݺ����� ������ color ������ ������ dfs�� ȣ���Ѵ�.
		{
			if (color[i] == 0)
			{
				bfs(i, 1);
			}
		}

		bool ok = true;

		for (int i = 1; i <= n; i++)
		{
			for (vector<int>::size_type k = 0; k < a[i].size(); k++)
			{
				// i�� j�� ����Ǿ� �ִµ� color ������ ������ �̺� �׷����� �ƴ�
				int j = a[i][k];
				if (color[i] == color[j])
				{
					ok = false;
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}