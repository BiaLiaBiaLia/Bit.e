#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#if 0
int main()
{
	//ʮ����ת��������(2<=N<=16)
	int M, N;
	cin >> M >> N;
	string ret;
	string str{ "0123456789ABCDEF" };

	int flag = 1;//Ĭ���������Ϊ����
	if (M < 0)
	{
		flag = 0;
		M = -M;//����Ϊ����
	}

	while (M)
	{
		ret += str[M%N];
		M /= N;
	}

	if (flag == 0)
	{
		ret += '-';
	}

	reverse(ret.begin(), ret.end());

	cout << ret << endl;

	system("pause");
	return 0;
}
#endif

/*���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou����
��ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��*/

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	// ʹ�ù�ϣӳ��˼����ͳ��str2�ַ����ֵĴ���
	int hashtable[256] = { 0 };
	for (int i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���
// str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i)
// ��Ϊ�߱�������erase�����׳���
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