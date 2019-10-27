#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int i = array.size() - 1, j = 0;
		while (i >= 0 && j < array[0].size()) {
			if (target == array[i][j]) {
				return true;
			}
			else if (target > array[i][j]) {
				j++;
			}
			else if (target < array[i][j]) {
				i--;
			}
		}
		return false;

	}
};

int main()
{

	system("pause");
	return 0;
}