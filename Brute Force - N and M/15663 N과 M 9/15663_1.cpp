/*
N개의 자연수 중에서 M개를 고른 수열 모두
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10];
int num[10];
int cnt[10]; // 각각의 수가 몇 개 있었는지를 저장

void go(int index, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << num[a[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (cnt[i] > 0)
			// 해당 인덱스의 수를 아직 사용할 수 있으면
		{
			cnt[i] -= 1; // 사용할 때마다 하나씩 빼줌
			a[index] = i; // 인덱스를 배열 a에 저장
			go(index + 1, n, m); // 다음 경우
			cnt[i] += 1; // 사용이 끝났으면 다시 더해줌
			// 같은 수를 개수에 맞게 선택할 수 있게 됨
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int temp[10];
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i]; // temp 배열에 수를 입력받음
	}
	sort(temp, temp + n); // 오름차순으로 정렬

	int k = 0;
	int x = temp[0]; // 입력받은 첫 번째 수
	int c = 1;

	for (int i = 1; i < n; i++)
	{
		if (x == temp[i])
			// 이전 수와 현재 인덱스에 저장된 수가 같으면
		{
			c += 1; // 중복되는 수의 개수를 저장하기 위해
					// 변수 c를 증가시킴
		}
		else // 이전 수와 현재 인덱스에 저장된 수가 다르면
		{
			num[k] = x; // 그 숫자를 num 배열에 저장
			cnt[k] = c; // 개수는 cnt 배열에 저장
			k += 1; // 인덱스 증가시킴
			x = temp[i]; // 현재 수를 변수에 저장
			c = 1; // 개수 초기화
		}
	}

	// 마지막 값은 저장 안했으므로
	num[k] = x;
	cnt[k] = c;
	n = k + 1;
	go(0, n, m);

	return 0;
}