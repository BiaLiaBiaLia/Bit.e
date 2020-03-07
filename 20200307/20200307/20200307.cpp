#include<iostream>
using namespace std;

//牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
int main() {
	int n, t = 0;
	char c;
	while (cin >> n) {
		t = 0;
		for (int i = 0; i < n; i++) {
			cin >> c;
			if (c == 'R') {
				t++;
				t %= 4;
			}
			else {
				if (t == 0) {
					t = 3;
				}
				else {
					t--;
				}
			}
		}
		if (t == 0)
			cout << 'N' << endl;
		else if (t == 1)
			cout << 'E' << endl;
		else if (t == 2)
			cout << 'S' << endl;
		else if (t == 3)
			cout << 'W' << endl;
	}

	system("pause");
	return 0;
}
