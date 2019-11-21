#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。
//现在有两个结点 a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
//给定两个int a, b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先
#if 0
class LCA {//满二叉树有个规律，父节点编号=子节点编号/2
public:
	int getLCA(int a, int b) {
		if (a == b)//可能为同一节点
			return a;
		while (a != b) {
			if (a > b) {
				a /= 2;
			}
			else
				b /= 2;
		}
		return a;
	}
};
#endif

//跳石板
//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
//这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的石板,小易单次只能往前跳K的一个约数(不含1和K)步，
//即跳到K + X(X为K的一个非1和本身的约数)的位置。
//小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达

int main() {//数组的下标为第i个石板，数组内存放的是最少需要多少步能到达(最少步数)
	int N, M;
	while (cin >> N >> M) {
		vector<int> v(M + 1, INT_MAX);//定义数组v，存放M+1个数据，初始化为INT_MAX，也可为其他数
		v[N] = 0;//起始位置为v[N],
		for (int i = N; i <= M; i++) {
			if (v[i] == INT_MAX) {
				continue;
			}
			for (int j = 2; (j*j) <= i; j++) {
				if (i%j == 0) {
					if (i + j <= M) {
						v[i + j] = min(v[i] + 1, v[i + j]);//比较存入更少的步数
					}
					if (i + (i / j) <= M) {
						v[i + (i / j)] = min(v[i] + 1, v[i + (i / j)]);
					}
				}
			}
		}
		if (v[M] == INT_MAX) {
			v[M] = -1;
		}
		cout << v[M] << endl;
	}

	system("pause");
	return 0;
}