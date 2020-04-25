#include<iostream> 
#include<string> 
using namespace std;

int main()
{
	string a;
	int len, flag = 0, count, min;
	while (getline(cin, a))
	{
		len = a.length();
		min = len;
		for (int i = 0; i < len; i++)
			a.push_back(a[i]);
		for (int i = 0; i < len + 5; i++)
		{
			int j = i;
			flag = 0;
			count = 0;
			while ((j < len + len) && flag != 0x1F)
			{
				if (flag == 0)
					count = 0;
				if (a[j] >= 'A'&&a[j] <= 'E')
				{
					flag |= 1 << (a[j] - 'A');
				}
				j++;
				count++;
			}
			if ((min > count) && (flag == 0x1F))
				min = count;
		}
		cout << len - min << endl;
	}

	system("pause");
	return 0;
}