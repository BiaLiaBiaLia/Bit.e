#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int a[1000001];
void getNumber(const int a[], int n, int &num1, int &num2)
{
	int num = 0;
	for (int i = 1; i <= n; ++i)
		num = num ^ a[i];

	num = num & (-num);
	num1 = num2 = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (num & a[i])
			num1 ^= a[i];
		else
			num2 ^= a[i];
	}
}
int main(void)
{
	int n = 0;
	while (~scanf("%d", &a[n + 1]))
		++n;

	int p, q;
	getNumber(a, n, p, q);
	if (p > q)
		swap(p, q);
	printf("%d %d\n", p, q);

	system("pause");
	return 0;
}