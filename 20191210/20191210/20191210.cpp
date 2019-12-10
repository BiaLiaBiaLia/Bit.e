#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void reOrderArray1(vector<int> &array) {  //不能保证交换完后奇偶数相对位置不变
		for (int i = 0; i < array.size(); ++i) {
			int j = i+1;
			if (array[i] % 2 == 0) {
				while (array[j]%2 != 1) {
					++j;
				}
				swap(array[i], array[j]);
				if (j == array.size() - 1)
					break;
			}
		}
	}

	void reOrderArray2(vector<int> &array) {  //时间换空间
		vector<int> v1;
		vector<int> v2;
		for (auto &e : array) {
			if (e % 2 == 0)
				v2.push_back(e);
			else
				v1.push_back(e);
		}

		array.clear();

		for (auto &e : v1) {
			array.push_back(e);
		}

		for (auto &e : v2) {
			array.push_back(e);
		}
	}

	void reOrderArray3(vector<int> &array) {  //插入排序的思想：删偶数，尾插偶数
		vector<int>::iterator vi = array.begin();
		int size = array.size();
		while (size)
		{
			if (*vi % 2 == 0)
			{
				int tmp = *vi;
				vi = array.erase(vi);
				array.push_back(tmp);
			}
			else
				vi++;
			size--;
		}
	}
};

int main()
{
	Solution s;
	vector<int> v{ 1,2,3,4,5,6,7 };
	s.reOrderArray3(v);
	for (auto &e : v) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}