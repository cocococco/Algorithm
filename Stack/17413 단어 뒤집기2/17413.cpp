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
	string str; // �׳� string�� cin���� �Է¹����� ���� ���������� �����. ��� �Ұ�. getline ����ؾ� ��.

	bool tag = false;
	getline(cin, str);
	stack<char> s;

	for (char c : str)
	{
		if (c == '<')
		{
			print(s); // ������ ������ ���Ӹ� �ƴ϶� <�� ������ ������ ������ �ܾ �������� ��
			tag = true;
			cout << c;
		}
		else if (c == '>')
		{
			tag = false;
			cout << c;
		}

		else if (tag) // c�θ� ����� ���� ���� ���� �ƴ϶� ����� �� bool���� tag�ε� ����� ���� ���� �� ����. �±��� ��쿡�� �׳� �� ���.
		{
			cout << c;
		}
		else // �±װ� �ƴ� �� ������ ���, �ܾ��� ���
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
	print(s); // �������� ���� �Ǵ� <�� ��� ��� ���� �ܾ �ִٸ� �����.
	cout << '\n';

	return 0;
}