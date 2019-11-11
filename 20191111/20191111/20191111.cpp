#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
//统计回文数
int main()
{
	string A, B, ret;
	int count = 0;
	cin >> A >> B;

	for (int i = 0; i <= A.size(); ++i)
	{
		ret = A;
		ret.insert(i, B);

		string str = ret;
		reverse(str.begin(), str.end());
		if (ret == str)
			++count;
	}

	cout << count << endl;

	system("pause");
	return 0;
}
#endif

//排序子序列：牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
//牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,
//牛牛想知道他最少可以把这个数组分为几段排序子序列.
//输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
//第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 表示数组A的每个数字。
int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	int i = 0;
	for (i=0; i < n; ++i)
	{
		cin >> a[i];
	}

	i = 0;
	int count = 0;
	while (i < n)
	{
		//非递减子序列
		if (a[i] < a[i + 1])
		{
			while (i < n&&a[i] <= a[i + 1])
			{
				++i;
			}
			++i;
			++count;
		}
		else if (a[i] == a[i + 1])
		{
			++i;
		}
		else//非递增子序列
		{
			while (i < n&&a[i] >= a[i + 1])
			{
				++i;
			}
			++i;
			++count;
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}