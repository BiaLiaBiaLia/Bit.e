#include <iostream>
#include <vector>
#include <string>
using namespace std;

//�Ǽ�����
//�����n�η�(n=������ÿ��������),���Ͻ�������쳲�����������
#if 0
vector<int> v{ 1,1 };
void fibo_init() {
	for (int i = 2; i < 10001; ++i) {
		v.push_back((v[i - 1] + v[i - 2]) % 10000);  //������λ����%10000
	}
}

int main()
{
	int n, x;
	fibo_init();
	while (cin >> n) {
		while (n--) {
			cin >> x;
			printf("%04d", v[x]);  //������4λ��0�����õ�printf(%04d)
		}
		cout << endl;
	}

	system("pasue");
	return 0;
}
#endif

//������
int num_heel(int n) {
	int sum = 0;
	while (n) {
		int x = n % 10;
		n /= 10;
		sum += x;
	}
	if (sum > 9)
		return num_heel(sum);
	else
		return sum;
}
int main()
{
	string n;
	while (cin >> n) {
		int count = 0;
		for (int i = 0; i < n.size(); ++i) {
			count += n[i] - '0';
		}
		cout << num_heel(count) << endl;
	}

	system("pause");
	return 0;
}