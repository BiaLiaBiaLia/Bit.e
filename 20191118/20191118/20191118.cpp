#include <iostream>
#include <math.h>
using namespace std;

//�����ƵĲ���
/*������32λ����n��m��
���д�㷨��m�Ķ�����λ�����뵽n�Ķ����Ƶĵ�j����iλ��
���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ*/
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

//�������һ��ż����ӽ�����������
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