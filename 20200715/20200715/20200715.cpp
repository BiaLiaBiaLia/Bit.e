#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string mygetstring(string &src);
int main()
{
	string src;
	string res;
	getline(cin, src);
	res = mygetstring(src);
	cout << res << endl;

	system("pause");
	return 0;
}
string mygetstring(string &src)
{
	string res;
	bool flag = false;
	if (src.size() <= 2)return src;
	for (int i = 0; i < src.size() - 2; i++)
	{
		if (src[i] == src[i + 1] && src[i + 1] == src[i + 2])
		{
			flag = true; break;
		}
	}
	if (!flag) return src;

	for (int i = 0; i < src.size() - 2; i++)
	{
		if (src[i] == src[i + 1] && src[i + 1] == src[i + 2])
		{
			src.erase(i, 3);

			mygetstring(src);
			break;
		}
	}
	return src;
}