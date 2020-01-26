#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<int> s;
	int n;
	string ans; // ������� string���� ����

	cin >> n; // n�� �Է¹��� ����

	int m = 0;

	while (n--)
	{
		int x;
		cin >> x; // �Է�
		if (x > m)
		{
			while (x > m) // x == m �� �� ��������, x = 4
			{
				s.push(++m); // m = 0,1,2,3, s = 1,2,3,4
				ans += '+';
			}
			s.pop(); // x == m �̸� pop
			ans += '-';
		}
		else // �Է¹��� ���ڰ� �̹� ���ÿ� ���� ��, x = 3
		{
			bool found = false;
			if (!s.empty())
			{
				int top = s.top(); // top = 3
				s.pop(); // top�� pop�� �� x�� ����
				ans += '-';
				if (x == top)
				{
					found = true;
				}
			}
			if (!found) // x�� �ٸ��� ����
			{
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	for (auto x : ans) // auto�� ����ϴ� ����? ���� ��� for��(ranged-based for loop)���� auto�� ����� �̻����� ���. auto�� �ڵ����� �ڷ����� �ο�����. ��� �ʱ�ȭ �ʿ�
	{
		cout << x << '\n';
	}
	return 0;
}