//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int go(vector<int> &a, int x)
//{
//	int left = 0;
//	int right = a.size() - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
//		if (a[mid] == x)
//		{
//			return 1;
//		}
//		else if (a[mid] > x)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//	int m;
//	cin >> m;
//	vector<int> b(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> b[i];
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		cout << go(a, b[i]) << (i < m - 1 ? ' ' : '\n');
//	}
//
//	return 0;
//}