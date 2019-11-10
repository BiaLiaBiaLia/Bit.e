#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#if 0
int main()
{
	//由于N的取值范围是2~16
	string ret;
	string table("0123456789ABCDEF");

	int M;
	int N;
	cin >> M >> N;

	int flag = 1;//默认是正数
	if (M < 0)//假如是负数
	{
		flag = 0;
		M = -M;
	}

	while (M)
	{
		ret += table[M%N];
		M /= N;
	}

	if (flag == 0)//是负数
	{
		ret += '-';
	}
	//得反转一下字符串(之前是从后到前倒着存的)
	reverse(ret.begin(), ret.end());
	cout << ret << endl;

	system("pause");
	return 0;
}
#endif

int main()
{
	string str1, str2;

	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	for (int i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	string ret;
	for (int i = 0; i < str1.size(); ++i)
	{
		if (0 == hashtable[str1[i]])
		{
			ret += str1[i];
		}
	}

	cout << ret << endl;

	system("pause");
	return 0;
}