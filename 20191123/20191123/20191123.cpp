#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//��ȫ������(ȡ�ɣ�ֻΪ����)
#if 0
int main()
{
	vector<int> v(5000001, 0);
	v[6] = 1;
	v[28] = 1;
	v[496] = 1;
	v[8128] = 1;
	int n;
	while (cin >> n) {
		if (n < 6)
			cout << 0 << endl;
		else if (n >= 6 && n < 28)
			cout << 1 << endl;
		else if (n >= 28 && n < 496)
			cout << 2 << endl;
		else if (n >= 496 && n < 8128)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int count, sum;
	int n;
	while (cin >> n) {
		count = 0;
		sum = 0;
		while (n != 0) {
			for (int i = 1; i < n; ++i) {
				if (0 == n % i)
					sum += i;
			}

			if (n == sum)
				++count;
			--n;
			sum = 0;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif

//�˿��ƴ�С
/*�������⣬���벻���ܷǷ���Ҳ������ȣ���˳��������
 *��������ͼ�Ϊ��
 *	�ж��Ƹ����������Ƚ���С�ƣ��������ֻ��ը���ɱȽ�
 *	���⣺��ը���ֻҪ����ը������ըӮ*/
int main()
{
	string str, table = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER"; // str���ճ��ƣ�table��������С
	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != -1) // ��ը�������ըֱ����ըӮ
			cout << "joker JOKER" << endl;
		else
		{
			int cut = str.find('-'); //�á�-�����������Ʒֿ�
			string s1 = str.substr(0, cut);
			string s2 = str.substr(cut + 1);
			int c1 = count(s1.begin(), s1.end(), ' ') + 1; //�����һ������(�ո���+1)
			int c2 = count(s2.begin(), s2.end(), ' ') + 1; //����ڶ�������(�ո���+1)
			string f1 = s1.substr(0, s1.find(' ')); //�õ���һ���ĵ�һ���Ƽ���С��
			string f2 = s2.substr(0, s2.find(' ')); //�õ��ڶ����ĵ�һ���Ƽ���С��
			if (c1 == c2) //����������ֱ�ӱȽϴ�С(���ӡ����ӡ�˳�ӡ�������ը����֮ͬ��Ƚ���Сֵ����)
			{
				if (table.find(f1) > table.find(f2))
					cout << s1 << endl;
				else
					cout << s2 << endl;
			}
			else //�����������ȣ���ֻ��ը���������������ͱȽϣ��������ը������ʾ����
			{
				if (c1 == 4)
					cout << s1 << endl;
				else if (c2 == 4)
					cout << s2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}

	system("pause");
	return 0;
}