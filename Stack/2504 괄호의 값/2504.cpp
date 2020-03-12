#include <iostream>
#include <string>
#include <stack>

using namespace std;

char get_open(char ch)
{
	if (ch == ')') return '(';
	if (ch == ']') return '[';
	return 0;
}

int get_mul(char ch)
{
	if (ch == ')') return 2;
	if (ch == ']') return 3;
	return 0;
}

int go(string &str)
{
	stack<char> s;
	stack<int> v;
	int ans = 0;

	for (char ch : str)
	{
		if (ch == '(' || ch == '[')
		{
			s.push(ch);
			v.push(0);
		}
		else
		{
			// 닫는 괄호일 때
			if (s.empty()) return 0;
			if (s.top() != get_open(ch)) return 0;
			s.pop();

			int val = v.top();
			v.pop();

			if (val == 0) val == 1;
			val *= get_mul(ch); // 숫자가 있으면 곱하고 없으면 그냥 1 곱함

			if (v.empty())
			{
				ans += val; // 더이상 계산할 것 없으면 정답에 더함
			}
			else
			{
				val += v.top();
				v.pop();
				v.push(val);
			}
		}
	}
	if (!s.empty()) return 0;
	return ans;
}

int main()
{
	string str;
	cin >> str;
	cout << go(str) << '\n';
	return 0;
}