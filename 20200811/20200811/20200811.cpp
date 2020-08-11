#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == NULL) return false;
		int len = strlen(string);
		int i = 0, dot = 0, nume = 0, num = 0;
		if (string[0] == '+' || string[0] == '-') i++;
		while (i < len)
		{
			if ((string[i] >= '0' && string[i] <= '9'))
			{
				i++;
				num = 1;
			}
			else if (string[i] == '.')
			{
				if (nume > 0 || dot > 0) return false;
				i++;
				dot++;
			}
			else if (string[i] == 'e' || string[i] == 'E') {
				if (num == 0 || nume > 0) return false;
				i++;
				nume++;
				if (string[i] == '\0') { return false; }
				if (string[i] == '+' || string[i] == '-') { i++; }
			}
			else { return false; }
		}
		return true;
	}

};

int main()
{
	Solution s;
	char str[] = { '+100','5e2','-123'};
	cout << s.isNumeric(str) << endl;

	system("pause");
	return 0;
}