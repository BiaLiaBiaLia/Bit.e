#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#if 0
int main()
{
	//����N��ȡֵ��Χ��2~16
	string ret;
	string table("0123456789ABCDEF");

	int M;
	int N;
	cin >> M >> N;

	int flag = 1;//Ĭ��������
	if (M < 0)//�����Ǹ���
	{
		flag = 0;
		M = -M;
	}

	while (M)
	{
		ret += table[M%N];
		M /= N;
	}

	if (flag == 0)//�Ǹ���
	{
		ret += '-';
	}
	//�÷�תһ���ַ���(֮ǰ�ǴӺ�ǰ���Ŵ��)
	reverse(ret.begin(), ret.end());
	cout << ret << endl;

	system("pause");
	return 0;
}
#endif

int main()
{
	string str1, str2;

	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	for (int i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	string ret;
	for (int i = 0; i < str1.size(); ++i)
	{
		if (0 == hashtable[str1[i]])
		{
			ret += str1[i];
		}
	}

	cout << ret << endl;

	system("pause");
	return 0;
}