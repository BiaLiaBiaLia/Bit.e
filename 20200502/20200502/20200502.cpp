#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	char c;
	int N = 0, T = 0, type = 0, num = 0;
	cin >> N >> T;

	for (int i = 0; i < N; ++i)
	{
		cin >> c;
		s.push_back(c);
	}

	for (int i = 0; i < T; ++i)
	{
		cin >> type >> num;
		if (type == 1)
		{
			s = s + s.substr(0, N - num);
			s.erase(0, N - num);
		}
		else
		{
			cout << s[num] << endl;
		}
	}

	system("pause");
	return 0;
}