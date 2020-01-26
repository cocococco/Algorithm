/*
이 문제의 어떤 점이 스택으로 풀도록 만들었는가 <- 중요

1. 앞에 있는 여는 괄호 중(push, O(1))
2. 다른 닫는 괄호와 짝을 이루지 않는(pop, O(1))
3. 가장 가까운 것(top, O(1))
=> 앞에 있는 것들 중 뒤와 가장 가까운 것을 찾아야 함. 따라서 LIFO를 만족함. 따라서 앞에 있는 여는 괄호들은 순서대로 stack에 push하고, 닫는 괄호를 만나면 pop을 한다.
*/

#include <iostream>
#include <string>

using namespace std;

string valid(string s)
{
	int cnt = 0; // 스택의 크기. 스택에는 '('밖에 안들어가기 때문에 실제로 넣지 않아도 cnt만 세어주면 됨. 어떤 것들이 서로 짝인지 알 필요 없음.
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			cnt += 1; // push
		}
		else
		{
			cnt -= 1;
		}
		if (cnt < 0) // ')'가 더 많은 경우
		{
			return "NO";
		} // ")()("일 때 올바르다고 나오면 안됨
	}
	if (cnt == 0) // 올바른 경우
	{
		return "YES";
	}
	else // '('가 더 많은 경우. size만큼 확인이 끝났는데도 스택에 원소가 남아있는 경우.
	{
		return "NO";
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		string s;
		cin >> s;
		cout << valid(s) << '\n';
	}
	return 0;
}