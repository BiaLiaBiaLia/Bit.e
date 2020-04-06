#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int partition(vector<int> &vec, int low, int high) {
	int temp = vec[low];
	while (low < high) {
		while (low < high && vec[high] >= temp) {
			high--;
		}
		vec[low] = vec[high];
		while (low < high && vec[low] <= temp) {
			low++;
		}
		vec[high] = vec[low];
	}
	vec[low] = temp;
	return low;
}

void quicksort(vector<int> &vec, int low, int high) {
	if (low < high) {
		int mid = partition(vec, low, high);
		quicksort(vec, low, mid - 1);
		quicksort(vec, mid + 1, high);
	}
}

int main() {
	int len = 20;
	vector<int> vec;
	for (int i = 0; i < len; i++) {
		vec.push_back(rand());
	}
	quicksort(vec, 0, len - 1);
	for (int i = 0; i < len; i++) {
		cout << vec[i] << endl;
	}

	system("pause");
	return 0;
}