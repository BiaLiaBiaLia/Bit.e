#include <iostream>
#include <vector>
using namespace std;

//栈的压入,弹出序列
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (!pushV.size())
			return false;
		vector<int> v;
		for (int i = 0,j=0; i < pushV.size(); ++i) {
			v.push_back(pushV[i]);
			while (j < popV.size() && v.back() == popV[j]) {
				v.pop_back();
				++j;
			}
		}
		return v.empty();
	}
};

int main()
{
	Solution s;
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2{ 4,5,3,2,1 };
	vector<int> v3{ 4,3,5,1,2 };

	cout << s.IsPopOrder(v1,v2) << endl;
	cout << s.IsPopOrder(v1,v3) << endl;

	system("pause");
	return 0;
}