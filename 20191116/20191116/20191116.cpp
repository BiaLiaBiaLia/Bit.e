#include <iostream>
#include <vector>
using namespace std;

/*
位的异或运算跟求'和'的结果一致：
异或 1 ^ 1 = 0 1 ^ 0 = 1 0 ^ 0 = 0
求和 1 + 1 = 0 1 + 0 = 1 0 + 0 = 0
位的与运算跟求'进位‘的结果一致：
位与 1 & 1 = 1 1 & 0 = 0 0 & 0 = 0
进位 1 + 1 = 1 1 + 0 = 0 0 + 0 = 0
*/
//另类加法
#if 0
class UnusualAdd {
public:
	int addAB(int A, int B) {
		while (A) {
			int temp = B;
			B = A ^ B;
			A = A & temp;
			A <<= 1;
		}

		return B;
	}
};

int main()
{
	UnusualAdd u;
	cout << u.addAB(7, 3) << endl;

	system("pause");
	return 0;
}
#endif
//算法之给定一个n*m的格子或棋盘，如何计算从左上角走到右下角的走法总数？
int main()
{
	int m, n;
	cin >> m >> n;

	int sum = 0;
	int sum1 = 1;
	int sum2 = 1;

	if (n >= m) {
		for (int i = n + 1; i <= (m + n); i++) {
			sum1 = sum1 * i;
		}

		for (int i = 1; i <= m; i++) {
			sum2 = sum2 * i;
		}

	}
	else {
		for (int i = m + 1; i <= (m + n); i++) {
			sum1 = sum1 * i;
		}

		for (int i = 1; i <= n; i++) {
			sum2 = sum2 * i;
		}
	}
	sum = sum1 / sum2;

	cout << sum << endl;

	system("pause");
	return 0;
}