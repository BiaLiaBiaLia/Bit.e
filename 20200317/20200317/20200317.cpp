#include<iostream>
using namespace std;

//Ա�����ڼ�¼
int main()
{
	int n;
	cin >> n;
	int cnt = 1;//ȫ��
	cnt += n;//ȱ��һ��
	int a = 1, b = 1;
	for (int i = n; i > 0; i--) {
		if (i > n - 2)
			a *= i;
		if (i <= 2)
			a /= i;
	}
	cout << cnt + a << endl;

	system("pause");
	return 0;
}