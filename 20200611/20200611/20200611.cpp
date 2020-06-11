#include <iostream>
using namespace std;

class Solution {
public:
	/**
	 * @param n int整型
	 * @param a int整型一维数组
	 * @param aLen int a数组长度
	 * @return int整型
	 */
	int ispri(int n)
	{
		if (n <= 3) 
			return 1;
		for (int i = 2; i*i <= n; i++)
		{
			if (n%i == 0) 
				return 0;
		}
		return 1;
	}


	int maxpri(int n)
	{
		for (int i = n; i >= 3; --i)
		{
			if (ispri(i)) 
				return i;
		}
	}

	int npri(int n)
	{
		int temp = n;
		int ret = 0;
		if (!ispri(n))
		{
			if (n % 2 == 0 || ispri(n - 2)) 
				ret = 1;
			else ret = 2;
		}
		return ret;
	}

	int work(int n, int* a, int aLen) {
		int ret = n;
		int det;
		for (int i = 0; i < aLen - 1; i++)
		{
			det = a[i + 1] - a[i];
			ret += npri(det);
		}
		return ret;
	}

};

int main()
{
	Solution s;
	int n = 3;
	int a[] = { 0,7,11 };
	int aLen = sizeof(a) / sizeof(a[0]);

	cout << s.work(n, a, aLen) << endl;

	system("pause");
	return 0;
}