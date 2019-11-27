#include <iostream>
#include <string>
using namespace std;

//汽水瓶
//三个空瓶子可以换一瓶新汽水,有两盖子时可先借一瓶
#if 0
int main() 
{
	int n;	
	while (cin >> n) {

		int news = 0, surplus = 0, count = 0;

		while (n >= 3) {
			count = n / 3;  //新的瓶盖数==可以喝的汽水瓶数
			news += count;  //一共可以喝的汽水瓶数
			surplus = n % 3;  //没有换掉的汽水瓶盖数
			n = count + surplus;
		}
		if (2 == n)
			cout << news + 1 << endl;
		else
			cout << news << endl;
	}

	system("pause");
	return 0;
}
#endif

//查找两个字符串a,b中的最长公共子串
//如果有多个，则输出在串联中最先出现的那个
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())
			swap(a, b);
		string str_m;//存储最长公共子串
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (int(b.find(temp)) < 0)
					break;
				else if (str_m.size() < temp.size())
					str_m = temp;
			}
		}
		cout << str_m << endl;
	}

	system("pause");
	return 0;
}