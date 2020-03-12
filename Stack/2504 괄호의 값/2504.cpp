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
			// �ݴ� ��ȣ�� ��
			if (s.empty()) return 0;
			if (s.top() != get_open(ch)) return 0;
			s.pop();

			int val = v.top();
			v.pop();

			if (val == 0) val == 1;
			val *= get_mul(ch); // ���ڰ� ������ ���ϰ� ������ �׳� 1 ����

			if (v.empty())
			{
				ans += val; // ���̻� ����� �� ������ ���信 ����
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