#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//��Ѽ��������
int main() {
	string s;
	cin >> s;
	int left = 0, right = 0, cnt = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'C')
			left += i - cnt++;
	cnt = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'D')
			right += i - cnt++;
	cout << min(left, right) << endl;

	system("pause");
	return 0;
}