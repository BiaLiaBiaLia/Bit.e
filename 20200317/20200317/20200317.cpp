#include<iostream>
using namespace std;

//员工考勤记录
int main()
{
	int n;
	cin >> n;
	int cnt = 1;//全勤
	cnt += n;//缺勤一天
	int a = 1, b = 1;
	for (int i = n; i > 0; i--) {
		if (i > n - 2)
			a *= i;
		if (i <= 2)
			a /= i;
	}
	cout << cnt + a << endl;

	system("pause");
	return 0;
}