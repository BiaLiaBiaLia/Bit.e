#include<iostream>
#include<string>
using namespace std;

int main() {
	char a[105];
	char str[105];
	while (cin >> a) {
		cin >> str;
		int len1 = strlen(a);
		int len2 = strlen(str);
		int k = 0, flag = 0;
		int s = 0;
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (a[i] == str[j]) {
					s++;
					if (s == len1) {
						cout << "true" << endl;
						flag = 1;
					}
					break;
				}
			}
		}
		if (flag == 0) {
			cout << "false" << endl;
		}
	}

	system("pause");
	return 0;
}