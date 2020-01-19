/*
단어 뒤집기. 공백이 나올 때마다 pop한다.
문자의 길이 = N => O(N)
push, pop => O(1)씩
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); // cpp의 iostream과 c의 stdio와의 동기화를 끊는 함수. c++만의 독립적인 버퍼를 생성하게 되고 c의 버퍼들과는 병행하여 사용 불가. 사용하는 버퍼의 수가 줄어들었기 때문에 입출력 속도가 증가. cin, cout만 사용하고 printf, scanf 같은 함수는 사용 불가능.
	cin.tie(nullptr); // cin을 cout으로부터 untie하는 함수. 원래 tie되어있을 때는 cout, cin 순서대로 있으면 cout 후 cin이 되기 전에 output이 flush된다. 그러나 stream을 untie하면 output이 flush되지 않은 채로 입력을 요구하게 된다. 따라서 cout의 output 메세지는 출력되지 않는다.(기본적으로 cout의 output은 buffer가 가득차거나 수동적으로 flush를 시켜주기 전까진 출력되지 않는다.) 따라서 cin과 cout을 untie한다면 cin으로 입력을 받기 전에 뭔가를 띄우고 싶다면 매번 수동으로 cout을 flush해야 한다. 여튼 cin이 cout과 맞춰줄 필요 없으므로 속도가 빨라진다.

	int t;
	cin >> t;
	cin.ignore(); // 입력 버퍼 비워주기. cin과 getline을 함께 사용하기 때문에 필요함. cin은 \n을 변수에 담지 않고 입력 버퍼에 남겨둔다. int가 아니라 string이라도 담지 못함. 그리고 getline은 \n을 변수에 담는다. (입력 버퍼 전체를 비우는 것이 아니라 맨 앞의 문자 하나를 지운다.)

	while (t--)
	{
		string str;
		getline(cin, str); // 띄어쓰기/공백, \n을 포함한 문자열을 입력받을 수 있음
		str += '\n'; // 맨 마지막에는 공백이 없으니 문장이 끝났을 때 뒤집을 수 없다. \n을 추가하여 조건도 추가하고 쉽게 만듦
		stack<char> s;

		for (char ch : str)
		{
			if (ch == ' ' || ch == '\n')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << ch; // 스택에 있는 것을 다 꺼내고 단어 사이사이 공백이 필요하므로.
			}
			else
			{
				s.push(ch);
			}
		}
	}
	return 0;
}