#include <iostream>
#include <queue>

using namespace std;

bool check[200001];
int dist[200001];

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	dist[n] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x - 1 >= 0 && !check[x - 1])
		{
			q.push(x - 1);
			check[x - 1] = true;
			dist[x - 1] = dist[x] + 1;
		}
		if (x + 1 < 200000 && !check[x + 1])
		{
			q.push(x + 1);
			check[x + 1] = true;
			dist[x + 1] = dist[x] + 1;
		}
		if (x * 2 < 200000 && !check[x * 2])
		{
			q.push(x * 2);
			check[x * 2] = true;
			dist[x * 2] = dist[x] + 1;
		}
	}
	cout << dist[k] << '\n';

	return 0;
}