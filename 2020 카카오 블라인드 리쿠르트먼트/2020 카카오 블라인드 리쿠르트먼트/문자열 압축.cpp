#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
	int size = s.size();
	int answer = size;
	for (int i = 1; i <= size / 2; i++)
	{
		// ������ 1������ n/2������ �غ�
		int cnt = 1;
		string unit = s.substr(0, i);
		string res;
		int res_size = size;

		for (int j = i; j < size; j + i)
		{
			// ������ �����ϰ� ������ Ȯ��
			if (j + i >= size)
			{
				res += s.substr(j, size - j);
			}
			else
			{
				string cmp = s.substr(j, i);
				if (unit == cmp)
				{
					cnt++;
				}
				else
				{
					if (cnt != 1) res += cnt;
					cnt = 1;
					res += unit;
					unit = cmp;
				}
			}
		}
		res_size = res.size();
		if (res_size < answer) answer = res_size;
	}

	return answer;
}

int main()
{
	string s;
	cin >> s;
	cout << solution(s) << '\n';
}