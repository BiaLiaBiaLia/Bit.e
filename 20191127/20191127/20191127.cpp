#include <iostream>
#include <string>
using namespace std;

//��ˮƿ
//������ƿ�ӿ��Ի�һƿ����ˮ,��������ʱ���Ƚ�һƿ
#if 0
int main() 
{
	int n;	
	while (cin >> n) {

		int news = 0, surplus = 0, count = 0;

		while (n >= 3) {
			count = n / 3;  //�µ�ƿ����==���Ժȵ���ˮƿ��
			news += count;  //һ�����Ժȵ���ˮƿ��
			surplus = n % 3;  //û�л�������ˮƿ����
			n = count + surplus;
		}
		if (2 == n)
			cout << news + 1 << endl;
		else
			cout << news << endl;
	}

	system("pause");
	return 0;
}
#endif

//���������ַ���a,b�е�������Ӵ�
//����ж����������ڴ��������ȳ��ֵ��Ǹ�
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())
			swap(a, b);
		string str_m;//�洢������Ӵ�
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (int(b.find(temp)) < 0)
					break;
				else if (str_m.size() < temp.size())
					str_m = temp;
			}
		}
		cout << str_m << endl;
	}

	system("pause");
	return 0;
}