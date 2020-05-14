#include<iostream>
using namespace std;

int main() {
	int M1[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int M2[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int year, mon, day;

	while (cin >> year >> mon >> day) {
		int res = day;
		if ((year % 100 == 0) && (year % 400 == 0)) {
			for (int i = 1; i < mon; i++) {
				res += M2[i];
			}
		}
		else if (year % 4 == 0 && year % 100 != 0) {
			for (int i = 1; i < mon; i++) {
				res += M2[i];
			}
		}
		else {
			for (int i = 1; i < mon; i++) {
				res += M1[i];
			}
		}

		cout << res << endl;
	}

	system("pause");
	return 0;
}
