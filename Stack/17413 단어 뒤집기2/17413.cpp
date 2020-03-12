#include <iostream>
#include <stack>
#include <string>

using namespace std;

void print(stack<char> &s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	string str; // 그냥 string을 cin으로 입력받으면 공백 이전까지만 저장됨. 사용 불가. getline 사용해야 함.

	bool tag = false;
	getline(cin, str);
	stack<char> s;

	for (char c : str)
	{
		if (c == '<')
		{
			print(s); // 공백을 만났을 때뿐만 아니라 <를 만났을 때에도 뒤집은 단어를 출력해줘야 함
			tag = true;
			cout << c;
		}
		else if (c == '>')
		{
			tag = false;
			cout << c;
		}

		else if (tag) // c로만 경우의 수를 나눌 것이 아니라 만들어 둔 bool값인 tag로도 경우의 수를 나눌 수 있음. 태그일 경우에는 그냥 다 출력.
		{
			cout << c;
		}
		else // 태그가 아닐 때 공백인 경우, 단어인 경우
		{
			if (c == ' ')
			{
				print(s);
				cout << c;
			}
			else
			{
				s.push(c);
			}
		}
	}
	print(s); // 마지막에 공백 또는 <가 없어서 출력 못한 단어가 있다면 출력함.
	cout << '\n';

	return 0;
}