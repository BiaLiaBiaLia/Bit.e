#include <iostream>
#include <string>
using namespace std;

//¼ô»¨²¼Ìõ
#if 0
int main()
{
	string s, t;
	while (cin >> s >> t) {
		int count = 0;
		for (int i = 0; i < s.size(); ++i) {
			int j = 0, k = i;
			while (s[k] == t[j] && k < s.size()) {
				++j;
				++k;
			}
			if (j == t.size()) {
				++count;
				i = k - 1;
			}
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif

int main()
{
	string s, t;
	while (cin >> s >> t) {
		int count = 0;
		while (s.find(t) != string::npos)
		{
			++count;
			s.erase(s.find(t), t.size());
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}