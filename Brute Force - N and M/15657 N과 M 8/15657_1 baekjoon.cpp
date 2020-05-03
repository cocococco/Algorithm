/*
N개의 서로 다른 자연수 중에서 M개를 고른 수열
(중복 가능, 비내림차순)
*/
#include <iostream>

using namespace std;

int cnt[10]; // 여러 개 선택할 수 있으므로 만든 cnt 배열

// 선택하는 경우, 안하는 경우로 나누는 방법
void go(int index, int selected, int n, int m)
{
	if (selected == m) // selected가 인덱스임
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= cnt[i]; j++)
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
		return;
	}

	if (index > n) return; // 불가능한 경우

	// 같은 걸 여러 개 선택할 수 있으므로 루프를 만들고
	// cnt 배열을 사용하여 선택하는 경우를 따진다
	// 1 1 1과 1 1 중 1 1 1이 순서가 더 빠르므로
	// 거꾸로 루프를 타야 함
	// 남은 빈칸의 개수 ~ 1까지 중에서 선택
	for (int i = m - selected; i >= 1; i--)
	{
		// 선택한 경우
		cnt[index] = i; // cnt : i를 몇개 선택했는지 저장
		go(index + 1, selected + i, n, m);
	}

	// 선택하지 않은 경우
	cnt[index] = 0;
	go(index + 1, selected, n, m);
}

int main()
{
	int n, m;
	cin >> n >> m;

	go(1, 0, n, m);

	return 0;
}