#include <iostream>
#include <string>
using namespace std;

//ͳ��ÿ������������(���࿼��쳲�����������)
#if 0
int getTotalCount(int n) {
	if (n < 3)
		return 1;
	else
		return getTotalCount(n - 1) + getTotalCount(n - 2);
}

int main()
{
	//f(n)����ÿ������=f(n-1)�ϸ�����������+f(n-2)��������������������
	int n;
	while (cin >> n) {
		cout << getTotalCount(n) << endl;
	}

	system("pause");
	return 0;
}
#endif

//�ַ���ͨ���
bool match(string str1, string str2) {
	int i = 0;
	int j = 0;
	bool flag = false;
	while (str1[i] != '\0' || str2[j] != '\0') {
		if (str1[i] == '*') {       
			++i;
			flag = true;
		}
		else if (str1[i] == str2[j] || str1[i] == '?') {
			++i;
			++j;
		}
		else if (flag == true) {
			while (str1[i] != str2[j]) {
				++j;
			}
			flag = false;
		}
		else {
			cout << "false" << endl;
			break;
		}
		if (str1[i] == '\0' && str2[j] == '\0')
			cout << "true" << endl;
	}
	return 0;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2) {
		match(str1, str2);
	}
	return 0;
}
