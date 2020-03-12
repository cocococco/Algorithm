#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string a;
	cin >> a;
	int n = a.size();
	stack<int> s;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '(')
		{
			s.push(i);
		}
		else
		{
			if (s.top() + 1 == i)
			{
				// 레이저인 경우
				s.pop();
				ans += s.size(); // 스택의 사이즈는 레이저 하나 당 자를 수 있는 쇠막대의 개수임
			}
			else
			{
				// 쇠막대의 오른쪽 끝
				s.pop();
				ans += 1; // 쇠막대 자체의 개수 1을 더해줌
			}
		}
	}
	cout << ans << '\n';
	return 0;
}