#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> res;
		while (n--)
		{
			int temp;
			cin >> temp;
			res.push_back(temp);
		}
		sort(res.begin(),res.end());

		int count = 0;
		int sum = res[0];
		for (int i = 1; i <= res.size(); i++)
		{
			if (sum <= m)
			{
				sum += res[i];
				count++;
			}
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}