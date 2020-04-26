#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(string &password)
// ���� 2�� �̻�, ���� 1�� �̻����� Ȯ���ϴ� �Լ�
{
	int ja = 0;
	int mo = 0;
	for (char x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			mo += 1;
		}
		else
		{
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}

void go(int n, vector<char> &alpha, string password, int i)
{
	if (password.length() == n)
	{
		if (check(password))
		{
			cout << password << '\n'; // ������ �����ϸ� ���
		}
		return;
	}
	if (i == alpha.size()) return; // �Ұ����� ���
	//  => �н����� ���̺��� �Ѿ ���
	// �� if���� �տ� ������ �� ã�� �ε����� �Ѿ ��쵵
	// ���� �� �����Ƿ� �ڿ� �ִ� �� �´�
	go(n, alpha, password + alpha[i], i + 1); // �ִ� ���
	go(n, alpha, password, i + 1); // ���� �ʴ� ���
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	go(n, a, "", 0);

	return 0;
}