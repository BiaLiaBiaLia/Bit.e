#include <iostream>
using namespace std;

//Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。
//现在小Y使用1024元的纸币购买了一件价值为N (0 < N \le 1024)N(0<N≤1024)的商品，请问最少他会收到多少硬币？
//输入描述:
//一行，包含一个数N。
//输出描述 :
//一行，包含一个数，表示最少收到的硬币数。

int main() {
	int n;
	cin >> n;
	int m = 1024 - n;
	int count = 0;
	count += m / 64;
	m %= 64;
	count += m / 16;
	m %= 16;
	count += m / 4;
	m %= 4;
	count += m / 1;
	cout << count << endl;

	system("pause");
	return 0;
}