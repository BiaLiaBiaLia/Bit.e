#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	char str[100][100];
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}
	int changdu = 1;
	for (int j = 0; j < n - 1; ++j) {
		if (strlen(str[j]) > strlen(str[j + 1])) {
			changdu = 0;
			break;
		}
	}

	int lex = 1;
	for (int k = 0; k < n - 1; ++k) {
		if (strcmp(str[k], str[k + 1]) > 0) {
			lex = 0;
			break;
		}
	}

	if (changdu == 1 && lex == 0) {
		cout << "lengths" << endl;
	}

	if (changdu == 0 && lex == 1) {
		cout << "lexicographically" << endl;
	}

	if (changdu == 1 && lex == 1) {
		cout << "both" << endl;
	}

	if (changdu == 0 && lex == 0) {
		cout << "none" << endl;
	}

	system("pause");
	return 0;
}