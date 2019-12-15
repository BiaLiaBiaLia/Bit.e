#include <iostream>
using namespace std;

//整数中1出现的次数
class Solution {
public:
	int NumberOf1Between1AndN_Solution1(int n)  //遍历每个数，效率低下
	{
		int count = 0;
		while (n) {
			int temp = n;
			while (temp) {
				if (1 == temp % 10)
					++count;
				temp /= 10;
			}
			--n;
		}
		return count;
	}

	//参考牛客网最高赞同回答
	int NumberOf1Between1AndN_Solution2(int n)
	{
		int count = 0;
		long long i = 1;
		for (i = 1; i <= n; i *= 10)
		{
			//i表示当前分析的是哪一个数位
			int a = n / i, b = n % i;
			count = count + (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
		}
		return count;
	}
};

int main()
{
	Solution s;
	int n;
	while (cin >> n) {
		cout << s.NumberOf1Between1AndN_Solution1(n) << endl;
		cout << s.NumberOf1Between1AndN_Solution2(n) << endl;
	}
	system("pause");
	return 0;
}