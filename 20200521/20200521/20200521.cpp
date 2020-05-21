#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//计算最少出列多少位同学，使得剩下的同学排成合唱队形
//说明：
//N位同学站成一排，音乐老师要请其中的(N - K)位同学出列，使得剩下的K位同学排成合唱队形。
//合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，
//则他们的身高满足存在i（1 <= i <= K）使得T1 < T2<......<Ti - 1 < Ti > Ti + 1>......>TK
//你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

void deal(vector<int>&stu, vector<int>&res) {
	vector<int> best(stu.size(), 9999);
	best[0] = stu[0];
	res.push_back(1);
	for (int i = 1; i < stu.size(); i++) {
		int pos = lower_bound(best.begin(), best.end(), stu[i]) - best.begin();
		res.push_back(pos + 1);
		best[pos] = stu[i];
	}
}

int main() {
	int num = 0;
	while (cin >> num) {
		vector<int> stu;
		vector<int> asc;
		vector<int> desc;
		while (num--) {
			int tmp = 0;
			cin >> tmp;
			stu.push_back(tmp);
		}
		deal(stu, asc);
		reverse(stu.begin(), stu.end());
		deal(stu, desc);
		reverse(desc.begin(), desc.end());
		int max_ = 0;
		for (int i = 0; i < stu.size(); i++)
			max_ = max(asc[i] + desc[i] - 1, max_);
		cout << stu.size() - max_ << endl;
	}

	system("pause");
	return 0;
}