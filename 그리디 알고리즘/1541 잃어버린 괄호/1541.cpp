///* ½ÇÆÐ. */
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	int size = s.size();
//
//	int index = 0;
//	int sum = 0;
//
//	while (s[index] != '-')
//	{
//		int num[5];
//		int cnt = 0;
//
//		while (s[index] != '-' && s[index] != '+')
//		{
//			num[cnt] = s[index] - '0';
//			cnt++;
//			index++;
//		}
//
//		for (int i = 0; i < cnt; i++)
//		{
//			int mul = 1;
//			for (int j = cnt - i - 1; j > 0; j--)
//			{
//				mul *= 10;
//			}
//			sum += (num[i] * mul);
//		}
//		index++;
//	}
//
//	index++;
//	int minus = 0;
//
//	while (index < size)
//	{
//		int num[5];
//		int cnt = 0;
//
//		while (s[index] != '+' && s[index] != '-')
//		{
//			num[cnt] = s[index] - '0';
//			cnt++;
//			index++;
//		}
//
//		for (int i = cnt; i > 0; i--)
//		{
//			int mul = 0;
//			for (int j = i - 1; j > 0; j--)
//			{
//				mul *= 10;
//			}
//			minus += (num[cnt - i - 1] * mul);
//		}
//		index++;
//	}
//
//	cout << sum - minus << '\n';
//
//	return 0;
//}