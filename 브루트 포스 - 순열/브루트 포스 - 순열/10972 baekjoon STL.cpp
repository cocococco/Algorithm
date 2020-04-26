#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 7 2 3 6 5 4 1
// 7 2(3)6 5 4 1
// 7 2 3 6 5(4)1
// 7 2(4)6 5(3)1
// 7 2 4(1 3 5 6)

// 원래 next_permutation 함수는 있지만 구현하면 이렇게 됨
bool next_permutation(int *a, int n)
{
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	// i-1번째가 i번째보다 작아졌을 때 out
	// a[i-1] : 3, a[i] : 6

	if (i <= 0) return false;
	// 마지막 순열인 경우

	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;
	// j번째가 i-1번째보다 커졌을 때 out
	// a[j] : 4

	swap(a[i - 1], a[j]);
	// 일단 i-1번째와 j번째의 순서를 바꿈

	j = n - 1;

	while (i < j)
	{
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	// 원래 내림차순이었으니 반대로 swap하면 내림차순이 됨

	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (next_permutation(a.begin(), a.end()))
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
	}
	else
	{
		cout << "-1";
	}

	cout << '\n';
	return 0;
}