#include <iostream>
#include <vector>
using namespace std;

#if 0
//数组中出现次数超过一半的数字
class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int max = numbers[0];
		for (int i = 1; i < numbers.size(); ++i)
		{
			if (numbers[i] > max)
				max = numbers[i];
		}

		vector<int> arr(max + 1);
		for (int i = 0; i < numbers.size(); i++)
		{
			arr[numbers[i]]++;
		}

		int _max = arr[0];
		int count = 0;
		for (int i = 1; i <= max; ++i)
		{
			if (arr[i] > _max)
			{
				_max = arr[i];
				count = i;
			}
		}
		if (_max > numbers.size() / 2)
			return count;
		else
			return 0;
	}
};

int main()
{
	Solution s;
	vector<int> x = { 1 };
	cout << s.MoreThanHalfNum_Solution(x) << endl;

	system("pause");
	return 0;
}
#endif

//数组中只出现一次的数字
class Solution
{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		if (data.size() < 2)
			return;

		int x = 0;
		for (int e : data)//所有数全部异或,得到两个不同数的异或x
			x ^= e;

		int i;//记录x二进制中第一个1的位置(也就是这两个数不同的一个部分,可将整个数组划分为记录位置为1的,和为0的)
		for (i = 0; i < data.size(); ++i)
		{
			if ((x&(1 << i)) != 0)
			{
				break;
			}
		}

		int _num1 = 0;
		int _num2 = 0;
		for (int e : data)
		{
			if ((e&(1 << i)) == 0)//记录位置为0的数全部异或可得到其中一个数
				_num1 ^= e;
			else                  //另一个数
				_num2 ^= e;
		}

		*num1 = _num1;
		*num2 = _num2;
	}
};

void Test()
{
	Solution s;
	vector<int> v = { 1,1,2,2,3,4,4,5,5,6,7,7 };
	int* num1=&v[0];
	int* num2=&v[1];

	s.FindNumsAppearOnce(v, num1, num2);
	cout << *num1 << " " << *num2 << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}