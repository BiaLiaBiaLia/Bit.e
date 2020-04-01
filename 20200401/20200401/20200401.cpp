#include <iostream>
using namespace std;

template <class T>
inline void scan_d(T &ret)
{
	char c;
	ret = 0;
	while ((c = getchar()) < '0' || c > '9');
	while (c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0'), c = getchar();
	}
}

int main()
{
	int n, k;
	cin >> n >>k;
	int interest[100001] = { 0 };
	int wake[100001] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin>>interest[i];
	}
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>wake[i];
		if (wake[i])
			sum += interest[i];
	}

	int start_i = 0;
	int sleep_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (wake[i] == 0)
		{
			start_i = i;
			for (int j = i; j < i + k && j < n; j++)
			{
				if (wake[j] == 0)
					sleep_sum += interest[j];
			}
			break;
		}
	}

	max = sleep_sum;

	for (int i = start_i; i < n - k; i++)
	{
		if (wake[i] == 0 && wake[i + k] == 0)
		{
			sleep_sum = sleep_sum - interest[i] + interest[i + k];
		}
		else if (wake[i] == 1 && wake[i + k] == 0)
		{
			sleep_sum += interest[i + k];
		}
		else if (wake[i] == 0 && wake[i + k] == 1)
		{
			sleep_sum -= interest[i];
		}

		if (sleep_sum > max)
			max = sleep_sum;
	}
	sum += max;
    cout << sum << endl;
	
	system("pause");
	return 0;
}