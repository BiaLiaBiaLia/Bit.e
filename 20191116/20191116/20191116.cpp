#include <iostream>
#include <vector>
using namespace std;

/*
λ������������'��'�Ľ��һ�£�
��� 1 ^ 1 = 0 1 ^ 0 = 1 0 ^ 0 = 0
��� 1 + 1 = 0 1 + 0 = 1 0 + 0 = 0
λ�����������'��λ���Ľ��һ�£�
λ�� 1 & 1 = 1 1 & 0 = 0 0 & 0 = 0
��λ 1 + 1 = 1 1 + 0 = 0 0 + 0 = 0
*/
//����ӷ�
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
//�㷨֮����һ��n*m�ĸ��ӻ����̣���μ�������Ͻ��ߵ����½ǵ��߷�������
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