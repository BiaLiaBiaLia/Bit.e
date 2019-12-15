#include <iostream>
using namespace std;

//������1���ֵĴ���
class Solution {
public:
	int NumberOf1Between1AndN_Solution1(int n)  //����ÿ������Ч�ʵ���
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

	//�ο�ţ���������ͬ�ش�
	int NumberOf1Between1AndN_Solution2(int n)
	{
		int count = 0;
		long long i = 1;
		for (i = 1; i <= n; i *= 10)
		{
			//i��ʾ��ǰ����������һ����λ
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