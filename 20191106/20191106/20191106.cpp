#include <iostream>
#include <vector>
using namespace std;

#if 0
//쳲���������
class Solution
{
public:
	int Fibonacci(int n)
	{
		if (n < 2)
			return n;

		int x = 0, y = 1, z;
		for (int i = 2; i <= n; ++i)
		{
			z = x + y;
			x = y;
			y = z;
		}
		return z;
	}
};

int main()
{
	Solution s;
	cout << s.Fibonacci(10) << endl;

	system("pause");
	return 0;
}
#endif

/*ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
���� :
һ������������Ա��ˮƽֵ�ֱ���3, 3, 3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���3, 2, 3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���1, 5, 2.��ô�����ˮƽֵ��2
Ϊ���ñ������п���, ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
��������ʾ :
���ţţ��6����Ա���ֵ���������
�������Ϊ :
team1: {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
	���������Ϊ :
	team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
	û�б��ܺ�Ϊ10����ķ���, �������10.

	�������� :
	����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)

	�ڶ��а���3*n������a_i(1 �� a_i �� 10 ^ 9), ��ʾÿ������ѡ�ֵ�ˮƽֵ.

	������� :
	���һ��������ʾ���ж����ˮƽֵ�ܺ����ֵ.

	�������� :
	2
	5 2 8 5 1 5

	������� :
	10
*/
class Solution
{
public:
	int Test(int n,vector<int> a_i)
	{
		if (n <= 0 || 0 == a_i.size())
			return 0;

		for (int i = 0; i < a_i.size(); ++i)
		{
			for (int j = 0; j < a_i.size() - i - 1; ++j)
			{
				if (a_i[j + 1] < a_i[j])
				{
					int temp = a_i[j];
					a_i[j] = a_i[j + 1];
					a_i[j + 1] = temp;
				}
			}
		}
		int z = 0;
		for (int i = 0; i < n; ++i)
		{
			z += a_i[i + n];
		}

		return z;
	}
};

int main()
{
	Solution s;
	int n;
	cin >> n;

	vector<int> g;
	int* arr = new int[3 * n];

	for (int i = 0; i < 3 * n; ++i)
	{
		cin >> arr[i];
		g.push_back(arr[i]);
	}

	cout << s.Test(n, g) << endl;

	system("pause");
	return 0;
}