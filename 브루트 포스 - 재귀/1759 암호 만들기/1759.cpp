#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(string &password)
// 자음 2개 이상, 모음 1개 이상인지 확인하는 함수
{
	int ja = 0;
	int mo = 0;
	for (char x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			mo += 1;
		}
		else
		{
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}

void go(int n, vector<char> &alpha, string password, int i)
{
	if (password.length() == n)
	{
		if (check(password))
		{
			cout << password << '\n'; // 조건을 만족하면 출력
		}
		return;
	}
	if (i == alpha.size()) return; // 불가능한 경우
	//  => 패스워드 길이보다 넘어간 경우
	// 이 if문이 앞에 있으면 다 찾고 인덱스가 넘어간 경우도
	// 들어올 수 있으므로 뒤에 있는 게 맞다
	go(n, alpha, password + alpha[i], i + 1); // 넣는 경우
	go(n, alpha, password, i + 1); // 넣지 않는 경우
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	go(n, a, "", 0);

	return 0;
}