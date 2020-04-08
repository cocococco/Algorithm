#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

void solve(int n, int x, int y)
{
	if (n == 0) return;

	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	// 1 << n�� 00000000 00000001���� n���������� ��Ʈ ������ �Ѵٴ� ��. ex) 1 << 8 �� 00000001 00000000 �� �ȴ�. ���� 2�� ������ó�� ����� �� �ִ�. �׷��Ƿ� (1 << n) -1 �� 2^n-1�̴�.
	solve(n, 1, 3);

	return 0;
}