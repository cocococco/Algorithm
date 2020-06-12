#include <iostream>
#include <string>
#include <vector>

using namespace std;

// fail 함수
vector<int> preprocessing(string p)
{
	int m = p.size();
	vector<int> fail(m);
	fail[0] = 0; // 첫 번째는 0
	int j = 0;

	for (int i = 1; i < m; i++)
	{
		// 다시 뒤로가서 틀렸던 곳부터 확인
		while (j > 0 && p[i] != p[j])
		{
			j = fail[j - 1];
		}

		// prefix == sufix 면 fail 증가
		if (p[i] == p[j])
		{
			fail[i] = j + 1;
			j += 1;
		}
		// 일치하지 않는다면 0
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
	auto fail = preprocessing(p); // fail 생성
	vector<int> ans;

	int n = s.size(); // 전체 string
	int m = p.size(); // 확인할 string
	int i = 0;
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		// 다른 경우 틀린 곳부터 다시 시작
		while (j > 0 && s[i] != p[j])
		{
			j = fail[j - 1]; // fail에 저장된 값만큼 같으므로 여기서부터 다시 시작하면 됨
		}

		if (s[i] == p[j])
		{
			// 부분 문자열 다 찾은 경우
			if (j == m - 1)
			{
				ans.push_back(i - m + 1); // 시작점을 저장
				j = fail[j]; // 틀렸던 곳부터 다시 시작
			}
			// 다 찾기 전에 문자가 같은 경우 인덱스 증가
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