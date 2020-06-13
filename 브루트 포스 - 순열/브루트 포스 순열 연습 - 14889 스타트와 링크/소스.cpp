#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[20][20];

int calc(vector<int> &v, int n)
{
	int ans = 0, first = 0, second = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (v[i] == 0 && v[j] == 0)
			{
				first += a[i][j];
			}
			else if (v[i] == 1 && v[j] == 1)
			{
				second += a[i][j];
			}
		}
	}

	ans = first - second;
	if (ans < 0) ans = -ans;

	return ans;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	vector<int> v(n);
	for (int i = n / 2; i < n; i++)
	{
		v[i] = 1;
	}

	int min = 1000;
	do
	{
		int tmp = calc(v, n);
		if (tmp < min) min = tmp;
	} while (next_permutation(v.begin(), v.end()));

	cout << min << '\n';

	return 0;
}