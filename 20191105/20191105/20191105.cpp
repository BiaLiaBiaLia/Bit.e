#include <iostream>
#include <vector>
using namespace std;

//旋转数组的最小数字
//变相的二分查找
class Solution
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		if (rotateArray.empty())
			return 0;

		int low = 0;
		int high = rotateArray.size() - 1;
		int mid = 0;

		while (low < high)
		{
			if (rotateArray[low] < rotateArray[high])//特例:1,1,0,1,1
				return rotateArray[low];

			mid = low + (high - low) / 2;
			if (rotateArray[mid] > rotateArray[low])
				low = mid + 1;
			else if (rotateArray[mid] < rotateArray[high])
				high = mid;
			else
				low++;
		}
		return rotateArray[low];
	}
};

void Test()
{
	Solution s;
	vector<int> v = { 1,1,0,1,1 };
	cout << s.minNumberInRotateArray(v) << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}