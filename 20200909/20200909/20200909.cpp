#include <iostream>
#include <vector>
using namespace std;

#if 0
//1.�Ӽ�(��ѧ����)
//subset([1,2,3])= A + [A[i].add(3) for i = 1..len(A)]
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		// base case������һ���ռ�
		if (nums.empty())
			return { {} };
		// �����һ��Ԫ���ó���
		int n = nums.back();
		nums.pop_back();
		// �ȵݹ����ǰ��Ԫ�ص������Ӽ�
		vector<vector<int>> res = subsets(nums);

		int size = res.size();
		for (int i = 0; i < size; i++) {
			// Ȼ����֮ǰ�Ľ��֮��׷��
			res.push_back(res[i]);
			res.back().push_back(n);
		}
		return res;
	}
};
#endif

#if 0
//1.�Ӽ�(�����㷨)
class Solution {
public:
	vector<vector<int>> res;

	vector<vector<int>> subsets(vector<int>& nums) {
		// ��¼�߹���·��
		vector<int> track;
		backtrack(nums, 0, track);
		return res;
	}

	void backtrack(vector<int>& nums, int start, vector<int>& track) {
		res.push_back(track);
		for (int i = start; i < nums.size(); i++) {
			// ��ѡ��
			track.push_back(nums[i]);
			// ����
			backtrack(nums, i + 1, track);
			// ����ѡ��
			track.pop_back();
		}
	}
};

int main()
{
	vector<int> n = { 1,2,3 };
	vector<vector<int>> res;
	Solution s;
	res = s.subsets(n);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
#endif