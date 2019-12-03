#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//年终奖问题(动态规划)
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		int n = board[0].size();
		vector<vector<int> > price(n);
		for (int i = 0; i < n; ++i)
			price[i].resize(n);
		price[0][0] = board[0][0];
		for (int i = 1; i < n; i++) {
			price[0][i] = price[0][i - 1] + board[0][i];
			price[i][0] = price[i - 1][0] + board[i][0];

		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				price[i][j] = max(price[i - 1][j], price[i][j - 1]) + board[i][j];
			}
		}
		return price[n - 1][n - 1];
	}
};

int main()
{
	Bonus b;
	
	system("pause");
	return 0;
}