/*
BFS
거리의 최소값을 구하는 문제 -> 가중치 = 거리
시간의 최소값을 구하는 문제 -> 가중치 = 시간

큐에 수빈이의 위치를 넣어가며 이동시킴
한 번 방문한 곳은 다시 방문하지 않는 것이 좋기 때문에,
따로 배열에 체크하면서 방문.
*/

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200000; // 0 <= n, m <= 100000
bool check[MAX + 1]; // i를 방문했는지
int dist[MAX + 1]; // i를 몇 번만에 방문했는지

int main()
{
	int n, m; // 수빈이 위치, 동생 위치
	cin >> n >> m;

	check[n] = true; // 초기값
	dist[n] = 0;
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int now = q.front(); // now는 front
		q.pop(); // 큐에서 pop

		if (now - 1 >= 0) // 뒤로 걷기
		{
			if (check[now - 1] == false) // 방문 안했으면
			{
				q.push(now - 1); // 큐에 push
				check[now - 1] = true; // 체크
				dist[now - 1] = dist[now] + 1; // 가중치 +1
			}
		}
		if (now + 1 < MAX) // 앞으로 걷기
		{
			if (check[now + 1] == false)
			{
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (now * 2 < MAX) // 뛰기
		{
			if (check[now * 2] == false)
			{
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}
	cout << dist[m] << '\n';
	return 0;
}