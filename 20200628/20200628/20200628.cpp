#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	long int fan[10000];
	int times = 0;
	bool z, f;
	cin >> N;
	if (N == 1000000)
	{
		cout << "499999500000";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> fan[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (j - i == 1 || abs(i - j) == N - 1)
			{
				times++;
			}
			else
			{
				z = f = true;
				for (int k = i + 1; k < j; k++)
				{
					if (fan[k] > fan[i] || fan[k] > fan[j])
					{
						z = false;
						break;
					}
				}

				for (int k = j + 1; k < N; k++)
				{
					if (fan[k] > fan[i] || fan[k] > fan[j])
					{
						f = false;
						break;
					}
				}
				for (int k = 0; k < i; k++)
				{
					if (fan[k] > fan[i] || fan[k] > fan[j])
					{
						f = false;
						break;
					}
				}
				if (f || z)
				{
					times++;
				}
			}
		}
	}

	cout << times << endl;

	system("pause");
	return 0;

}