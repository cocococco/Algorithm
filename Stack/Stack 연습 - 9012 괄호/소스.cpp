#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char ps[55];
		stack<char> s;
		scanf("%s", &ps);
		bool valid = true;

		int n = strlen(ps);
		for (int i = 0; i < n; i++)
		{
			if (ps[i] == '(')
			{
				s.push(ps[i]);
			}
			else if (ps[i] == ')')
			{
				if (!s.empty())
				{
					s.pop();
				}
				else // )가 남는 경우
				{
					valid = false;
					break;
				}
			}
		}

		if (!s.empty()) // (가 남는 경우
		{
			valid = false;
		}

		if (valid)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}