#include <iostream>
#include <vector>
using namespace std;

//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
//对于A长度为1的情况，B无意义，故而无法构建，因此该情况不会存在。
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int>B;
		if (A.size() <= 0) {
			return B;
		}
		int muit = 1;
		for (int i = 0; i < A.size(); ++i) {
			muit = 1;
			for (int j = 0; j < A.size(); j++) {
				if (j == i) {
					continue;
				}
				muit *= A[j];
			}
			B.push_back(muit);
		}
		return B;

	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,2,3,4,5 };
	vector<int> res = s.multiply(v);
	for (auto &e : res) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}