#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

	int ans = a[0];
	for (int i = 1; i < n; i++)
	{
		a[i] += a[i - 1];
		ans += a[i];
	}

	cout << ans << '\n';
	return 0;
}