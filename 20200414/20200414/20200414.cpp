#include <iostream>
#include <string>
#include <set>
using namespace std;

//µç»°ºÅÂë
int main()
{
	string str;
	int n;
	while (cin >> n)
	{
		string num = "22233344455566677778889999";
		set<string> data;
		int count;
		for (int i = 0; i < n; ++i)
		{
			string res;
			cin >> str;
			count = 0;
			for (int j = 0; j < str.size(); ++j)
			{
				if (str[j] >= 'A' && str[j] <= 'Z')
				{
					res += num[str[j] - 'A'];
					count++;
					if (count == 3)
						res += '-';
				}
				else if (str[j] >= '0' && str[j] <= '9')
				{
					res += str[j];
					count++;
					if (count == 3)
						res += '-';
				}
			}
			data.insert(res);
		}
		for (auto e : data)
			cout << e << endl;
		cout << endl;
	}

	system("pause");
	return 0;
}