#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//完全数计算(取巧，只为解题)
#if 0
int main()
{
	vector<int> v(5000001, 0);
	v[6] = 1;
	v[28] = 1;
	v[496] = 1;
	v[8128] = 1;
	int n;
	while (cin >> n) {
		if (n < 6)
			cout << 0 << endl;
		else if (n >= 6 && n < 28)
			cout << 1 << endl;
		else if (n >= 28 && n < 496)
			cout << 2 << endl;
		else if (n >= 496 && n < 8128)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int count, sum;
	int n;
	while (cin >> n) {
		count = 0;
		sum = 0;
		while (n != 0) {
			for (int i = 1; i < n; ++i) {
				if (0 == n % i)
					sum += i;
			}

			if (n == sum)
				++count;
			--n;
			sum = 0;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif

//扑克牌大小
/*根据题意，输入不可能非法，也不会相等，且顺子已排序
 *所以问题就简化为：
 *	判断牌个数：相等则比较最小牌，不相等则只有炸弹可比较
 *	特殊：王炸最大，只要有王炸就是王炸赢*/
int main()
{
	string str, table = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER"; // str接收出牌，table存放牌面大小
	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != -1) // 王炸最大，有王炸直接王炸赢
			cout << "joker JOKER" << endl;
		else
		{
			int cut = str.find('-'); //用‘-’将两方出牌分开
			string s1 = str.substr(0, cut);
			string s2 = str.substr(cut + 1);
			int c1 = count(s1.begin(), s1.end(), ' ') + 1; //计算第一方牌数(空格数+1)
			int c2 = count(s2.begin(), s2.end(), ' ') + 1; //计算第二方牌数(空格数+1)
			string f1 = s1.substr(0, s1.find(' ')); //得到第一方的第一张牌即最小牌
			string f2 = s2.substr(0, s2.find(' ')); //得到第二方的第一张牌即最小牌
			if (c1 == c2) //如果牌数相等直接比较大小(个子、对子、顺子、三个、炸弹相同之间比较最小值即可)
			{
				if (table.find(f1) > table.find(f2))
					cout << s1 << endl;
				else
					cout << s2 << endl;
			}
			else //如果牌数不相等，则只有炸弹可以与其他类型比较，如果不是炸弹则提示错误
			{
				if (c1 == 4)
					cout << s1 << endl;
				else if (c2 == 4)
					cout << s2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}

	system("pause");
	return 0;
}