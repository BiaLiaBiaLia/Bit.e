#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> A, B, C;
	int x;
	char c = ' ';

	while (c != '\n') {
		cin >> x;
		A.push_back(x);
		c = getchar();
	}
	c = ' ';
	while (c != '\n') {
		cin >> x;
		B.push_back(x);
		c = getchar();
	}

	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] < B[j]) C.push_back(A[i++]);
		else C.push_back(B[j++]);
	}

	while (i < A.size()) C.push_back(A[i++]);
	while (j < B.size()) C.push_back(B[j++]);

	cout << C[0];
	for (i = 1; i < C.size(); i++) 
		cout << " " << C[i];
	cout << endl;

	system("pause");
	return 0;
}