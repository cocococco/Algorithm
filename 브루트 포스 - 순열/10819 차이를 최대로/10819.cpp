#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculate(vector<int> &a)
{
	int sum = 0;
	for (int i = 1; i < a.size(); i++)
	{
		sum += abs(a[i] - a[i - 1]);
		// abs = 절대값 함수. C++11 이전에서는 cstlib(int), cmath(실수)를 써야 함
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;
	do
	{
		int temp = calculate(a);
		ans = max(ans, temp);
	} while (next_permutation(a.begin(), a.end()));

	cout << ans << '\n';
	return 0;
}