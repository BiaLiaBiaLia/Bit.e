#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
//ͳ�ƻ�����
int main()
{
	string A, B, ret;
	int count = 0;
	cin >> A >> B;

	for (int i = 0; i <= A.size(); ++i)
	{
		ret = A;
		ret.insert(i, B);

		string str = ret;
		reverse(str.begin(), str.end());
		if (ret == str)
			++count;
	}

	cout << count << endl;

	system("pause");
	return 0;
}
#endif

//���������У�ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�
//ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,
//ţţ��֪�������ٿ��԰���������Ϊ��������������.
//����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)
//�ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡�
int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	int i = 0;
	for (i=0; i < n; ++i)
	{
		cin >> a[i];
	}

	i = 0;
	int count = 0;
	while (i < n)
	{
		//�ǵݼ�������
		if (a[i] < a[i + 1])
		{
			while (i < n&&a[i] <= a[i + 1])
			{
				++i;
			}
			++i;
			++count;
		}
		else if (a[i] == a[i + 1])
		{
			++i;
		}
		else//�ǵ���������
		{
			while (i < n&&a[i] >= a[i + 1])
			{
				++i;
			}
			++i;
			++count;
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}