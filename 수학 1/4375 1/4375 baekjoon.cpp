#include <iostream>

using namespace std;

int main()
{
	int n; // 나눌 수
	while (cin >> n)
	{
		int num = 0;

		for (int i = 1; ; i++)
		{
			num = num * 10 + 1; // 1, 11, 111, 1111...
			if (num < n) continue; // 추가함
			num %= n;
			if (num == 0)
			{
				cout << i << '\n';
				break;
			}
		}
	}

	return 0;
}