#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<int> s;
	int n;
	string ans; // 결과값을 string으로 만듦

	cin >> n; // n개 입력받을 예정

	int m = 0;

	while (n--)
	{
		int x;
		cin >> x; // 입력
		if (x > m)
		{
			while (x > m) // x == m 일 때 빠져나옴, x = 4
			{
				s.push(++m); // m = 0,1,2,3, s = 1,2,3,4
				ans += '+';
			}
			s.pop(); // x == m 이면 pop
			ans += '-';
		}
		else // 입력받은 숫자가 이미 스택에 있을 때, x = 3
		{
			bool found = false;
			if (!s.empty())
			{
				int top = s.top(); // top = 3
				s.pop(); // top을 pop한 게 x면 성공
				ans += '-';
				if (x == top)
				{
					found = true;
				}
			}
			if (!found) // x와 다르면 실패
			{
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	for (auto x : ans) // auto를 사용하는 이유? 범위 기반 for문(ranged-based for loop)에서 auto의 사용은 이상적인 방식. auto는 자동으로 자료형을 부여받음. 대신 초기화 필요
	{
		cout << x << '\n';
	}
	return 0;
}