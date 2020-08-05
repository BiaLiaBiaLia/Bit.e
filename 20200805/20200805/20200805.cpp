#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int len = sequence.size();
		if (len == 0)
			return false;
		return IsBST((int*)&sequence[0], len);
	}
	bool IsBST(int *s, int len) {
		if (!s || len == 0)
			return false;
		int root = s[len - 1];
		int i = 0;
		for (; i < len - 1; ++i) {
			if (s[i] > root)
				break;
		}
		for (int j = i; j < len - 1; ++j) {
			if (s[j] < root)
				return false;
		}
		bool left = true; bool right = true;
		if (i > 0)
			left = IsBST(s, i);
		if (len - i - 1 > 0)
			right = IsBST(s + i, len - i - 1);
		return (left && right);
	}
};

int main()
{
	Solution s;
	vector<int> v= { 6,7,8,5 };
	cout << s.VerifySquenceOfBST(v) << endl;

	system("pause");
	return 0;
}