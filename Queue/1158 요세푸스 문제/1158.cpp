#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	printf("<");

	for (int i = 0; i < n - 1; i++) // ������ 1�� ���� �� ���
	{
		for (int j = 0; j < m - 1; j++)
		{
			q.push(q.front());
			q.pop();
		} // m-1����ŭ pop�ؼ� �ڿ� push��
		printf("%d, ", q.front());
		q.pop(); // m��° ������ ���
	}
	printf("%d>\n", q.front()); // ������ ���� ������ ��ȣ�� �ݱ� ���� ���� ���

	return 0;
}