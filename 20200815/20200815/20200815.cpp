#include <iostream>
using namespace std;

int NumOfSeven(int num)
{
	int n = 0;
	int sum = 0;
	if (num < 7)
	{
		return sum;
	}
	else
	{
		for (int i = 7; i <= num; i++)
		{
			if (!(i % 7) || i % 10 == 7 || (i % 100) / 10 == 7 || (i % 1000) / 100 == 7 || (i % 10000) / 1000 == 7)
			{
				sum = sum + 1;
			}
		}
		return sum;
	}
}

int main()
{
	int number = 0;
	while (cin >> number)
	{
		cout << NumOfSeven(number) << endl;
	}

	system("pause");
	return 0;
}
