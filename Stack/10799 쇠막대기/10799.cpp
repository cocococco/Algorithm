#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int cnt = 0;
	stack<int> s;
	vector<int> v;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ')')
		{
			if (str[i - 1] == '(')
			{
				// 레이저
				v.push_back(i - 1);
				s.pop();
			}
			else
			{
				// 쇠막대기 오른쪽 끝
				// 왼쪽 끝 찾아내기
				int left = s.top();
				s.pop();
				cnt++;
				for (int laser : v)
				{
					if (laser > left && laser < i)
					{
						// 레이저가 쇠막대기 사이에 있음
						cnt++;
					}
				}
			}
		}
		else
		{
			s.push(i);
		}
	}

	cout << cnt << endl;

	return 0;
}