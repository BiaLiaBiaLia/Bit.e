#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1030. 距离顺序排列矩阵单元格
//lambda表达式
class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> ret;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				ret.push_back({ i, j });
			}
		}
		sort(ret.begin(), ret.end(), [=](vector<int>& a, vector<int>& b) {
			return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
		});
		return ret;
	}

	void Pri_vec(vector<vector<int>> res) {
		for (int i = 0; i < res.size(); ++i) {
			for (int j = 0; j < res[i].size(); ++j) {
				cout << '[' << res[i][j] << ']' << " ";
			}
		}
	}
};

int main()
{
	Solution s;
	int R, C, r0, c0;
	cin >> R>> C>> r0>> c0;

	vector<vector<int>> res = s.allCellsDistOrder(R, C, r0, c0);
	s.Pri_vec(res);

	system("pause");
	return 0;
}