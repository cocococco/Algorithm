// 다시 봐야함 왜틀렸는지 모르겠음
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
	cout << cnt << '\n';

	return 0;
}