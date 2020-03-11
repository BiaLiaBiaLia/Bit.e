#include <iostream>
#include <istream>
#include <vector>

using namespace std;

int n, m, cnt = 0;

void dfs(int sum, int p) {

	if (sum == m && p == n + 1) {
		cnt++;
		return;
	}
	int t = 0;
	for (int i = p; i <= n; i++, t *= 10) {
		t += i;
		dfs(sum + t, i + 1);
		if (p != 1) {
			dfs(sum - t, i + 1);
		}
	}
}

int main() {

	cin >> n >> m;

	dfs(0, 1);
	cout << cnt << endl;

	system("pause");
	return 0;
}
