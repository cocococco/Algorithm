/*맞는 것 같은데 백준에서 틀렸다고 나옴. 모르겠음*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		stack<char> left, right;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '<')
			{
				if (!left.empty())
				{
					right.push(left.top());
					left.pop();
				}
			}
			else if (s[i] == '>')
			{
				if (!right.empty())
				{
					left.push(right.top());
					right.pop();
				}
			}
			else if (s[i] == '-' && !left.empty())
			{
				if (!left.empty())
				{
					left.pop();
				}
			}
			else
			{
				left.push(s[i]);
			}
		}
		while (!left.empty())
		{
			right.push(left.top());
			left.pop();
		}
		while (!right.empty())
		{
			cout << right.top();
			right.pop();
		}
		cout << '\n';
	}

	return 0;
}