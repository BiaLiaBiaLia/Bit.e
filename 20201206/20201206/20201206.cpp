#include <iostream>
#include <vector>
using namespace std;

//ɾ�����������е��ظ������������ЧԪ�صĸ���
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {  //ɾ���������ظ�Ԫ�أ�ʱ�����̫��
		if (0 == nums.size())
			return 0;
		auto it = nums.begin();
		while (it != nums.end()-1) {
			if (*it == *(it + 1))
				it = nums.erase(it);
			else
				++it;
		}
		return nums.size();
	}
};
*/

#if 0
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		int i = 0;
		for (int j = 1; j < nums.size(); ++j) {
			if (nums[i] == nums[j])
				continue;
			nums[++i] = nums[j];              //���ظ���Ԫ�ظ��ǵ�ǰ����Ԫ�أ�����++i����Ϊ�Ǵ�0��ʼ��
		}
		return ++i;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,1,2 };
	cout << s.removeDuplicates(nums)<<endl;
	system("pause");
	return 0;
}
#endif

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows);
		for (size_t i = 0; i < numRows; ++i) {
			res[i].resize(i + 1);
			res[i][0] = res[i][i] = 1;
			for (size_t j = 1; j < i; ++j)
				res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
		}

		return res;
	}
};

int main()
{
	Solution s;
	int n;
	cin >> n;
	vector<vector<int>> ret = s.generate(n);

	system("pause");
	return 0;
}