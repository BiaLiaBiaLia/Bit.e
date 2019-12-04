#include <iostream>
#include <vector>
#include <string>
using namespace std;

//星际密码
//矩阵的n次方(n=给出的每个正整数),左上角数都是斐波那契额数列
#if 0
vector<int> v{ 1,1 };
void fibo_init() {
	for (int i = 2; i < 10001; ++i) {
		v.push_back((v[i - 1] + v[i - 2]) % 10000);  //保留四位所以%10000
	}
}

int main()
{
	int n, x;
	fibo_init();
	while (cin >> n) {
		while (n--) {
			cin >> x;
			printf("%04d", v[x]);  //数不足4位补0，需用到printf(%04d)
		}
		cout << endl;
	}

	system("pasue");
	return 0;
}
#endif

//求数跟
int num_heel(int n) {
	int sum = 0;
	while (n) {
		int x = n % 10;
		n /= 10;
		sum += x;
	}
	if (sum > 9)
		return num_heel(sum);
	else
		return sum;
}
int main()
{
	string n;
	while (cin >> n) {
		int count = 0;
		for (int i = 0; i < n.size(); ++i) {
			count += n[i] - '0';
		}
		cout << num_heel(count) << endl;
	}

	system("pause");
	return 0;
}