#include<iostream>
using namespace std;

//��Ŀ����
//��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�������K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ���
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