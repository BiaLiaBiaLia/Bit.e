#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	vector<vector<int>>num(n, vector<int>(n)), dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int t = 0;
		for (int j = 0; j < n; j++, t += 2)
			num[i][j] = s[t] - '0';
	}
	dp[0][0] = num[0][0];
	for (int i = 1; i < n; i++)
		dp[i][0] = num[i][0] + dp[i - 1][0];
	for (int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1] + num[0][j];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + num[i][j];
	cout << dp[n - 1][n - 1] << endl;

	system("pause");
	return 0;
}