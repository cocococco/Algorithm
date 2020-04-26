#include <iostream>

using namespace std;

int go(int sum, int goal)
{
	if (sum > goal) // 불가능한 경우
	{
		return 0;
	}
	if (sum == goal) // 정답을 찾은 경우
	{
		return 1; // 답의 개수를 구하기 위해 답을 구하면 1 리턴
	}
	int now = 0;
	for (int i = 1; i <= 3; i++)
	{
		now += go(sum + i, goal); // 1, 2, 3씩 더하면서 재귀 호출
	}
	return now; // 모든 방법이 끝나면 개수 리턴
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}

	return 0;
}