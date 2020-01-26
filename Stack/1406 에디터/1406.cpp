/* ������ Linked List�� Ǯ���� Stack�� ��� */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char a[600000]; // �ִ� 600000�ڱ��� �Է� ����

int main()
{
	scanf("%s", a);

	stack<char> left, right;
	int n = strlen(a); // a�� ���� = n

	for (int i = 0; i < n; i++)
	{
		left.push(a[i]); // left�� a ������� ����
	}

	int m;
	scanf("%d", &m); // �� ���� ������ �� ������ �Է¹���

	while (m--) // m�� �ݺ�
	{
		char what;
		scanf(" %c", &what); // � �������� �Է¹���
		// ���ۿ� \n�� ���������Ƿ� �տ� ���� �� �ʿ��� �׷��� ������ \n�� what���� ��

		if (what == 'L') // Ŀ�� �������� �� ĭ
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			} // �������� �� �� ������ �� ĭ �δ�
		}
		else if (what == 'D') // Ŀ�� ���������� �� ĭ
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			} // ���������� �� �� ������ �� ĭ ��
		}
		else if (what == 'B') // ���� �ϳ� ����
		{
			if (!left.empty())
			{
				left.pop();
			} // ���ʿ� ���������� ����
		}
		else if (what == 'P') // ���ʿ� �ϳ� �߰�
		{
			char c;
			scanf(" %c", &c); // ���ۿ� ' '�� ���������Ƿ� ������ �־����� ������ c�� ' '�� ��. �� �ʿ�
			left.push(c);
		} // ���� �Է¹ް� Ŀ�� ���ʿ� �߰�
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	} // left�� �ִ� ���� ���ʷ� pop�ؼ� right�� push

	while (!right.empty())
	{
		printf("%c", right.top());
		right.pop();
	} // right�� �ִ� ���� ������� ���
	printf("\n");

	return 0;
}