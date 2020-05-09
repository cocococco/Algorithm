/*
1부터 N까지 자연수 중에서 M개를 고른 수열
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
		for (int i = 1; i <= n; i++) // 고를 수 있는 숫자는 1~n
		{
			// 해당 숫자의 인덱스를 가진 cnt 배열에 들어있는
			// 개수만큼 해당 숫자를 출력함
			// cnt[1]에는 1이 몇 개 있는지 들어있음
			for (int j = 1; j <= cnt[i]; j++)
			{
				cout << i << ' ';
			}
		} // 이걸 n까지 돌면서 찾고 출력
		cout << '\n';
		return;
	}

	if (index > n) return; // 불가능한 경우

	// 같은 걸 여러 개 선택할 수 있으므로 루프를 만들고
	// cnt 배열을 사용하여 선택하는 경우를 따진다
	// 1 1 1과 1 1 중 1 1 1이 순서가 더 빠르므로
	// 거꾸로 루프를 타야 함
	// i는 남은 빈칸의 개수, m ~ 1까지
	for (int i = m - selected; i >= 1; i--)
	{
		// 선택한 경우
		cnt[index] = i; // cnt : i를 몇개 선택했는지 저장
		go(index + 1, selected + i, n, m);
		// i만큼 선택했으므로 selected는 i만큼 증가
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