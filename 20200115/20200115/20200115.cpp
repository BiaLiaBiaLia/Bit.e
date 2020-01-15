#include <iostream>
#include <vector>
using namespace std;

#if 0
//奇数位上都是奇数或者偶数位上都是偶数
class Solution {
public:
	void oddInOddEvenInEven(std::vector<int>& arr, int len) {
		long i = 0, j = 1;
		while (i < len && j < len) {
			if ((arr[i] % 2) == 0) { i += 2; continue; }//偶数位上寻找非偶数
			if ((arr[j] % 2) != 0) { j += 2; continue; }//奇数位上寻找非奇数
			swap(arr[i], arr[j]);
		}
	}
};

int main()
{
	Solution s;
	vector<int> v{ 1,2,3,4 };
	s.oddInOddEvenInEven(v, v.size());
	for (auto &e : v) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}
#endif

//猴子分桃
/*
因为每次分5堆都会多出来1个，所以我们借给猴子们4个，以致每次都可以刚好分成5堆 并且，每次给老猴子的桃
子都不在我们借出的那4个中，这样最后减掉4就可以得到结果。 假设最初由x个桃子，我们借给猴子4个，则此时
有x + 4个， 第一个猴子得到（x + 4） / 5，剩余（x + 4）（4 / 5）个 第二个猴子分完后剩余（x + 4）(4 / 5) ^ 2个 第三个
猴子分完后剩余（x + 4）(4 / 5) ^ 3个 依次类推，第n个猴子分完后剩余（x + 4）（4 / 5）^n 要满足最后剩余的为整
数，并且x最小，则当 x + 4 = 5 ^ n时，满足要求；此时，x = 5 ^ n - 4; 老猴子得到的数量为：x + 4）*（4 / 5）^n + n - 4
= 4 ^ n + n - 4 最后的 + n是因为每个小猴子都会多出一个给老猴子， - 4是还了借的4个
*/
int main()
{
	int n;
	while (std::cin >> n) {
		if (n == 0) break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		std::cout << total << " " << left << std::endl;
	}

	system("pause");
	return 0;
}