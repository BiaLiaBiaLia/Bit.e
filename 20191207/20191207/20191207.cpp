#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//奇位数上都是奇数，偶数位上都是偶数
#if 0
class Solution {
public:
	/**
	 *  奇数位上都是奇数或者偶数位上都是偶数
	 *  输入：数组arr，长度大于2
	 *  len：arr的长度
	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	 */
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		while (i < len && j < len)
		{
			if (arr[len - 1] % 2 == 0)
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};

int main()
{
	vector<int> v{ 7,7,9,5,1,6,7,9,3,2,6 };
	int len = v.size();

	Solution s;
	s.oddInOddEvenInEven(v, len);
	for (auto &e : v) {
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif

//猴子分桃问题
/*老猴子辛苦了一辈子，给那群小猴子们留下了一笔巨大的财富——一大堆桃子。老猴子决定把这些桃子分给小猴子。
第一个猴子来了，它把桃子分成五堆，五堆一样多，但还多出一个。它把剩下的一个留给老猴子，自己拿走其中的一堆。
第二个猴子来了，它把桃子分成五堆，五堆一样多，但又多出一个。它把多出的一个留给老猴子，自己拿走其中的一堆。
后来的小猴子都如此照办。最后剩下的桃子全部留给老猴子。
这里有n只小猴子，请你写个程序计算一下在开始时至少有多少个桃子，以及最后老猴子最少能得到几个桃子。
*/
int main()
{
	int n;
	while (cin >> n && n > 0)
	{
		cout << (long)pow(5, n) - 4 << " " << (long)pow(4, n) + n - 4 << endl;
	}

	system("pause");
	return 0;
}