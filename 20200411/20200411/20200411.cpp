#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(vector<int> v, int n) {		
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	BubbleSort(v, n);

	system("pause");
	return 0;
}