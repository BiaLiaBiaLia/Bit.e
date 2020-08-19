#include<iostream>
using namespace std;

//°ÙÇ®Âò°Ù¼¦
int main() {
	int num;
	while (cin >> num) {
		int i, j, k;

		for (i = 0; i <= 20; i++) {
			for (j = 0; j < 33; j++) {
				k = 100 - i - j;
				if ((k % 3 == 0) && (5 * i + 3 * j + k / 3 == 100))
					cout << i << ' ' << j << ' ' << k << endl;
			}
		}
	}


	system("pause");
	return 0;
}