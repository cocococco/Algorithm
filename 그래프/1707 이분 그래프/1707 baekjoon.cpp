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
		int next = a[node][i]; // 현재 node에 연결된 다음 노드를 next에 저장
		if (color[next] == 0) // 아직 방문하지 않았으면
		{
			bfs(next, 3 - c); // 1과 2로 구분하기 위해서 3에서 뺌. 1이었으면 다음은 2가 되고 2였으면 다음은 1이 됨
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

		// 각 테스트 케이스마다 초기화해줌
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			color[i] = 0;
		}

		// 간선에 대한 정보를 입력받아 a에 저장
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			a[u].push_back(v);
			a[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) // 연결이 끊긴 형태의 그래프가 있을 수 있으므로 모든 노드 반복문을 돌려서 color 정보가 없으면 dfs를 호출한다.
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
				// i와 j가 연결되어 있는데 color 정보가 같으면 이분 그래프가 아님
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