#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		vector<vector<int>> v(n, vector<int>(n));
		int num = 1;

		for (int i = 0; i < n; ++i)
		{
			int m = i;
			for (int j = 0; j <= i; ++j)
			{
				v[m--][j] = num++;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - i - 1; ++j)
			{
				if (v[i][j] != 0)
					cout << v[i][j] << " ";
			}
			cout << v[i][n - i - 1] << endl;
		}

		v.clear();
	}

	system("pause");
	return 0;
}