#include<iostream>
using namespace std;

//题目描述
//把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
int fun(int m, int n)
{
	if (m == 0 || n == 1)
		return 1;
	if (n > m)
		return fun(m, m);
	else
		return fun(m, n - 1) + fun(m - n, n);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (m >= 0 && m <= 10 && n >= 1 && n <= 10)
			cout << fun(m, n) << endl;
	}

	system("pause");
	return 0;
}