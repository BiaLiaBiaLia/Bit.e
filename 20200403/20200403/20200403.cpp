#include <iostream>
#define MAX 83
using namespace std;

//��ʽ�㷨
//쳲���������ǰn���=��(n+2)��ֵ-1
int main()
{
	int form, to;
	long long a[MAX] = { 1,1 }, sum = 0;
	while (cin >> form >> to) {
		for (int i = 2; i < (to + 2); ++i) {
			a[i] = a[i - 1] + a[i - 2];
		}
		sum = a[to + 1] - a[form];
		cout << sum << endl;
	}

	system("pause");
	return 0;
}