#include <iostream>

using namespace std;

int memo[1000001];

int dp(int n)
{
	// 점화식과 맞지 않는 초기값은 꼭 지정해줌
	if (n == 1) return 0;

	// 메모해 둔 내용이 있다면 리턴
	if (memo[n] > 0) return memo[n];
	// 없다면 계산
	else
	{
		// 먼저 기본값으로 1을 빼는 경우를 저장해놓는다.
		memo[n] = dp(n - 1) + 1;

		if (n % 3 == 0)
		{
			int tmp = dp(n / 3) + 1;
			// 3으로 나눈 결과가 min이면 memo값 변경
			if (memo[n] > tmp)
			{
				memo[n] = tmp;
			}
		}
		if (n % 2 == 0)
		{
			int tmp = dp(n / 2) + 1;
			// 2로 나눈 결과가 min이면 memo값 변경
			if (memo[n] > tmp)
			{
				memo[n] = tmp;
			}
		}
		// 이렇게 모든 경우를 확인하고 min을 구하지 않으면 반례에 틀려버림.
	}
	return memo[n];
}

int main()
{
	int n;
	cin >> n;
	cout << dp(n) << '\n';
	return 0;
}