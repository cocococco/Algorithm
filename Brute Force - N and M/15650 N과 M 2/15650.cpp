///*
//1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열(오름차순)
//각각의 자연수를 선택하는 경우와 선택하지 않는 경우로 나눔.
//더욱 일반적인 방법.
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int a[10];
//
//// index는 선택할지 말지 고를 숫자가 됨
//// selected가 인덱스임
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
//	// 숫자가 n보다 커지면 불가능. 리턴.
//	if (index > n) return;
//
//	// 선택한 경우
//	a[selected] = index;
//	// 선택했으므로 selected도 1증가,
//	// 다음으로 넘어가기 위해 index도 1증가.
//	go(index + 1, selected + 1, n, m);
//
//	// 선택 안하는 경우
//	a[selected] = 0;
//	// 선택하지 않았으므로 selected 증가시키지 않음
//	// 다음으로 넘어가기 위해 index 1증가.
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