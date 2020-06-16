#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Lecture
{
	int pay;
	int day;
};

bool cmp(const Lecture &x, const Lecture &y)
{
	return x.day > y.day;
}

int main()
{
	int n;
	cin >> n;
	vector<Lecture> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].pay >> a[i].day;
	}

	sort(a.begin(), a.end(), cmp);

	int ans = 0;
	int k = 0;
	priority_queue<int> q;

	for (int i = 10000; i >= 1; i--)
	{
		while (k < n && a[k].day == i)
		{
			q.push(a[k].pay);
			k++;
		}
		if (!q.empty())
		{
			ans += q.top();
			q.pop();
		}
	}

	cout << ans << '\n';

	return 0;
}