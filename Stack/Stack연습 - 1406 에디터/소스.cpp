#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
	stack<char> s1, s2;

	char s[100000];
	scanf("%s", &s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		s1.push(s[i]);
	}

	int t;
	scanf("%d", &t);

	while (t--)
	{
		char cmd, al;
		scanf(" %c", &cmd); // �߿�!!

		if (cmd == 'L' && !s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		else if (cmd == 'D' && !s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		else if (cmd == 'B' && !s1.empty())
		{
			s1.pop();
		}
		else if (cmd == 'P')
		{
			scanf(" %c", &al); // �߿�!!
			s1.push(al);
		}
	}

	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	// stack�� ����ϴ� ���
	while (!s2.empty())
	{
		printf("%c", s2.top());
		s2.pop();
	}
	printf("\n");

	return 0;
}