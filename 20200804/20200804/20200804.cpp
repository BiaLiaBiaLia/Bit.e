#include <iostream>
using namespace std;

//����һ���Ǹ�����N������ö����������N!�Ľ�����������λ��1���ĸ�λ���ϣ���Ϊ���ҵ�λ��Ϊλ��0��
int main()
{
	long long n;
	long long res = 0;
	cin >> n;

	while (n) {
		res += n / 2;
		n /= 2;
	}

	cout << res << endl;

	system("pause");
	return 0;
}