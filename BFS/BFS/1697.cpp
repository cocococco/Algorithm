/*
BFS
�Ÿ��� �ּҰ��� ���ϴ� ���� -> ����ġ = �Ÿ�
�ð��� �ּҰ��� ���ϴ� ���� -> ����ġ = �ð�

ť�� �������� ��ġ�� �־�� �̵���Ŵ
�� �� �湮�� ���� �ٽ� �湮���� �ʴ� ���� ���� ������,
���� �迭�� üũ�ϸ鼭 �湮.
*/

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200000; // 0 <= n, m <= 100000
bool check[MAX + 1]; // i�� �湮�ߴ���
int dist[MAX + 1]; // i�� �� ������ �湮�ߴ���

int main()
{
	int n, m; // ������ ��ġ, ���� ��ġ
	cin >> n >> m;

	check[n] = true; // �ʱⰪ
	dist[n] = 0;
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int now = q.front(); // now�� front
		q.pop(); // ť���� pop

		if (now - 1 >= 0) // �ڷ� �ȱ�
		{
			if (check[now - 1] == false) // �湮 ��������
			{
				q.push(now - 1); // ť�� push
				check[now - 1] = true; // üũ
				dist[now - 1] = dist[now] + 1; // ����ġ +1
			}
		}
		if (now + 1 < MAX) // ������ �ȱ�
		{
			if (check[now + 1] == false)
			{
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (now * 2 < MAX) // �ٱ�
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