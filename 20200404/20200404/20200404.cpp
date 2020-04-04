#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<long long> a = { 0,0,1 };
	vector<long long> b = { 0,1,2 };

	for (int i = 3; i < 21; ++i) {
		a.push_back(0);
		a[i] = (i - 1)*(a[i - 1] + a[i - 2]);  //·Ö×Ó

		b.push_back(0);
		b[i] = i * b[i - 1];  //·ÖÄ¸
	}

	while (cin >> n) {
		printf("%.2f%c\n", 1.0*a[n] / b[n] * 100, '%');
	}

	system("pause");
	return 0;
}