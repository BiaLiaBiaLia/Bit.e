#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		map<int, int> mp;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		for (auto& i : nums)
			mp[i]++;
		for (auto& p : mp) {
			pq.push(pair<int, int>(p.second, p.first));
			if (pq.size() > k)
				pq.pop();
		}

		while (k--) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};

int main()
{
	vector<int> v = { 1,1,1,2,2,3 };
	Solution s;
	vector<int> res = s.topKFrequent(v, 2);

	for (auto& i : res)
		cout << i << " ";

	cout << endl;

	system("pause");
	return 0;
}