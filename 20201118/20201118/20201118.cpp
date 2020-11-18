#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int i = 0;  //从第0号加油站开始尝试
		int n = gas.size();  //一共有多少家加油站
		while (i < n) {
			int sumofgas = 0;  //总共加的油
			int sumofcost = 0;  //总共消耗的油
			int count = 0;  //记录走过加油站的个数
			while (count < n) {  //退出条件是走过的所有的加油站
				int j = (count + i) % n;  //站是循环的  (走过的+起始位置)%n=当前位置
				sumofgas += gas[j];
				sumofcost += cost[j];

				if (sumofcost > sumofgas)  //消耗大于获取则退出
					break;
				else
					++count;
			}
			if (count == n)  //说明走完一圈了
				return i;  //返回起始站点编号
			else
				i = i + count + 1;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };

	cout << s.canCompleteCircuit(gas, cost) << endl;

	system("pause");
	return 0;
}