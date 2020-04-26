#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> lotto;

void solve(vector<int> &a, int index, int cnt)
{
	if (cnt == 6) // 번호를 다 정한 경우
	{
		for (int num : lotto)
		{
			printf("%d ", num); // 출력
		}
		printf("\n");
		return;
	}

	// 번호를 더 골라야 하는 경우
	int n = a.size();
	if (n == index) return; // 불가능한 경우

	// 해당 index의 번호를 고르는 경우
	lotto.push_back(a[index]);
	solve(a, index + 1, cnt + 1);

	// 해당 index의 번호를 고르지 않는 경우
	lotto.pop_back();
	solve(a, index + 1, cnt);
}

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		solve(a, 0, 0);
		cout << '\n';
	}
	return 0;
}