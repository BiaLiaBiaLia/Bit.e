#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string t;
		cin >> t;
		string hour(t.begin(), t.begin() + 2);
		int hours = atoi(hour.c_str());
		if (hours > 23) {
			t[0] = '0';
		}
		string m_s(t.begin() + 3, t.begin() + 5);
		int m = atoi(m_s.c_str());
		if (m > 59) {
			t[3] = '0';
		}
		string s_s(t.begin() + 6, t.end());
		int second = atoi(s_s.c_str());
		if (second > 59) {
			t[6] = '0';
		}
		cout << t << endl;
	}

	system("pause");
	return 0;
}