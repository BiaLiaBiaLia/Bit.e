#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int a, b;
		int* arr = new int[n];
		int nCt = 0;

		while (n)
		{
			a = n / 2;
			b = n % 2;
			if (!b)
			{
				--a;
				arr[nCt] = 3;
				++nCt;
			}
			else {
				arr[nCt] = 2;
				++nCt;
			}
			n = a;
		}
		for (int i = nCt - 1; i >= 0; i--)
			cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}