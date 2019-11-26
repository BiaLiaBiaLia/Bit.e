#include <iostream>
#include <bitset>
using namespace std;

//矩形覆盖
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//可用递归f(n)=f(n-1)+f(n-2)：n行可看成一组小排+2*(n-1)+两组竖排+2*(n-2)
//还是考察斐波那契额数列
#if 0
class Solution {
public:
	int rectCover(int number) {
		if (number < 1)
			return 0;
		else if (number > 0 && number < 3)
			return number;
		else {
			int a = 1, b = 2, c;
			for (int i = 3; i <= number; ++i) {
				c = a + b;
				a = b;
				b = c;
			}
			return c;
		}
	}
};

int main()
{
	Solution s;
	int n;

	while (cin >> n) {
		cout << s.rectCover(n) << endl;
	}

	system("pause");
	return 0;
}
#endif

//二进制中1的个数
#if 0
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n) {
			n &= n - 1; //位的经典运算
			++count;
		}
		return count;
	}

	int  NumberOf2(int n) {  //位图
		bitset<32> bs(n);
		return bs.count();
	}
};

int main()
{
	Solution s;
	int n;
	while (cin >> n) {
		cout << s.NumberOf1(n) << endl;
		cout << s.NumberOf2(n) << endl;
	}

	system("pause");
	return 0;
}
#endif

//数值的整数次方
class Solution {
public:
	double Power(double base, int exponent) {
		if (0.0 == base)
			return 0.0;
		double result = 1.0;
		int x = exponent > 0 ? exponent : -exponent;
		for (int i = 0; i < x; ++i) {
			result *= base;
		}
		return exponent > 0 ? result : 1 / result;
	}
};

int main()
{
	Solution s;
	double b;
	int ex;
	while (cin >> b >> ex) {
		cout << s.Power(b, ex) <<  endl;
	}

	system("pasue");
	return 0;
}