#include <iostream>
#include <vector>
#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

//�������ڵ�����ת��
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

//���˴���
int n;
int num[1010];
bool cmp(int a, int b) {
	return a < b;
}
int dfs(int index, long long sum, long long mult) {
	int cnt = 0;//indexΪ���� sumΪ�� multΪ��
	for (int i = index; i < n; i++) {
		sum += num[i];
		mult *= num[i];
		if (sum > mult) {//����ʹ��ڻ�˵�����Խ���ǰ�����ӽ�ȥ��Ϊһ�����˱���
			cnt += 1 + dfs(i + 1, sum, mult);
			//cout << i << " ";
		}
		else if (num[i] == 1) {//����Ϊ1�����������һ�����˱���
			cnt += dfs(i + 1, sum, mult);
		}
		else break;//�����в�ͨ
		sum -= num[i];//�ָ�ԭ���
		mult /= num[i];//�ָ�ԭ����൱��һ�������ظ��ڵ�
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