#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	int x, y;
	bool operator < (const Point &v) const
	{
		if (x < v.x)
		{
			return true;
		}
		else if (x == v.x)
		{
			return y < v.y;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Point> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
	{
		cout << a[i].x << ' ' << a[i].y << '\n';
	}

	return 0;
}