#include <iostream>
using namespace std;

class Solution
{
public:
	void replaceSpace(char* str, int length) //"We Are Happy"
	{
		int count = 0;
		int i = length-1;
		while (i >=0)
		{
			if (str[i] == ' ')
			{
				for (int j = length; j >= i; --j)//�Ӻ���ǰ����������[�ո�,'\0']�Ĳ������ƽ��2����λ
				{
					str[j + 2] = str[j];
				}

				str[i] = '%';
				str[i + 1] = '2';
				str[i + 2] = '0';

				length += 2;
			}
			i--;
		}
	}

	void PrintStr(char* str)
	{
		while (*str != '\0')
		{
			cout << *str;
			str++;
		}
	}
};

int main()
{
	Solution s;
	char str[] = "We Are Happy";
	int length = strlen(str);

	s.replaceSpace(str, length);
	s.PrintStr(str);

	system("pause");
	return 0;
}