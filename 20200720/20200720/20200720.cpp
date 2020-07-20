#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int k = 0;
		for (int i = 0; i < array.size(); ++i) {
			if (array[i] & 1) {
				int temp = array[i];
				int j = i;
				while (j > k) {
					array[j] = array[j - 1];  //新奇数与旧奇数之间的偶数后移一位
					--j;
				}
				array[k++] = temp;  //放置新奇数,k后移一位
			}
		}
	}

	void printArray(vector<int> &array) {
		for (auto &e : array) {
			cout << e << " ";
		}
		cout << endl;
	}
};

int main()
{
	vector<int> v{ 1,2,3,4,5,6 };

	Solution s;
	s.printArray(v);
	s.reOrderArray(v);
	s.printArray(v);

	system("pause");
	return 0;
}