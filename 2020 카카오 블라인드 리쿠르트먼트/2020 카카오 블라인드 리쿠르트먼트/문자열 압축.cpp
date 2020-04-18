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
		// 단위가 1개부터 n/2개까지 해봄
		int cnt = 1;
		string unit = s.substr(0, i);
		string res;
		int res_size = size;

		for (int j = i; j < size; j + i)
		{
			// 단위를 설정하고 같은지 확인
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