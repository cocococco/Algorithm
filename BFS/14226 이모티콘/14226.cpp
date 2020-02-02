#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int d[1001][1001];
// ������ check �迭���� �迭 2���� ����Ͽ� �湮 ���� Ȯ�ΰ�, �Ÿ� üũ�� �ϴµ� �迭 �ϳ��� �����.

int main()
{
	int n;
	cin >> n;

	// -1�� �ʱ�ȭ�Ͽ� -1�̸� �湮x�� üũ �����ϰ�, �Ÿ��� 0���� �����Ͽ� ���ÿ� �� �迭�� Ȯ�� �����ϰ� ��.
	memset(d, -1, sizeof(d)); // d �迭�� ��� -1�� ä���, for������ �� ���� �� �ֱ� ������ ���
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0)); // �ʱⰪ�� ȭ�鿡 �̸�Ƽ�� 1��, Ŭ�����忡 0����.
	d[1][0] = 0;

	while (!q.empty())
	{
		int s, c;
		tie(s, c) = q.front(); // pair���� �ѹ��� ������ ����
		q.pop();

		// ���� (s, c) -> (s, c)
		if (d[s][s] == -1)
		{
			d[s][s] = d[s][c] + 1;
			q.push(make_pair(s, s));
		}
		// �ٿ��ֱ� (s, c) -> (s+c, c)
		if (s + c <= n && d[s + c][c] == -1)
		{
			d[s + c][c] = d[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		// ���� (s, c) -> (s-1, c)
		if (s - 1 >= 0 && d[s - 1][c] == -1)
		{
			d[s - 1][c] = d[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}
	}

	// n���� �̸�Ƽ���� ȭ�鿡 ���� �� �Ÿ��� �ּҰ� ã��
	int ans = -1; // �ּҰ��� -1�� �ʱ�ȭ
	for (int i = 0; i <= n; i++) // �ּ� 0������ �ִ� n������ Ŭ�����忡 ����� �� �����ϱ�.
	{
		if (d[n][i] != -1) // ����� ������ ������
		{
			// -1�̸� �ʱⰪ�̴� �׳� �־��ְ�, �ƴϸ� ans�� ����� ���� ���Ͽ� �ּҰ��� ans�� �־���
			if (ans == -1 || ans > d[n][i])
			{
				ans = d[n][i];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}