/*
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열(오름차순)
*/
#include <iostream>

using namespace std;

int a[10];

void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	// 오름차순이어야 하므로 start 변수를 추가하여
	// start ~ n 사이의 숫자를 선택한다.
	// 여기서 index는 인덱스고, i. start는 숫자임!
	// check 배열은 필요가 없어짐. 오름차순이므로 중복 불가.
	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		go(index + 1, i + 1, n, m);
		// 이 다음은 i+1 이상의 숫자가 와야 함
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);

	return 0;
}