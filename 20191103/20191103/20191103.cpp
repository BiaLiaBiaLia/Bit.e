#include <iostream>
#include <vector>
using namespace std;

#if 0
//�����г��ִ�������һ�������
class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int max = numbers[0];
		for (int i = 1; i < numbers.size(); ++i)
		{
			if (numbers[i] > max)
				max = numbers[i];
		}

		vector<int> arr(max + 1);
		for (int i = 0; i < numbers.size(); i++)
		{
			arr[numbers[i]]++;
		}

		int _max = arr[0];
		int count = 0;
		for (int i = 1; i <= max; ++i)
		{
			if (arr[i] > _max)
			{
				_max = arr[i];
				count = i;
			}
		}
		if (_max > numbers.size() / 2)
			return count;
		else
			return 0;
	}
};

int main()
{
	Solution s;
	vector<int> x = { 1 };
	cout << s.MoreThanHalfNum_Solution(x) << endl;

	system("pause");
	return 0;
}
#endif

//������ֻ����һ�ε�����
class Solution
{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		if (data.size() < 2)
			return;

		int x = 0;
		for (int e : data)//������ȫ�����,�õ�������ͬ�������x
			x ^= e;

		int i;//��¼x�������е�һ��1��λ��(Ҳ��������������ͬ��һ������,�ɽ��������黮��Ϊ��¼λ��Ϊ1��,��Ϊ0��)
		for (i = 0; i < data.size(); ++i)
		{
			if ((x&(1 << i)) != 0)
			{
				break;
			}
		}

		int _num1 = 0;
		int _num2 = 0;
		for (int e : data)
		{
			if ((e&(1 << i)) == 0)//��¼λ��Ϊ0����ȫ�����ɵõ�����һ����
				_num1 ^= e;
			else                  //��һ����
				_num2 ^= e;
		}

		*num1 = _num1;
		*num2 = _num2;
	}
};

void Test()
{
	Solution s;
	vector<int> v = { 1,1,2,2,3,4,4,5,5,6,7,7 };
	int* num1=&v[0];
	int* num2=&v[1];

	s.FindNumsAppearOnce(v, num1, num2);
	cout << *num1 << " " << *num2 << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}