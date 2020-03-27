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
//vector<int> a[1001]; // 어떤 노드들과 연결되어 있는지 저장된 인접 리스트
//bool check[1001]; // 방문했는지 확인하기 위한 배열
//
//void dfs(int node) // 재귀 사용
//{
//	check[node] = true; // 방문 체크를 true로 변경
//	printf("%d ", node); // 방문한 노드 출력
//
//	// 현재 노드를 방문 완료했으니 다음 노드를 추적
//	for (int i = 0; i < a[node].size(); i++)
//	{
//		int next = a[node][i]; // 현재 노드에 연결된 인접 노드를 next에 저장
//		if (check[next] == false) // 그 next 노드를 방문하지 않았으면
//		{
//			dfs(next); // 그 next 노드를 dfs에 인자로 전달 = 방문하기
//		}
//	}
//}
//
//void bfs(int start)
//{
//	queue<int> q;
//	memset(check, false, sizeof(check)); // 앞에서 사용했던 check 배열의 값을 모두 false로 초기화
//
//	check[start] = true; // 방문했다는 표시로 check 배열의 start를 먼저 true로 변경
//	q.push(start); // 큐에 start 추가
//
//	while (!q.empty()) // 큐를 사용하여 반복문을 계속 반복할지 중단할지 정함
//	{
//		int node = q.front(); // 현재 노드는 큐의 가장 앞 원소
//		q.pop(); // 현재 노드를 알았으니 큐에서 꺼냄
//		printf("%d ", node); // 큐에서 꺼내면서 출력을 한다
//
//		// 현재 노드와 연결된 다른 노드들을 찾기 위해 반복
//		for (int i = 0; i < a[node].size(); i++)
//		{
//			int next = a[node][i]; // 인접 리스트에서 현재 노드와 연결된 다음 노드를 next에 넣음
//			if (check[next] == false) // 만약 그 next 노드를 아직 방문하지 않았다면
//			{
//				check[next] = true; // 방문 표시를 true로 바꿈
//				q.push(next); // 큐에 그 next 노드를 넣음
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
//		// 연결 정보를 인접 리스트에 저장
//		a[u].push_back(v);
//		a[v].push_back(u);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		// 문제의 조건이 '번호가 작은 것을 먼저 방문하라'고 했으므로 적은 번호부터 시작되도록 sorting
//		sort(a[i].begin(), a[i].end());
//	}
//
//	dfs(start);
//	puts(""); // 자동으로 개행 문자를 출력해주는 puts를 사용해 아무런 문자열도 입력하지 않음으로써 오로지 개행 문자만 출력하게 함
//
//	bfs(start);
//	puts("");
//
//	return 0;
//}