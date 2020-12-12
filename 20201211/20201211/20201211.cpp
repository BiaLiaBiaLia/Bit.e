#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//������
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sum = 0;  //ֻҪ��һ����ɫΪ0������ֻ�ָ���ɫȫ�ã�sumҲ�ͱ�ʾ�ı�����������
		int sum_left = 0, sum_right = 0, left_min = 27, right_min = 27;
		//�����ֳ�0֮���������׺�   &&  �����ֳ�0֮����ɫ���ٵ���������
		for (int i = 0; i < n; ++i) {
			if (0 == left[i] || 0 == right[i])
				sum += left[i] + right[i];
			else {
				sum_left += left[i];
				left_min = min(left_min, left[i]);
				sum_right += right[i];
				right_min = min(right_min, right[i]);
			}
		}

		//2ָ�����������ָ���һֻ
		int res = (sum_left - left_min) < (sum_right - right_min) ? (sum_left - left_min) : (sum_right - right_min);
		return res + 2 + sum;
	}
};

int main()
{
	Gloves g;
	vector<int> l = { 0,7,1,6 };
	vector<int> r = { 1,5,0,6 };
	cout << g.findMinimum(4, l, r) << endl;

	system("pause");
	return 0;
}