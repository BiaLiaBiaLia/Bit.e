#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= '0' && str[i] <= '9' && (i == 0 || str[i - 1] < '0' || str[i - 1] > '9'))
			{
				str = str.substr(0, i) + '*' + str.substr(i);
				i++;
			}
			if (str[i] >= '0' && str[i] <= '9' && (i == str.size() || str[i + 1] < '0' || str[i + 1] > '9'))
			{
				str = str.substr(0, i + 1) + '*' + str.substr(i + 1);
				i++;
			}

		}
		cout << str << endl;
	}

	system("pause");
	return 0;
}