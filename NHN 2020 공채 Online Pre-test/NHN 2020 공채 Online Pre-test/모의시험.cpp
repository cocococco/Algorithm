#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string a[100][100];
string b[100][100];

// 배열, 시작점, 한 변의 길이, 회전수
void rotate(int x, int k, int w)
{
	w = w % (k - 1) * 4;
	int side = w / (k - 1);
	int step = w % (k - 1);

	for (int i = 0; i < k * 4; i++)
	{
	}
}

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

	return 0;
}