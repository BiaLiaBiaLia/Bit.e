#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��λ���϶���������ż��λ�϶���ż��
#if 0
class Solution {
public:
	/**
	 *  ����λ�϶�����������ż��λ�϶���ż��
	 *  ���룺����arr�����ȴ���2
	 *  len��arr�ĳ���
	 *  ��arr����������λ�϶�����������ż��λ�϶���ż��
	 */
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		while (i < len && j < len)
		{
			if (arr[len - 1] % 2 == 0)
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};

int main()
{
	vector<int> v{ 7,7,9,5,1,6,7,9,3,2,6 };
	int len = v.size();

	Solution s;
	s.oddInOddEvenInEven(v, len);
	for (auto &e : v) {
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif

//���ӷ�������
/*�Ϻ���������һ���ӣ�����ȺС������������һ�ʾ޴�ĲƸ�����һ������ӡ��Ϻ��Ӿ�������Щ���ӷָ�С���ӡ�
��һ���������ˣ��������ӷֳ���ѣ����һ���࣬�������һ��������ʣ�µ�һ�������Ϻ��ӣ��Լ��������е�һ�ѡ�
�ڶ����������ˣ��������ӷֳ���ѣ����һ���࣬���ֶ��һ�������Ѷ����һ�������Ϻ��ӣ��Լ��������е�һ�ѡ�
������С���Ӷ�����հ졣���ʣ�µ�����ȫ�������Ϻ��ӡ�
������nֻС���ӣ�����д���������һ���ڿ�ʼʱ�����ж��ٸ����ӣ��Լ�����Ϻ��������ܵõ��������ӡ�
*/
int main()
{
	int n;
	while (cin >> n && n > 0)
	{
		cout << (long)pow(5, n) - 4 << " " << (long)pow(4, n) + n - 4 << endl;
	}

	system("pause");
	return 0;
}