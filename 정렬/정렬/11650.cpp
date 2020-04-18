//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	vector<pair<int, int>> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i].first >> a[i].second;
//	}
//
//	sort(a.begin(), a.end());
//	// pair로 sorting하면 자동으로 first, second 순서 오름차순으로 정렬된다.
//
//	for (int i = 0; i < a.size(); i++)
//	{
//		cout << a[i].first << ' ' << a[i].second << '\n';
//	}
//
//	return 0;
//}