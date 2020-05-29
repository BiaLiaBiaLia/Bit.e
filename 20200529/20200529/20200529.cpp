#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int m[10] = { 0 };//砝码的重量
		int x[10] = { 0 };//相应砝码的数量
		for (int i = 0; i < n; i++)
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> x[i];
		int v[120000] = { 0 };
		int max = 0;
		for (int i = 0; i < n; i++)
			max += m[i] * x[i];

		for (int i = 0; i < n; i++)//对n种不同重量的砝码进行循环
		{
			for (int k = max; k >= 0; k--)//将0~max中重量，进行循环
			{
				for (int j = 1; j <= x[i]; j++)//第i中砝码有x[i]个，1~x[i]循环
				{
					if (k == 0 || (v[k] == 1 && v[k + j * m[i]] != 1))//如果某一重量存在，（小于总重）那么加上又一个砝码的质量必定存在
						v[k + j * m[i]] = 1;
				}
			}
		}
		int cnt = 1;
		for (int i = 1; i <= max; i++)
			if (v[i] == 1)
				cnt++;
		cout << cnt << endl;
	}

	system("pause");
	return 0;
}