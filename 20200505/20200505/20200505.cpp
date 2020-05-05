#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, x = 0;
	cin >> n;
	string s = "";
	while (n)
	{
		if (n % 2 == 0)
		{
			n = (n - 2) / 2;
			s += '3';
		}
		else
		{
			n = (n - 1) / 2;
			s += '2';
		}
	}

	reverse(s.begin(), s.end());
	cout << s << endl;

	system("pause");
	return 0;
}