#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	vector<int> a;
	for (int i = 0; i < 4; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			a.push_back(i);
		}
	}

	long long min = 1000000000;
	long long max = -1000000000;
	do
	{
		int sum = s[0];
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] == 0)
			{
				sum += s[i + 1];
			}
			else if (a[i] == 1)
			{
				sum -= s[i + 1];
			}
			else if (a[i] == 2)
			{
				sum *= s[i + 1];
			}
			else
			{
				sum /= s[i + 1];
			}
		}
		if (sum > max) max = sum;
		if (sum < min) min = sum;
	} while (next_permutation(a.begin(), a.end()));

	cout << max << '\n' << min << '\n';

	return 0;
}