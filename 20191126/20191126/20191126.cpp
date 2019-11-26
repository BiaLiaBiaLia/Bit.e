#include <iostream>
#include <bitset>
using namespace std;

//���θ���
//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
//������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
//���õݹ�f(n)=f(n-1)+f(n-2)��n�пɿ���һ��С��+2*(n-1)+��������+2*(n-2)
//���ǿ���쳲�����������
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

//��������1�ĸ���
#if 0
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n) {
			n &= n - 1; //λ�ľ�������
			++count;
		}
		return count;
	}

	int  NumberOf2(int n) {  //λͼ
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

//��ֵ�������η�
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