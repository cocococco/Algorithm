#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

char a[1000][1000];
bool check[1000][1000];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

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

	queue<pair<int, int>> q;
	vector<int> sizes;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 'L' && check[i][j] == false)
			{
				int size = 1;
				q.push(make_pair(i, j));
				check[i][j] = true;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (a[nx][ny] == 'L' && !check[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < n)
						{
							q.push(make_pair(nx, ny));
							check[nx][ny] = true;
							size++;
						}
					}
				}
				sizes.push_back(size);
			}
		}
	}

	sort(sizes.begin(), sizes.end());
	int x = sizes.size();
	int last = -1;

	for (int i = x - 2; i >= 0; i--)
	{
		if (sizes[x - 1] != sizes[i])
		{
			last = i;
			break;
		}
	}

	if (last == -1)
	{
		printf("0 0 0.00 0\n");
		return 0;
	}

	int max, min;
	double avg, mid;

	max = sizes[last];
	min = sizes[0];

	double sum = 0;
	for (int i = 0; i <= last; i++) // last == 마지막 index
	{
		sum += sizes[i];
	}
	avg = sum / (double)(last + 1); // last + 1 == 개수

	if ((last + 1) % 2 == 1) // 홀수
	{
		if (last == 0) // 원소가 1개
		{
			mid = sizes[0];
		}
		else // 3개 이상
		{
			mid = sizes[(last + 1) / 2];
		}
	}
	else // 짝수
	{
		mid = (sizes[(last + 1) / 2] + sizes[(last + 1) / 2 + 1]) / 2.0f;
	}

	if ((mid - (int)mid) == 0)
	{
		printf("%d %d %.2f %d\n", max, min, avg, (int)mid);
	}
	else
	{
		printf("%d %d %.2f %.2f\n", max, min, avg, mid);
	}

	return 0;
}