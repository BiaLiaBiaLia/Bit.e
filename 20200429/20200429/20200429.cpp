#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ch[26] = { 0 };

	for (int i = 0; i < 26; i++)
	{
		cin >> ch[i];
	}

	string str;
	cin >> str;
	int length = str.size();
	int sum = 0;
	int line = 1;

	for (int i = 0; i < length; i++)
	{
		if (sum + ch[str[i] - 'a' - 0] > 100)
		{
			line++;
			sum = ch[str[i] - 'a' - 0];
		}
		else
		{
			sum = sum + ch[str[i] - 'a' - 0];
		}

	}
	cout << line << " " << sum << endl;

	system("pause");
	return 0;
}