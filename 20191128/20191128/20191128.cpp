#include <iostream>
#include <string>
using namespace std;

//字符串反转
//写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串
#if 0
int main()
{
	string n;
	while (cin >> n) {
		int len = n.size();
		for (int i = 0; i < len / 2; ++i) {
			swap(n[i], n[len - i - 1]);
		}
		cout << n << endl;
	}

	system("pause");
	return 0;
}
#endif

//计算最大公共字符串的长度
int main()
{
	string a, b, ret;
	int count;  //保存最大公共字符串的长度
	while (cin >> a >> b) {
		count = 0;
		if (a.size() > b.size())
			swap(a, b);
		for (int i = 0; i < a.size(); ++i) {
			for (int j = i; j < a.size(); ++j) {
				string temp = a.substr(i, j - i + 1);
				int flag = b.find(temp);
				if (flag < 0)  //说明在b中没找到公共字符串
					break;
				else if (temp.size() > ret.size()) {
					ret = temp;
					count = ret.size();
				}
			}
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}