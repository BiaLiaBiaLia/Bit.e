#include <iostream>
#include <string>
using namespace std;

//最难的问题(消息加密)
#if 0
int main()
{
	string str;
	while (getline(cin, str)) {
		string ret;
		for (int i = 0; i < str.size(); ++i) {
			if (' ' == str[i])
				ret += ' ';
			else if (str[i] >= 'A' && str[i] <= 'E')
				ret += str[i] + 21;
			else
				ret += str[i] - 5;
		}
		cout << ret << endl;
	}

	system("pause");
	return 0;
}
#endif


//因子个数(相同的算一个)
int main()
{
	int n;
	while (cin >> n) {
		int count=0;
		for (int i = 2; i < sqrt(n); ++i) {
			if (0 == n % i) {
				while (0 == n % i) {
					n /= i;
				}
				++count;
			}
		}
		if (n != 1)
			++count;	
		cout << count << endl;
	}

	system("pause");
	return 0;
}