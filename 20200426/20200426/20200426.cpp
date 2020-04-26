#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, k, d;
	long long int res = 0;
	cin >> n;
	vector<int> nums;
	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}

	cin >> k >> d;
	long long int fm[11][50], fn[11][50];

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			fm[i][j] = 0;
			fn[i][j] = 0;
		}
	}

	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i <= k; i++)
		{
			if (i == 1)
			{
				fm[i][j] = nums[j];
				fn[i][j] = nums[j];
				continue;
			}
			for (int m = 1; m <= d; m++)
			{
				if (j - m >= 0 && j - m < n)
				{
					fm[i][j] = max(fm[i][j], max(fm[i - 1][j - m] * nums[j], fn[i - 1][j - m] * nums[j]));
					fn[i][j] = min(fn[i][j], min(fm[i - 1][j - m] * nums[j], fn[i - 1][j - m] * nums[j]));
				}
			}
		}
		res = max(res, fm[k][j]);
	}
	cout << res;

	system("pause");
	return 0;
}