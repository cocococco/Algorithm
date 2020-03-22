/*생각하기 너무 어렵다*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1); // 카드팩

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	vector<int> d(n + 1); // 최대비용
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// i장 구매 최대비용 = (j장 카드팩 구매비용 + i-j장 구매 최대비용)의 최대값
			d[i] = max(d[i], d[i - j] + a[j]);
		}
	}
	cout << d[n] << '\n';
	return 0;
}