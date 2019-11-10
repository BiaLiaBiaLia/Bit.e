#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#if 0
int main()
{
	//十进制转其他进制(2<=N<=16)
	int M, N;
	cin >> M >> N;
	string ret;
	string str{ "0123456789ABCDEF" };

	int flag = 1;//默认输入的数为正数
	if (M < 0)
	{
		flag = 0;
		M = -M;//处理为正数
	}

	while (M)
	{
		ret += str[M%N];
		M /= N;
	}

	if (flag == 0)
	{
		ret += '-';
	}

	reverse(ret.begin(), ret.end());

	cout << ret << endl;

	system("pause");
	return 0;
}
#endif

/*输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，
则删除之后的第一个字符串变成”Thy r stdnts.”*/

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	// 使用哈希映射思想先统计str2字符出现的次数
	int hashtable[256] = { 0 };
	for (int i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)
// 因为边遍历，边erase，容易出错。
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