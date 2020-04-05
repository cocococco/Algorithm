#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);
		auto p = equal_range(a.begin(), a.end(), num);
		// equal_range ; upper bound, lower bound를 둘 다 리턴해 주는 함수. first = lower bound, second = upper bound
		printf("%d ", p.second - p.first);
	}
	printf("\n");
	return 0;
}