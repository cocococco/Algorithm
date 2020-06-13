#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string a[111][111];

int main()
{
	int n, w;
	cin >> n >> w;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<vector<string>> groups;
	int size = n / 2;
	int rot = w;

	for (int k = 0; k < size; k++)
	{
		vector<string> group;

		if (rot < 0)
		{
			for (int j = k; j < n - k - 1; j++)
			{
				group.push_back(a[k][j]);
			}
			for (int i = k; i < n - k - 1; i++)
			{
				group.push_back(a[i][n - k - 1]);
			}
			for (int j = n - k - 1; j > k; j--)
			{
				group.push_back(a[n - k - 1][j]);
			}
			for (int i = n - k - 1; i > k; i--)
			{
				group.push_back(a[i][k]);
			}
		}
		else
		{
			for (int i = k; i < n - k - 1; i++)
			{
				group.push_back(a[i][k]);
			}
			for (int j = k; j < n - k - 1; j++)
			{
				group.push_back(a[n - k - 1][j]);
			}
			for (int i = n - k - 1; i > k; i--)
			{
				group.push_back(a[i][n - k - 1]);
			}
			for (int j = n - k - 1; j > k; j--)
			{
				group.push_back(a[k][j]);
			}
		}
		rot = -rot;

		groups.push_back(group);
	}

	rot = w;
	for (int k = 0; k < size; k++)
	{
		vector<string> &group = groups[k];
		int len = group.size();

		int index = (w < 0 ? -w : w) % len;

		if (rot < 0)
		{
			for (int j = k; j < n - k - 1; j++, index = (index + 1) % len)
			{
				a[k][j] = group[index];
			}
			for (int i = k; i < n - k - 1; i++, index = (index + 1) % len)
			{
				a[i][n - k - 1] = group[index];
			}
			for (int j = n - k - 1; j > k; j--, index = (index + 1) % len)
			{
				a[n - k - 1][j] = group[index];
			}
			for (int i = n - k - 1; i > k; i--, index = (index + 1) % len)
			{
				a[i][k] = group[index];
			}
		}
		else
		{
			for (int i = k; i < n - k - 1; i++, index = (index + 1) % len)
			{
				a[i][k] = group[index];
			}
			for (int j = k; j < n - k - 1; j++, index = (index + 1) % len)
			{
				a[n - k - 1][j] = group[index];
			}
			for (int i = n - k - 1; i > k; i--, index = (index + 1) % len)
			{
				a[i][n - k - 1] = group[index];
			}
			for (int j = n - k - 1; j > k; j--, index = (index + 1) % len)
			{
				a[k][j] = group[index];
			}
		}
		rot = -rot;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
			if (j != n - 1) cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}