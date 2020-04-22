#include <iostream>
using namespace std;

#define BIG_NUM 1000000007
int getTime(long nNum)
{
	int i;
	i = 0;
	while (i < 100000)
	{
		if ((nNum * 4 + 3) % BIG_NUM == 0)
		{
			return i + 1;
		}
		if ((4 * (nNum * 4 + 3) + 3) % BIG_NUM == 0)
		{
			return i + 2;
		}
		if ((nNum * 8 + 7) % BIG_NUM == 0)
		{
			return i + 1;
		}
		nNum = (nNum * 8 + 7) % BIG_NUM;
		i++;
	}
	return -1;
}

int main()
{
	long nNum;
	while (cin >> nNum)
	{
		cout << getTime(nNum) << endl;
	}

	system("pause");
	return 0;
}