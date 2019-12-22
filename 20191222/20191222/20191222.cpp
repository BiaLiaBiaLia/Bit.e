#include <iostream>
using namespace std;

//求1+2+3+···+n  不能使用乘除法和关键字
class Solution {
public:
	int Sum_Solution(int n) {
		int res = n;
		res && (res += Sum_Solution(n - 1));  //前面减到负数就不需要判断后面的递归了，递归结束
		return res;
	}
};

int main()
{
	Solution s;
	int n;
	while (cin >> n) {
		cout << s.Sum_Solution(n) << endl;
	}

	system("pause");
	return 0;
}