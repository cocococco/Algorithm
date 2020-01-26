/* 보통은 Linked List로 풀지만 Stack을 사용 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char a[600000]; // 최대 600000자까지 입력 가능

int main()
{
	scanf("%s", a);

	stack<char> left, right;
	int n = strlen(a); // a의 길이 = n

	for (int i = 0; i < n; i++)
	{
		left.push(a[i]); // left에 a 순서대로 넣음
	}

	int m;
	scanf("%d", &m); // 몇 개의 연산을 할 것인지 입력받음

	while (m--) // m번 반복
	{
		char what;
		scanf(" %c", &what); // 어떤 연산인지 입력받음
		// 버퍼에 \n이 남아있으므로 앞에 공백 꼭 필요함 그렇지 않으면 \n이 what으로 들어감

		if (what == 'L') // 커서 왼쪽으로 한 칸
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			} // 왼쪽으로 밀 수 있으면 한 칸 민다
		}
		else if (what == 'D') // 커서 오른쪽으로 한 칸
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			} // 오른쪽으로 밀 수 있으면 한 칸 밈
		}
		else if (what == 'B') // 왼쪽 하나 삭제
		{
			if (!left.empty())
			{
				left.pop();
			} // 왼쪽에 남아있으면 삭제
		}
		else if (what == 'P') // 왼쪽에 하나 추가
		{
			char c;
			scanf(" %c", &c); // 버퍼에 ' '이 남아있으므로 공백을 넣어주지 않으면 c에 ' '이 들어감. 꼭 필요
			left.push(c);
		} // 문자 입력받고 커서 왼쪽에 추가
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	} // left에 있는 문자 차례로 pop해서 right에 push

	while (!right.empty())
	{
		printf("%c", right.top());
		right.pop();
	} // right에 있는 문자 순서대로 출력
	printf("\n");

	return 0;
}