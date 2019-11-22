#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

//�������������������1�ĸ���
//1.����λ����
#if 0
int main()
{
	int n,count;
	while (cin >> n) {
		count = 0;
		if (0 == n) {
			cout << 0 << endl;
			break;
		}
		while (n) {
			n &= n - 1;
			++count;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif

//2.λͼ
#if 0
class Solution
{
public:
	static int findNumberOf1(int num) {
		bitset<32> bs(num);
		return bs.count();
	}
};

int main()
{
	int n;
	while (cin >> n) {
		Solution s;
		cout << s.findNumberOf1(n) << endl;
	}

	system("pause");
	return 0;
}
#endif

//����(���Ƴ���ԭ��)
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int left_min = INT_MAX, left_sum = 0;
		int right_min = INT_MAX, right_sum = 0;
		int sum = 0;

		for (int i = 0; i < n; ++i) {
			if (left[i] * right[i] == 0) {//�κ���ɫֻҪ��һ��Ϊ0������Ҫ��ͬ����ɫ��ȫ����
				sum += left[i] + right[i];
			}
			else
			{
				//ͳ��������ĳ��ɫ�������ٵ����׸����Լ��������ߵ�����
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);

				left_sum += left[i];
				right_sum += right[i];
			}
		}
		//�Ƚ���������(left,right)_sum��ֵ��ȡ��С��һ��+1����֤�ܸ������е���ɫ������һ������ȡһ���������ж�Ӧ��ɫ������
		//��Ҫ���˼���sum
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

int main()
{
	int n = 4;
	vector<int> v1 = { 0,7,1,6 };
	vector<int> v2 = { 1,5,0,6 };

	Gloves g;
	cout << g.findMinimum(n, v1, v2) << endl;

	system("pause");
	return 0;
}