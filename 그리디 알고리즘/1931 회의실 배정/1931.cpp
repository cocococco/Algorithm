#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
	int begin, end;
};

bool cmp(const Meeting &u, const Meeting &v)
{
	// 끝나는 시간이 같을 경우 일찍 시작하는거
	if (u.end == v.end)
	{
		return u.begin < v.begin;
	}
	// 다를 경우 일찍 끝나는거
	else
	{
		return u.end < v.end;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<Meeting> a(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].begin, &a[i].end);
	}
	sort(a.begin(), a.end(), cmp);

	int now = 0;
	int ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (now <= a[i].begin)
		{
			now = a[i].end;
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}