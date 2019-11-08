#include <iostream>
using namespace std;


class Solution
{
public:
//跳台阶
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
//假设第一次跳的是一阶，那么剩下的n-1个台阶，跳法是f(n-1)
//假设第一次跳的是两阶，那么剩下的n - 2个台阶，跳法是f(n - 2)
//由上面两种假设可得：f(n) = f(n - 1) + f(n - 2)
	int jumpFloor(int number)
	{
		if (number <= 0)
			return 0;
		if (number <= 2)
			return number;

		int x = 1;//跳一阶台阶只有一种跳法
		int y = 2;//跳一阶台阶只有两种跳法
		int z;
		for (int i = 3; i <= number; ++i)
		{
			z = x + y;
			x = y;
			y = z;
		}
		return z;
	}


//变态跳台阶
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
//当n = n 时
//第一次跳出一阶后，后面还有f(n-1)中跳法；
//第一次跳出二阶后，后面还有f(n-2)中跳法......第一次跳出n阶后，后面还有 f(n-n)中跳法
//f(n) = f(n-1) + f(n-2) +...+ f(2) + f(1) + 1
//f(n - 1) = f(n - 2) + ... + f(2) + f(1) + 1
//上下一减 得：f(n)=2*f(n-1)
	int jumpFloorII(int number)
	{
		if (number <= 0)
			return 0;
		if (1 == number)
			return 1;

		int f = 1;//表示n=1时，只有一种跳法
		for (int i = 2; i <= number; ++i)
		{
			f = 2 * f;
		}
		return f;
	}
};

int main()
{
	Solution s;
	cout << s.jumpFloor(5) << endl;
	cout << s.jumpFloorII(5) << endl;

	system("pause");
	return 0;
}
