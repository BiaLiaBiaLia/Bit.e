#include<iostream>
using namespace std;


int Max(int a, int b)
{
	return (a > b) ? a : b;
}


int main()
{
	int num;
	while (cin >> num)
	{
		int a[65535];
		int dp[65535];
		for (int i = 0; i < num; i++)
		{
			cin >> a[i];
		}

		dp[0] = 1;
		int max = 0;
		for (int i = 1; i < num; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (a[i] > a[j])
				{
					dp[i] = Max(dp[i], dp[j] + 1);
				}

			}
			if (max < dp[i])
				max = dp[i];
		}
		cout << max << endl;
	}

	system("pause");
	return 0;
}