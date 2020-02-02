/*
너무 어렵다...
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
*/

#include <iostream>

using namespace std;

bool c[10]; // check. 사용했는지 안했는지 확인
int a[10]; // 결과를 출력할 배열

void go(int index, int n, int m)
{
	if (index == m) // m개 선택 완료되면 수열을 출력
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) // 정수 1부터 n까지 순서대로 탐색
	{
		if (c[i]) continue; // 사용했는지 확인
		c[i] = true; // 사용 안했으면 true로 바꿔주고
		a[index] = i; // 그 정수를 결과 배열에 추가
		go(index + 1, n, m); // 다음 정수 찾기 위해 index를 다음 위치로 옮겨주고 다시 순서대로 탐색함
		c[i] = false; // 이 위치에 왔다는 것은 변수 i를 다 사용했다는 뜻이므로 false로 바꿔주고 다음 i로 넘어감
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	go(0, n, m);

	return 0;
}