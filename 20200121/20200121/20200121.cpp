#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

//��ȫ��
#if 0
int count(int n) {
	int cnt = 0;
	if ((n < 0) | (n > 500000))
		return -1;
	else {
		for (int i = 2; i <= n; i++) {
			int sum = 0;
			//������Χ
			int sq = sqrt(i);
			for (int j = 2; j <= sq; j++) {
				if (i%j == 0) {
					//���j^2 = i��˵������Լ����ͬ��ֻ��һ��
					if (i / j == j)
						sum += j;
					else
						//����������ͬ��Լ����Ҫ���
						sum += j + (i / j);
				}
			}
			if (sum + 1 == i)
				cnt++;
		}
		return cnt;
	}
}

//�˿��ƴ�С
int main() {
	int input;
	while (cin >> input)
		cout << count(input) << endl;

	system("pause");
	return 0;
}
#endif

int main() {
	string line;
	while (getline(cin, line)) {
		//��ը���ֱ�����
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else {
			int dash = line.find('-');
			//�ֿ�������
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//��ȡ�ո�Ĵ���������Ϊc + 1
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			//�õ���һ����
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2) {
				//ֻҪ������ȣ����һ���ƴ�ļ�Ϊ��
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				//��������ͬ��˵�����Ͳ�ͬ,ֻ��ը�����Ժ������ƱȽ�
				//�������Ͷ��Ǵ����
				if (c1 == 3)
				cout << car1 << endl;
				else if (c2 == 3)
				cout << car2 << endl;
				else
				cout << "ERROR" << endl;
			}
		}
	}

	system("pause");
	return 0;
}