#include <iostream>
using namespace std;

class Solution
{
public:
	void replaceSpace(char* str, int length)
	{
		int count = 0;
		int ol = 0;     //oldlength
		for (ol = 0; str[ol] != '\0'; ++ol)
		{
			if (str[ol] == ' ')
				count++;
		}
		int nl = ol + 2 * count;     //newlength

		if (nl > length)
			return;

		str[nl] = '\0';

		int p1 = ol - 1;
		int p2 = nl - 1;

		while (p1 >= 0)
		{
			if (str[p1] == ' ')
			{
				str[p2--] = '0';
				str[p2--] = '2';
				str[p2--] = '%';
			}
			else
				str[p2--] = str[p1];
			p1--;
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

	s.replaceSpace(str, 20);
	s.PrintStr(str);

	system("pause");
	return 0;
}