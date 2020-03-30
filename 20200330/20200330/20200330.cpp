#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i != n; ++i)
	{
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> q(m, 0);
	for (int i = 0; i != m; ++i)
	{
		cin >> q[i];
	}
	vector<int> sum(n, 0);
	vector<int> res(m, 0);
	sum[0] = a[0];
	for (int i = 1; i != n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 0; i != m; ++i)
	{
		int fi = 0, la = n - 1;
		while (fi < la)
		{
			int mid = (fi + la) >> 1;
			if (sum[mid] < q[i])
			{
				fi = mid + 1;
			}
			else
			{
				la = mid;
			}
		}
		res[i] = la + 1;
	}
	for (int i = 0; i != m; ++i)
	{
		cout << res[i] << endl;
	}

	system("pause");
	return 0;
}