#include<iostream>
using namespace std;

//ţţȥ�Ġ���ʦ�Ҳ��Σ����ŵ�ʱ�����򱱷���������������·�ˡ���Ȼ��������һ�ŵ�ͼ����������Ҫ֪���Լ������ĸ���������������
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
