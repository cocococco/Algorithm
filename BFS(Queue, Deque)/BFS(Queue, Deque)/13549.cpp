/*
BFS������ �׻� �Ÿ��� 1���̳��� �͸� ��. ���� ť�� �ΰ� ����� �ذ� ����
ť ��� / �� ���
*/
#include <iostream>
#include <queue>
#include <deque>

using namespace std;

bool c[1000000];
int d[1000000];
int MAX = 1000000;

int main()
{
	int n, m;
	cin >> n >> m;
	c[n] = true;
	d[n] = 0;
	//queue<int> q;
	//queue<int> next_queue;
	//q.push(n);
	deque<int> q;
	q.push_back(n);

	while (!q.empty())
	{
		int now = q.front();
		//q.pop();
		q.pop_front(); // �տ������� ����

		if (now * 2 < MAX)
		{
			if (c[now * 2] == false)
			{
				//q.push(now * 2);
				q.push_front(now * 2); // �Ÿ��� 0�� ������ �տ� ����
				c[now * 2] = true;
				d[now * 2] = d[now]; // 0��
			}
		}
		if (now - 1 >= 0)
		{
			if (c[now - 1] == false)
			{
				//next_queue.push(now - 1); // 1�ʴ� ���� ť�� ����
				q.push_back(now - 1); // �Ÿ��� 1�� ������ �ڿ� ����
				c[now - 1] = true;
				d[now - 1] = d[now] + 1;
			}
		}
		if (now + 1 < MAX)
		{
			if (c[now + 1] == false)
			{
				//next_queue.push(now + 1);
				q.push_back(now + 1);
				c[now + 1] = true;
				d[now + 1] = d[now] + 1;
			}
		}
		//if (q.empty()) // ť�� �ִ� ���� �� pop�ϸ� ���� ť�� ��ü
		//{
		//	q = next_queue;
		//	next_queue = queue<int>();
		//}
	}
	cout << d[m] << '\n';
	return 0;
}