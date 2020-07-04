#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if (n == 0)
		cout << 0 << endl;
	else
	{
		vector<long long>arr;
		arr.push_back(0);
		arr.push_back(1);
		long long num = 0, flag = 0, chaZhi;
		long long min = n - 1;
		while (1)
		{
			num = arr[0] + arr[1];
			chaZhi = abs(n - num);
			if (chaZhi < min)
				min = chaZhi;
			if (num > n)
			{
				if (num - n >= chaZhi)
					cout << min << endl;
				else
					cout << num - chaZhi << endl;
				break;
			}
			arr.push_back(num);
			arr.erase(arr.begin());
		}
	}

	system("pause");
	return 0;
}