#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void Printdoubvec(vector<vector<int>> vv) {
	for (int i = 0; i < vv.size(); ++i) {
		cout << '[';
		for (int j = 0; j < vv[i].size(); ++j)
			cout << vv[i][j] << " ";
		cout << ']';
		cout << endl;
	}
}
#if 0
//组合总和
//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
class Solution {
public:
	vector<vector<int>> res;
	vector<int> cur;
	void backtrack(vector<int>& candidates,int target,int sum,int startIndex) {
		if (sum > target)
			return;
		if (sum == target) {
			res.push_back(cur);
			return;
		}
		// 这里i 依然从 startIndex开始，因为求的是组合，如果求的是排列，那么i每次都从0开始
		for (int i = startIndex; i < candidates.size(); ++i) {
			sum += candidates[i];
			cur.push_back(candidates[i]);
			backtrack(candidates, target, sum, i);  //关键点在这儿,i不用+1,表示可以重复读取当前的数
			sum -= candidates[i];
			cur.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		backtrack(candidates,target,0,0);
		return res;
	}
};

int main() {
	vector<int> candidates = { 2,3,6,7 };
	Solution s;
	vector<vector<int>> res = s.combinationSum(candidates, 7);
	Printdoubvec(res);

	system("pause");
	return 0;
}
#endif

#if 0
//组合问题
//给出两个整数n和k，求在1..n这n个数字中选出k个数字的所有组合
//如  n=4，k=2
//结果为[ [1,2][1,3][1,4][2,3][2,4][3,4] ]
class Solution {
public:
	vector<vector<int>> res;
	vector<int> cur;
	//求解C(n,k)，当前已经找到的组合存储在cur中，需要从startIndex开始搜索新元素
	void generateCombinations(int n, int k,int startIndex) {
		if (cur.size() == k) {
			res.push_back(cur);
			return;
		}
		/*for (int i = startIndex; i <= n; ++i) {  //i<=n,可以优化,此处cur已经放进了cur.size()个元素,还有k-cur.size()个空位
			cur.push_back(i);                    //所以[i..n]中至少还需要有k-cur.size()个元素，也就是 n-i>=k-cur.size()+1
			generateCombinations(n, k, i + 1);   //所以此处可以更改为i<=n-(k-cur.size())+1
			cur.pop_back(); 
		}*/

		for (int i = startIndex; i <= n - (k - cur.size())+1; ++i) {
			cur.push_back(i);
			generateCombinations(n, k, i + 1);
			cur.pop_back();
		}
	}
	vector<vector<int>> comnine(int n, int k) {
		generateCombinations(n, k, 1);
		return res;
	}
};
#endif

//给定一个数组 candidates 和一个目标数 target ，找出 candidates中所有可以使数字和为 target 的组合。
//candidates 中的每个数字在每个组合中只能使用一次。
class Solution {
public:
	vector<vector<int>> res;
	vector<int> cur;
	void backtrack(vector<int>& candidates, int target, int sum, int startIndex) {
		if (sum > target)
			return;
		if (sum == target) {
			res.push_back(cur);
			return;
		}
		for (int i = startIndex; i < candidates.size(); ++i) {
			if (i > startIndex&&candidates[i] == candidates[i - 1])
				continue;
			cur.push_back(candidates[i]);
			sum += candidates[i];
			backtrack(candidates, target, sum, i + 1);
			sum -= candidates[i];
			cur.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0, 0);
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> candidates{ 10,1,2,7,6,1,5 };
	vector<vector<int>> res = s.combinationSum2(candidates, 8);
	Printdoubvec(res);

	system("pause");
	return 0;
}