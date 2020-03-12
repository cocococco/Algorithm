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
				// ������
				v.push_back(i - 1);
				s.pop();
			}
			else
			{
				// �踷��� ������ ��
				// ���� �� ã�Ƴ���
				int left = s.top();
				s.pop();
				cnt++;
				for (int laser : v)
				{
					if (laser > left && laser < i)
					{
						// �������� �踷��� ���̿� ����
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