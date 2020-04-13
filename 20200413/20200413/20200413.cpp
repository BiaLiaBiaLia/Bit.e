#include <iostream>
using namespace std;

//ËØÊı¶Ô
int fun(int n);
int sum = 0;

int fun(int n)
{
	int i, f = 0;
	for (i = 2; i <= n / 2; i++)
	{
		if (n%i == 0)
			break;
	}
	if (i > n / 2)
		f = 1;
	return f;
}

int main()
{
	int n;
	int i;
	int k = 0;
	cin >> n;
	for (i = 2; i <= n / 2; i++)
	{
		k = fun(i);
		if (k == 1)
			k = fun(n - i);
		if (k == 1)
			sum++;
	}
	cout << sum << endl;

	system("pause");
	return 0;
}

