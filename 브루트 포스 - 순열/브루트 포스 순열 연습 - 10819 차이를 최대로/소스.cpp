#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calc(vector<int> x, int n)
{
	int ans = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int tmp = x[i] - x[i + 1];
		if (tmp < 0) tmp = -tmp;
		ans += tmp;
	}

	return ans;
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
	int max = 0;

	do
	{
		int tmp = calc(a, n);
		if (max < tmp) max = tmp;
	} while (next_permutation(a.begin(), a.end()));

	cout << max << '\n';

	return 0;
}