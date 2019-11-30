#include <iostream>
#include <vector>
#include <string>
using namespace std;

//小易的升级之路
#if 0
int gcd(int x, int y)  //最大公约数(辗转相除法)
{
	if (x < y)
		swap(x, y);
	return y == 0 ? x : gcd(y, x%y);
}

int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		int c = a;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			if (v[i] <= c)  //<=当前能力值时，直接增加v[i]
				c += v[i];
			else
			{
				int comnum = gcd(v[i], c);  //增加最大公约数
				c += comnum;
			}
		}
		cout << c << endl;
	}

	system("pause");
	return 0;
}
#endif

//找一个字符串中第一个只出现一次的字符
char FindFirst(string str) {
	int hashtable[256] = { 0 };
	for (int i = 0; i < str.size(); ++i) {
		hashtable[str[i]]++;
	}

	for (int i = 0; i < str.size(); ++i) {
		if (1 == hashtable[str[i]])
			return str[i];
	}
	return 0;
}

int main()
{
	string s;
	while (cin>>s) {
		char result = FindFirst(s);
		if (result == 0)
			cout << -1 << endl;
		else
			cout << result << endl;
	}

	system("pause");
	return 0;
}