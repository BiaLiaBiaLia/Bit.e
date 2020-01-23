#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//��ˮƿ
//����ƿ�ǻ�һƿ�µ�
#if 0
int calculateNum(int num)
{
	//�ܶһ���
	int sum = 0;
	while (num > 1)
	{
		//ÿ��ƿ��һƿ
		int result = num / 3;
		//ʣ�಻����ƿ���ȱ���
		int reminder = num % 3;
		sum = sum + result;
		//��һ�ο��Զһ��Ŀ�ƿ
		num = result + reminder;
		if (num == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}

int main() {
	int number;
	while (cin >> number)
	{
		cout << calculateNum(number) << endl;
	}

	system("pause");
	return 0;
}
#endif

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//����̵��ַ�����Ϊs1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				//����и����Ĺ����Ӵ������³���
				if (MCS[i][j] > max)
				{
					max = MCS[i][j];
						//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max
						start = i - max;
				}
			}
		cout << str1.substr(start, max) << endl;
	}

	system("pause");
	return 0;
}