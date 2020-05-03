/*
N개의 서로 다른 자연수 중에서 M개를 고른 수열
(중복 가능, 비내림차순)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int cnt[10]; // 여러 개 선택할 수 있으므로 만든 cnt 배열
int num[10];

// 선택하는 경우, 안하는 경우로 나누는 방법
void go(int index, int selected, int n, int m)
{
	if (selected == m) // selected가 인덱스임
	{
		// 0번째 인덱스부터 n-1번째까지
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= cnt[i]; j++)
			{
				cout << num[i] << ' ';
				// 해당 i 인덱스에 들어있는 cnt 개수만큼
				// num의 i 인덱스에 있는 숫자를 출력함
			}
		}
		cout << '\n';
		return;
	}

	if (index >= n) return; // 불가능한 경우

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
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);

	go(0, 0, n, m);

	return 0;
}