#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while (true)
	{
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> s(k);
		vector<int> a(k);
		for (int i = 0; i < k; i++)
		{
			cin >> s[i];
			if (i < 6) a[i] = 0;
			else a[i] = 1;
		}

		do
		{
			for (int i = 0; i < k; i++)
			{
				if (a[i] == 0) cout << s[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(a.begin(), a.end()));
		cout << '\n';
	}
	return 0;
}