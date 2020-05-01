#include <iostream> 
using namespace std;

int main()
{
	int x;
	cin >> x;
	int num = 0;
	for (int i = 0; i <= x; i++)
	{
		int flag = 0;
		int n = i;
		while (n)
		{
			int t = n % 10;
			if (t == 3 || t == 4 || t == 7)
			{
				break;
			}
			else if (t == 2 || t == 5 || t == 6 || t == 9)
			{
				flag = 1;
			}
			n = n / 10;
		}
		if (flag == 1 && n == 0)
		{
			num++;
		}
	}
	cout << num << endl;

	system("pause");
	return 0;
}