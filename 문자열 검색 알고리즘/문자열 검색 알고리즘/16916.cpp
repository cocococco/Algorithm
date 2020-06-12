#include <iostream>
#include <string>
#include <vector>

using namespace std;

// fail �Լ�
vector<int> preprocessing(string p)
{
	int m = p.size();
	vector<int> fail(m);
	fail[0] = 0; // ù ��°�� 0
	int j = 0;

	for (int i = 1; i < m; i++)
	{
		// �ٽ� �ڷΰ��� Ʋ�ȴ� ������ Ȯ��
		while (j > 0 && p[i] != p[j])
		{
			j = fail[j - 1];
		}

		// prefix == sufix �� fail ����
		if (p[i] == p[j])
		{
			fail[i] = j + 1;
			j += 1;
		}
		// ��ġ���� �ʴ´ٸ� 0
		else
		{
			fail[i] = 0;
		}
		// ABCABE
		// i = 1 2 3 4 5
		// j = 0   1 2 0
		// fail = 0 0 0 1 2 0
	}

	return fail;
}

vector<int> kmp(string s, string p)
{
	auto fail = preprocessing(p); // fail ����
	vector<int> ans;

	int n = s.size(); // ��ü string
	int m = p.size(); // Ȯ���� string
	int i = 0;
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		// �ٸ� ��� Ʋ�� ������ �ٽ� ����
		while (j > 0 && s[i] != p[j])
		{
			j = fail[j - 1]; // fail�� ����� ����ŭ �����Ƿ� ���⼭���� �ٽ� �����ϸ� ��
		}

		if (s[i] == p[j])
		{
			// �κ� ���ڿ� �� ã�� ���
			if (j == m - 1)
			{
				ans.push_back(i - m + 1); // �������� ����
				j = fail[j]; // Ʋ�ȴ� ������ �ٽ� ����
			}
			// �� ã�� ���� ���ڰ� ���� ��� �ε��� ����
			else
			{
				j += 1;
			}
		}
	}

	return ans;
}

int main()
{
	string s, p;
	cin >> s >> p;

	auto matched = kmp(s, p);

	if (matched.size() > 0)
	{
		cout << 1 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}

	return 0;
}