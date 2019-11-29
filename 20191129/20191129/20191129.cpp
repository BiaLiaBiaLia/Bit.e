#include <iostream>
#include <vector>
#include <string>
using namespace std;

//洗牌
#if 0
int main()
{
	int T, n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		int num = 2 * n;
		vector<int> v(num);
		for (int i = 0; i < num; ++i) {
			cin >> v[i];  //存放未洗牌数组
		}
		while (k--) {
			vector<int> tmp(v);  //拷贝一份未洗牌数组
			for (int i = 0; i < n; ++i) {
				v[2 * i] = tmp[i];  //洗牌
				v[2 * i + 1] = tmp[i + n];
			}
		}
		for (int i = 0; i < num - 1; ++i)
			cout << v[i] << " ";
		cout << v[num - 1] << endl;
	}

	system("pause");
	return 0;
}
#endif


int main() {
	int n;
	string order;
	while (cin >> n >> order)
	{
		int num = 1, first = 1; //将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌曲的编号
		if (n <= 4) //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (num == 1 && order[i] == 'U') num = n;
				else if (num == n && order[i] == 'D') num = 1;
				else if (order[i] == 'U') num--;
				else  num++;
			}
			for (int i = 1; i <= n - 1; i++)
				cout << i << ' ';
			cout << n << endl;
			cout << num << endl;
		}
		else  //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (first == 1 && num == 1 && order[i] == 'U') { first = n - 3; num = n; } //特殊翻页1
				else if (first == n - 3 && num == n && order[i] == 'D') { first = 1; num = 1; } //特殊翻页2
				else if (first != 1 && num == first && order[i] == 'U') { first--; num--; } //一般翻页1
				else if (first != n - 3 && num == first + 3 && order[i] == 'D') { first++; num++; } //一般翻页2
				else if (order[i] == 'U') num--; //其他情况1
				else num++; //其他情况2
			}
			for (int i = first; i < first + 3; i++)
				cout << i << ' ';
			cout << first + 3 << endl;
			cout << num << endl;
		}
	}

	system("pause");
	return 0;
}