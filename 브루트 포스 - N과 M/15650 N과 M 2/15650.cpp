///*
//1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����(��������)
//������ �ڿ����� �����ϴ� ���� �������� �ʴ� ���� ����.
//���� �Ϲ����� ���.
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int a[10];
//
//// index�� �������� ���� �� ���ڰ� ��
//// selected�� �ε�����
//void go(int index, int selected, int n, int m)
//{
//	if (selected == m)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			cout << a[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	// ���ڰ� n���� Ŀ���� �Ұ���. ����.
//	if (index > n) return;
//
//	// ������ ���
//	a[selected] = index;
//	// ���������Ƿ� selected�� 1����,
//	// �������� �Ѿ�� ���� index�� 1����.
//	go(index + 1, selected + 1, n, m);
//
//	// ���� ���ϴ� ���
//	a[selected] = 0;
//	// �������� �ʾ����Ƿ� selected ������Ű�� ����
//	// �������� �Ѿ�� ���� index 1����.
//	go(index + 1, selected, n, m);
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	go(1, 0, n, m);
//
//	return 0;
//}