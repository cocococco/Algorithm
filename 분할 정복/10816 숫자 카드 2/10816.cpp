//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int n, m;
//int a[500000];
//
//int binary_search(int x)
//{
//	int l = 0;
//	int r = n - 1;
//	int cnt = 0;
//
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (a[mid] == x)
//		{
//			cnt++;
//		}
//		else if (a[mid] > x)
//		{
//			r = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	cin >> m;
//	while (m--)
//	{
//		int num;
//		cin >> num;
//		cout << binary_search(num) << ' ';
//	}
//	cout << '\n';
//	return 0;
//}