#include <iostream>
using namespace std;

//给定一个非负整数N，如果用二进制数表达N!的结果，返回最低位的1在哪个位置上，认为最右的位置为位置0。
int main()
{
	long long n;
	long long res = 0;
	cin >> n;

	while (n) {
		res += n / 2;
		n /= 2;
	}

	cout << res << endl;

	system("pause");
	return 0;
}