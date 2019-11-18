#include <iostream>
#include <math.h>
using namespace std;

//二进制的插入
/*有两个32位整数n和m，
请编写算法将m的二进制位数插入到n的二进制的第j到第i位，
其中二进制的位数从低位数到高位且以0开始*/
#if 0
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		for (int x = j; x <= i; ++x) {
			int z = m & 1;
			m >>= 1;
			if (z != 0) {
				n |= z << x;
			}
		}
		return n;
	}
};

int main()
{
	BinInsert b;
	cout << b.binInsert(1024, 19, 2, 6) << endl;

	system("pause");
	return 0;
}
#endif

//查找组成一个偶数最接近的两个素数
bool IsPrime(int x) {
	if (0 == x % 2)
		return false;
	for (int i = 2; i <= sqrt(x*1.0); ++i) {
		if (0 == x % i)
			return false;
	}
	return true;
}

int main() {
	int n;
	int a, b;
	while (cin >> n) {
		if (n < 2)
			return 1;
		else {
			for (int i = 1; i <= n / 2; i++) {
				if (IsPrime(i) && IsPrime(n - i)) {
					a = i;
					b = n - i;
				}
			}
			cout << a << endl;
			cout << b << endl;
		}
	}

	system("pause");
	return 0;
}