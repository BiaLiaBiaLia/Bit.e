#include <iostream>
#include <vector>
using namespace std;


//����ܺ�3
//�ҳ��������֮��Ϊn��k�����������ֻ������1-9��������������ÿ���в������ظ�����
class Solution {
public:
	vector<vector<int>> res;
	vector<int> cur;
	void backtrack(int k, int n, vector<int> cur, int sum, int start) {
		if (k > 9 || k < 1)
			return;
		if (sum > n || cur.size() > k)
			return;
		if (sum == n && cur.size() == k) {
			res.push_back(cur);
			return;
		}
		for (int i = start; i < 10; ++i) {
			sum += i;
			cur.push_back(i);
			backtrack(k, n, cur, sum, i + 1);
			sum -= i;
			cur.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		backtrack(k, n, cur, 0, 1);
		return res;
	}
};

int main()
{
	Solution s;
	int k, n;
	cin >> k >> n;
	vector<vector<int>> res = s.combinationSum3(k, n);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
