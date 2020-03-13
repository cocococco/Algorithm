#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> f;
	//int a[50];

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		f.push_back(temp);
		//cin >> f[i];
		//cin >> a[i];
	}

	sort(f.begin(), f.end());
	//sort(a, a + n);

	cout << f[0] * f[n - 1] << '\n';
	//cout << a[0] * a[n - 1] << '\n';

	return 0;
}