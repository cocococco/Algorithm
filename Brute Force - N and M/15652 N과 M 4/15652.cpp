///*
//1부터 N까지 자연수 중에서 M개를 고른 수열
//(중복 가능, 비내림차순)
//*/
//#include <iostream>
//
//using namespace std;
//
//int a[10];
//
//void go(int index, int start, int n, int m)
//{
//	if (index == m)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			cout << a[i];
//			if (i != m - 1) cout << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	for (int i = start; i <= n; i++)
//	{
//		a[index] = i;
//		go(index + 1, i, n, m);
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	go(0, 1, n, m);
//
//	return 0;
//}