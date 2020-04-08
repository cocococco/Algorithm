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
	// 1 << n은 00000000 00000001에서 n번왼쪽으로 비트 연산을 한다는 뜻. ex) 1 << 8 은 00000001 00000000 이 된다. 따라서 2의 제곱수처럼 사용할 수 있다. 그러므로 (1 << n) -1 은 2^n-1이다.
	solve(n, 1, 3);

	return 0;
}