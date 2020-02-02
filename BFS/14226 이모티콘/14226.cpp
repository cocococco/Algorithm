#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int d[1001][1001];
// 보통은 check 배열까지 배열 2개를 사용하여 방문 여부 확인과, 거리 체크를 하는데 배열 하나를 사용함.

int main()
{
	int n;
	cin >> n;

	// -1로 초기화하여 -1이면 방문x로 체크 가능하고, 거리도 0부터 시작하여 동시에 한 배열로 확인 가능하게 함.
	memset(d, -1, sizeof(d)); // d 배열을 모두 -1로 채우기, for문보다 더 빠를 수 있기 때문에 사용
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0)); // 초기값은 화면에 이모티콘 1개, 클립보드에 0개임.
	d[1][0] = 0;

	while (!q.empty())
	{
		int s, c;
		tie(s, c) = q.front(); // pair값을 한번에 변수에 넣음
		q.pop();

		// 복사 (s, c) -> (s, c)
		if (d[s][s] == -1)
		{
			d[s][s] = d[s][c] + 1;
			q.push(make_pair(s, s));
		}
		// 붙여넣기 (s, c) -> (s+c, c)
		if (s + c <= n && d[s + c][c] == -1)
		{
			d[s + c][c] = d[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		// 삭제 (s, c) -> (s-1, c)
		if (s - 1 >= 0 && d[s - 1][c] == -1)
		{
			d[s - 1][c] = d[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}
	}

	// n개의 이모티콘이 화면에 있을 때 거리의 최소값 찾기
	int ans = -1; // 최소값은 -1로 초기화
	for (int i = 0; i <= n; i++) // 최소 0개부터 최대 n개까지 클립보드에 저장될 수 있으니까.
	{
		if (d[n][i] != -1) // 저장된 정보가 있으면
		{
			// -1이면 초기값이니 그냥 넣어주고, 아니면 ans와 저장된 값을 비교하여 최소값을 ans에 넣어줌
			if (ans == -1 || ans > d[n][i])
			{
				ans = d[n][i];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}