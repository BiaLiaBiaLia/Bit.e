#include <iostream>
#include <queue>
using namespace std;

int main() {
	int x, y;
	char c;
	int cnt = 0;
	bool flag = false;
	cin >> x >> c >> y;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int tmp = q.front();
			q.pop();
			if (tmp == y) {
				flag = true;
				break;
			}
			else {
				q.push(tmp + 1);
				q.push(tmp - 1);
				q.push(tmp * 2);
			}
		}
		if (flag)
			break;
		cnt++;
	}
	cout << cnt << endl;

	system("pause");
	return 0;
}