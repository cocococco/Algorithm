/*
�ܾ� ������. ������ ���� ������ pop�Ѵ�.
������ ���� = N => O(N)
push, pop => O(1)��
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); // cpp�� iostream�� c�� stdio���� ����ȭ�� ���� �Լ�. c++���� �������� ���۸� �����ϰ� �ǰ� c�� ���۵���� �����Ͽ� ��� �Ұ�. ����ϴ� ������ ���� �پ����� ������ ����� �ӵ��� ����. cin, cout�� ����ϰ� printf, scanf ���� �Լ��� ��� �Ұ���.
	cin.tie(nullptr); // cin�� cout���κ��� untie�ϴ� �Լ�. ���� tie�Ǿ����� ���� cout, cin ������� ������ cout �� cin�� �Ǳ� ���� output�� flush�ȴ�. �׷��� stream�� untie�ϸ� output�� flush���� ���� ä�� �Է��� �䱸�ϰ� �ȴ�. ���� cout�� output �޼����� ��µ��� �ʴ´�.(�⺻������ cout�� output�� buffer�� �������ų� ���������� flush�� �����ֱ� ������ ��µ��� �ʴ´�.) ���� cin�� cout�� untie�Ѵٸ� cin���� �Է��� �ޱ� ���� ������ ���� �ʹٸ� �Ź� �������� cout�� flush�ؾ� �Ѵ�. ��ư cin�� cout�� ������ �ʿ� �����Ƿ� �ӵ��� ��������.

	int t;
	cin >> t;
	cin.ignore(); // �Է� ���� ����ֱ�. cin�� getline�� �Բ� ����ϱ� ������ �ʿ���. cin�� \n�� ������ ���� �ʰ� �Է� ���ۿ� ���ܵд�. int�� �ƴ϶� string�̶� ���� ����. �׸��� getline�� \n�� ������ ��´�. (�Է� ���� ��ü�� ���� ���� �ƴ϶� �� ���� ���� �ϳ��� �����.)

	while (t--)
	{
		string str;
		getline(cin, str); // ����/����, \n�� ������ ���ڿ��� �Է¹��� �� ����
		str += '\n'; // �� ���������� ������ ������ ������ ������ �� ������ �� ����. \n�� �߰��Ͽ� ���ǵ� �߰��ϰ� ���� ����
		stack<char> s;

		for (char ch : str)
		{
			if (ch == ' ' || ch == '\n')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << ch; // ���ÿ� �ִ� ���� �� ������ �ܾ� ���̻��� ������ �ʿ��ϹǷ�.
			}
			else
			{
				s.push(ch);
			}
		}
	}
	return 0;
}