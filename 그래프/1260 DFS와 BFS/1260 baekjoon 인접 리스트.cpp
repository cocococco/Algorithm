//#define _CRT_SECURE_NO_WARNINGS
//
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector<int> a[1001]; // � ����� ����Ǿ� �ִ��� ����� ���� ����Ʈ
//bool check[1001]; // �湮�ߴ��� Ȯ���ϱ� ���� �迭
//
//void dfs(int node) // ��� ���
//{
//	check[node] = true; // �湮 üũ�� true�� ����
//	printf("%d ", node); // �湮�� ��� ���
//
//	// ���� ��带 �湮 �Ϸ������� ���� ��带 ����
//	for (int i = 0; i < a[node].size(); i++)
//	{
//		int next = a[node][i]; // ���� ��忡 ����� ���� ��带 next�� ����
//		if (check[next] == false) // �� next ��带 �湮���� �ʾ�����
//		{
//			dfs(next); // �� next ��带 dfs�� ���ڷ� ���� = �湮�ϱ�
//		}
//	}
//}
//
//void bfs(int start)
//{
//	queue<int> q;
//	memset(check, false, sizeof(check)); // �տ��� ����ߴ� check �迭�� ���� ��� false�� �ʱ�ȭ
//
//	check[start] = true; // �湮�ߴٴ� ǥ�÷� check �迭�� start�� ���� true�� ����
//	q.push(start); // ť�� start �߰�
//
//	while (!q.empty()) // ť�� ����Ͽ� �ݺ����� ��� �ݺ����� �ߴ����� ����
//	{
//		int node = q.front(); // ���� ���� ť�� ���� �� ����
//		q.pop(); // ���� ��带 �˾����� ť���� ����
//		printf("%d ", node); // ť���� �����鼭 ����� �Ѵ�
//
//		// ���� ���� ����� �ٸ� ������ ã�� ���� �ݺ�
//		for (int i = 0; i < a[node].size(); i++)
//		{
//			int next = a[node][i]; // ���� ����Ʈ���� ���� ���� ����� ���� ��带 next�� ����
//			if (check[next] == false) // ���� �� next ��带 ���� �湮���� �ʾҴٸ�
//			{
//				check[next] = true; // �湮 ǥ�ø� true�� �ٲ�
//				q.push(next); // ť�� �� next ��带 ����
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n, m, start;
//	scanf("%d %d %d", &n, &m, &start);
//
//	for (int i = 0; i < m; i++)
//	{
//		int u, v;
//		scanf("%d %d", &u, &v);
//
//		// ���� ������ ���� ����Ʈ�� ����
//		a[u].push_back(v);
//		a[v].push_back(u);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		// ������ ������ '��ȣ�� ���� ���� ���� �湮�϶�'�� �����Ƿ� ���� ��ȣ���� ���۵ǵ��� sorting
//		sort(a[i].begin(), a[i].end());
//	}
//
//	dfs(start);
//	puts(""); // �ڵ����� ���� ���ڸ� ������ִ� puts�� ����� �ƹ��� ���ڿ��� �Է����� �������ν� ������ ���� ���ڸ� ����ϰ� ��
//
//	bfs(start);
//	puts("");
//
//	return 0;
//}