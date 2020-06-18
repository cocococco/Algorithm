#include <iostream>

using namespace std;
int d[1000001];

int main()
{
	int n;
	cin >> n;

	d[1] = 0; // 점화식과 상관 없는 초기값은 설정해줌
	// 그 이후부터 반복문을 통해 n번째 값을 찾아나감
	for (int i = 2; i <= n; i++)
	{
		// 먼저 1을 뺐을 경우를 결과값에 넣어놓음
		d[i] = d[i - 1] + 1;
		// 2로 나누어떨어지고, 그 결과가 min일경우 결과값 변경
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
		}
		// 3으로 나누어떨어지고, 그 결과가 min일 경우 결과값 변경
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
		}
		// 세 경우 다 우선순위 없이 확인해볼 수 있음
	}
	cout << d[n] << '\n';

	return 0;
}