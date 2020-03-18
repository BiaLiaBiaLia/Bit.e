#include <iostream>
#include<vector>
using namespace std;

//´ó°Í³µ
int main() {
	int nums, orders;
	cin >> nums >> orders;
	vector<vector<int>> res;
	int data;
	for (int i = 0; i < nums; i = i + orders)
	{
		vector<int> cur;
		for (int j = i; j < i + orders && j < nums; j++)
		{
			cin >> data;
			cur.push_back(data);
		}
		res.push_back(cur);
	}
	int size = res.size();
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " " << endl;
		}
	}

	system("pause");
	return 0;
}