#include <iostream>
#include <vector>
using namespace std;

#if 0
//����λ�϶�����������ż��λ�϶���ż��
class Solution {
public:
	void oddInOddEvenInEven(std::vector<int>& arr, int len) {
		long i = 0, j = 1;
		while (i < len && j < len) {
			if ((arr[i] % 2) == 0) { i += 2; continue; }//ż��λ��Ѱ�ҷ�ż��
			if ((arr[j] % 2) != 0) { j += 2; continue; }//����λ��Ѱ�ҷ�����
			swap(arr[i], arr[j]);
		}
	}
};

int main()
{
	Solution s;
	vector<int> v{ 1,2,3,4 };
	s.oddInOddEvenInEven(v, v.size());
	for (auto &e : v) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}
#endif

//���ӷ���
/*
��Ϊÿ�η�5�Ѷ�������1�����������ǽ��������4��������ÿ�ζ����Ըպ÷ֳ�5�� ���ң�ÿ�θ��Ϻ��ӵ���
�Ӷ��������ǽ������4���У�����������4�Ϳ��Եõ������ ���������x�����ӣ����ǽ������4�������ʱ
��x + 4���� ��һ�����ӵõ���x + 4�� / 5��ʣ�ࣨx + 4����4 / 5���� �ڶ������ӷ����ʣ�ࣨx + 4��(4 / 5) ^ 2�� ������
���ӷ����ʣ�ࣨx + 4��(4 / 5) ^ 3�� �������ƣ���n�����ӷ����ʣ�ࣨx + 4����4 / 5��^n Ҫ�������ʣ���Ϊ��
��������x��С���� x + 4 = 5 ^ nʱ������Ҫ�󣻴�ʱ��x = 5 ^ n - 4; �Ϻ��ӵõ�������Ϊ��x + 4��*��4 / 5��^n + n - 4
= 4 ^ n + n - 4 ���� + n����Ϊÿ��С���Ӷ�����һ�����Ϻ��ӣ� - 4�ǻ��˽��4��
*/
int main()
{
	int n;
	while (std::cin >> n) {
		if (n == 0) break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		std::cout << total << " " << left << std::endl;
	}

	system("pause");
	return 0;
}