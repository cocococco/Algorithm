#include <iostream>

using namespace std;

// 왼쪽 자식과 오른쪽 자식 정보를 저장하는 노드 구조체
struct Node
{
	int left;
	int right;
};

Node a[50];

// 먼저 출력 후 왼쪽 오른쪽
void preorder(int x)
{
	if (x == -1) return;

	cout << (char)(x + 'A'); // 다시 A를 더해서 char형으로 출력
	preorder(a[x].left);
	preorder(a[x].right);
}

// 왼쪽 갔다가 출력 후 오른쪽
void inorder(int x)
{
	if (x == -1) return;

	inorder(a[x].left);
	cout << (char)(x + 'A');
	inorder(a[x].right);
}

// 왼쪽 오른쪽 그 후 출력
void postorder(int x)
{
	if (x == -1) return;

	postorder(a[x].left);
	postorder(a[x].right);
	cout << (char)(x + 'A');
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) // 노드의 개수만큼 입력받음
	{
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A'; // 0부터 표시하기 위해 A를 빼줌

		if (y == '.')
		{
			a[x].left = -1; // 왼쪽 자식 노드가 없는 경우 -1
		}
		else
		{
			a[x].left = y - 'A';
		}

		if (z == '.')
		{
			a[x].right = -1;
		}
		else
		{
			a[x].right = z - 'A';
		}
	}

	preorder(0);
	cout << '\n';

	inorder(0);
	cout << '\n';

	postorder(0);
	cout << '\n';

	return 0;
}