#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
now -> next (next로 갈 때 무조건 방문x임)
next의 dist는 now의 dist + 1임
dist로 가장 빠른 건 저장할 수 있지만 경로는 저장 불가.
그래서 from배열을 사용함
from[next] = now로 어디서 왔는지를 저장.
*/

const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];
int from[MAX + 1];

void print(int n, int m)
{
	if (n != m) // 시작점이 아니라면
	{
		print(n, from[m]); // n부터 from[m]까지 경로를 출력
	}
	cout << m << ' ';
}

int main()
{
	int n, m;
	cin >> n >> m;

	queue<int> q;

	q.push(n);
	check[n] = true;
	dist[n] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now - 1 >= 0)
		{
			if (check[now - 1] == false)
			{
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;

				from[now - 1] = now;
			}
		}
		if (now + 1 < MAX)
		{
			if (check[now + 1] == false)
			{
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;

				from[now + 1] = now;
			}
		}
		if (now * 2 < MAX)
		{
			if (check[now * 2] == false)
			{
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;

				from[now * 2] = now;
			}
		}
	}
	cout << dist[m] << '\n';
	print(n, m); // n부터 m까지의 경로를 출력

	/* print with stack
	stack<int> ans;
	for (int i = m; i != n; i = from[i])
	{
		ans.push(i);
	}
	ans.push(n);
	while (!ans.empty())
	{
		cout << ans.top() << ' ';
		ans.pop();
	}
	*/

	cout << '\n';
	return 0;
}