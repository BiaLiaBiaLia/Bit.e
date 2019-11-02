#include <iostream>
#include <vector>
using namespace std;

//数字中出现次数超过一半的数字
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		if (numbers.size() <= 0)
			return 0;

		int count = 1;
		int temp = numbers[0];
		int length = numbers.size();
		for (int i = 1; i < length; i++) 
		{
			if (count == 0) {
				temp = numbers[i];
				count = 1;
			}
			else if (numbers[i] == temp)
				count++;
			else
				count--;
		}

		int result = temp;

		int times = 0;
		for (int i = 0; i < length; i++) 
		{
			if (numbers[i] == result)
				times++;
		}
		if (times <= length / 2)
			return 0;
		else
			return result;
	}
};


int main()
{
	Solution s;
	vector<int> m = { 1,2,3,2,2,2,5,4,2 };

	cout << s.MoreThanHalfNum_Solution (m)<< endl;
	system("pause");
	return 0;
}