/*
�� ������ � ���� �������� Ǯ���� ������°� <- �߿�

1. �տ� �ִ� ���� ��ȣ ��(push, O(1))
2. �ٸ� �ݴ� ��ȣ�� ¦�� �̷��� �ʴ�(pop, O(1))
3. ���� ����� ��(top, O(1))
=> �տ� �ִ� �͵� �� �ڿ� ���� ����� ���� ã�ƾ� ��. ���� LIFO�� ������. ���� �տ� �ִ� ���� ��ȣ���� ������� stack�� push�ϰ�, �ݴ� ��ȣ�� ������ pop�� �Ѵ�.
*/

#include <iostream>
#include <string>

using namespace std;

string valid(string s)
{
	int cnt = 0; // ������ ũ��. ���ÿ��� '('�ۿ� �ȵ��� ������ ������ ���� �ʾƵ� cnt�� �����ָ� ��. � �͵��� ���� ¦���� �� �ʿ� ����.
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
		if (cnt < 0) // ')'�� �� ���� ���
		{
			return "NO";
		} // ")()("�� �� �ùٸ��ٰ� ������ �ȵ�
	}
	if (cnt == 0) // �ùٸ� ���
	{
		return "YES";
	}
	else // '('�� �� ���� ���. size��ŭ Ȯ���� �����µ��� ���ÿ� ���Ұ� �����ִ� ���.
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