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

	for (int i = 0; i < n - 1; i++) // 마지막 1개 빼고 다 출력
	{
		for (int j = 0; j < m - 1; j++)
		{
			q.push(q.front());
			q.pop();
		} // m-1개만큼 pop해서 뒤에 push함
		printf("%d, ", q.front());
		q.pop(); // m번째 정수는 출력
	}
	printf("%d>\n", q.front()); // 마지막 남은 정수는 괄호를 닫기 위해 따로 출력

	return 0;
}