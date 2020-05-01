#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, cnt = 0;
vector<int> a;

void go(int index, int sum)
{
	if (sum == s && index == n)
	{
		cnt++;
		return;
	}
	if (index == n && sum != s) return;

	go(index + 1, sum + a[index]);

	go(index + 1, sum);

	return;
}

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	go(0, 0);

	if (s == 0) cnt -= 1; // 중요!
	// 아무것도 선택하지 않는 공집합이 있을 수 있다.
	// 그러므로 합이 0인 것을 찾을 때에는 공집합 하나를
	// 빼 줘야 한다.

	cout << cnt << '\n';

	return 0;
}