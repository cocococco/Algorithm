#include <iostream>

using namespace std;

int d[1001];
int p[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> p[i];
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (d[i] < d[j] + p[i - j])
			{
				d[i] = d[j] + p[i - j];
			}
		}
	}

	cout << d[n] << '\n';
	return 0;
}