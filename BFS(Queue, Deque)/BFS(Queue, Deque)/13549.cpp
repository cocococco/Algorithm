/*
BFS에서는 항상 거리가 1차이나는 것만 들어감. 따라서 큐를 두개 만들면 해결 가능
큐 사용 / 덱 사용
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
		q.pop_front(); // 앞에서부터 꺼냄

		if (now * 2 < MAX)
		{
			if (c[now * 2] == false)
			{
				//q.push(now * 2);
				q.push_front(now * 2); // 거리가 0일 때에는 앞에 넣음
				c[now * 2] = true;
				d[now * 2] = d[now]; // 0초
			}
		}
		if (now - 1 >= 0)
		{
			if (c[now - 1] == false)
			{
				//next_queue.push(now - 1); // 1초는 다음 큐에 넣음
				q.push_back(now - 1); // 거리가 1일 때에는 뒤에 넣음
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
		//if (q.empty()) // 큐에 있는 원소 다 pop하면 다음 큐로 교체
		//{
		//	q = next_queue;
		//	next_queue = queue<int>();
		//}
	}
	cout << d[m] << '\n';
	return 0;
}