#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*��ȫ��*/
#if 0
int countOfPerfectNums(int num) {
	int count = 0;
	if (1 == num)
		return count;
	int sum = 0;
	while (num > 1) {
		int tmp = (int)sqrt(num*1.0);
		for (int i = 1; i <= tmp; ++i) {
			if (0 == num % i)
				sum += i + (num/i);
		}
		if ((sum-num) == num)
			++count;
		--num;
		sum = 0;
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
		cout << countOfPerfectNums(n) << endl;

	system("pause");
	return 0;
}
#endif


//�˿��ƴ�С
int main() {
	string str;
	while (getline(cin, str)) {
		//��ը���ֱ�����
		if (str.find("joker JOKER") != -1) {
			cout << "joker JOKER" << endl;
		}
		else {
			int dash = str.find('-');
			//�ֿ�������            
			string car1 = str.substr(0, dash);
			string car2 = str.substr(dash + 1);
			//��ȡ�ո�Ĵ���������Ϊc + 1
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			//�õ���һ����            
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string strr = "345678910JQKA2jokerJOKER";
			if (c1 == c2) {
				//ֻҪ������ȣ����һ���ƴ�ļ�Ϊ��
				if (strr.find(first1) > strr.find(first2)) {
					cout << car1 << endl;
				}
				else {
					cout << car2 << endl;
				}
			}
			else {
				//��������ͬ��˵�����Ͳ�ͬ,ֻ��ը�����Ժ������ƱȽ�
				//�������Ͷ��Ǵ����
				if (c1 == 3) {
					cout << car1 << endl;
				}
				else if (c2 == 3) {
					cout << car2 << endl;
				}
				else {
					cout << "ERROR" << endl;
				}
			}
		}
	}

	system("pause");
	return 0;
}