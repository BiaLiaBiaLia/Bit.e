#include <iostream>
#include <vector>
#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

//计算日期到天数转换
#if 0
int main()
{
	vector<int> v = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, m, d, sum;
	while (cin >> y>> m>> d) {
		sum = 0;
		v[2] = 28;
		if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > v[m]) {
			cout << -1 << endl;
			break;
		}
		if ((0 == y % 4 && 0 != y % 100) || 0 == y % 400) {
			v[2] = 29;
		}
		for (int i = 1; i < m; ++i) {
			sum += v[i];
		}
		sum += d;
		cout << sum << endl;
	}

	system("pause");
	return 0;
}
#endif

//幸运袋子
int n;
int num[1010];
bool cmp(int a, int b) {
	return a < b;
}
int dfs(int index, long long sum, long long mult) {
	int cnt = 0;//index为坐标 sum为和 mult为积
	for (int i = index; i < n; i++) {
		sum += num[i];
		mult *= num[i];
		if (sum > mult) {//如果和大于积说明可以将当前的数加进去，为一种幸运背包
			cnt += 1 + dfs(i + 1, sum, mult);
			//cout << i << " ";
		}
		else if (num[i] == 1) {//或者为1，后面可能又一种幸运背包
			cnt += dfs(i + 1, sum, mult);
		}
		else break;//否则行不通
		sum -= num[i];//恢复原情况
		mult /= num[i];//恢复原情况相当于一颗树返回根节点
		for (; i < n - 1 && num[i + 1] == num[i]; i++);
	}
	return cnt;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	printf("%d", dfs(0, 0, 1));
	return 0;
}