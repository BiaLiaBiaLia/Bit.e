#include <iostream>
#include <algorithm>
using namespace std;


//二进制插入
//将m的二进制位数插入到n的j->i二进制位中
#if 0
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		int count = 0;
		for (int x = j; x <= i; ++x) {
			int temp = m & (1 << count++);
			if (0 == temp)
				continue;
			n ^= (1 << x);
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
bool is_prime(int num) {
	if (2 == num)
		return true;
	for (int i = 2; i <= sqrt(num); ++i) {
		if (0 == num % i)
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n) {
		int mid = n / 2;
		for (int i = mid; i > 1; --i) {
			if (is_prime(i) && is_prime(n - i)) {
				cout << i << endl;
				cout << n - i << endl;
				break;
			}
		}
	}

	system("pause");
	return 0;
}