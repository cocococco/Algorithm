#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
now -> next (next�� �� �� ������ �湮x��)
next�� dist�� now�� dist + 1��
dist�� ���� ���� �� ������ �� ������ ��δ� ���� �Ұ�.
�׷��� from�迭�� �����
from[next] = now�� ��� �Դ����� ����.
*/

const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];
int from[MAX + 1];

void print(int n, int m)
{
	if (n != m) // �������� �ƴ϶��
	{
		print(n, from[m]); // n���� from[m]���� ��θ� ���
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
	print(n, m); // n���� m������ ��θ� ���

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