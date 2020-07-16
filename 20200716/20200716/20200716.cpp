#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr;
	int tmp, len = 0, sum = 0;
	char s = ' ';
	while (s != '\n')
	{
		cin >> tmp;
		arr.push_back(tmp);
		sum += tmp;
		len++;
		s = getchar();
	}
	// cout<<sum;

	int sum1 = 0;
	int sum2 = sum / 2;
	for (int i = 0; i < len; i++)
	{
		sum1 += arr[i];
		if (sum1 >= sum2)
			break;
	}
	int a = sum - sum1;
	if (sum1 == sum)
	{
		sum1 = sum - arr[len - 1];
		a = arr[len - 1];
	}
	if (a > sum1)
	{
		int t = sum1;
		sum1 = a;
		a = t;
	}
	cout << sum1 << "," << a << endl;

	system("pause");
	return 0;
}