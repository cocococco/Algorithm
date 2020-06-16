//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//bool cmp(int x, int y)
//{
//	return x > y;
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	int size = s.size();
//	vector<int> a(size);
//	int sum = 0;
//
//	for (int i = 0; i < size; i++)
//	{
//		a[i] = s[i] - '0';
//		sum += a[i];
//	}
//
//	sort(a.begin(), a.end(), cmp);
//
//	if (a[size - 1] != 0 || !(sum % 3 == 0))
//	{
//		cout << -1 << '\n';
//		return 0;
//	}
//	else
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << a[i];
//		}
//		cout << '\n';
//		return 0;
//	}
//}