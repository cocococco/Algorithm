#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

char a[32][4];

int calc(char c)
{
	if (c == '0') return 0;
	else return 1;
}

int main()
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int sum = 0;
			sum = calc(a[i * 4 + j][0]) * 2 * 2 * 2 + calc(a[i * 4 + j][1]) * 2 * 2 + calc(a[i * 4 + j][2]) * 2 + calc(a[i * 4 + j][3]);

			if (sum < 10) cout << sum;
			else
			{
				char c = sum + 87;
				cout << c;
			}
		}

		if (i != 7) cout << ':';
	}
	cout << '\n';

	return 0;
}