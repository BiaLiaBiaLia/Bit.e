#include <iostream>
#include <string>
using namespace std;

//�ַ�����ת
//д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ���
#if 0
int main()
{
	string n;
	while (cin >> n) {
		int len = n.size();
		for (int i = 0; i < len / 2; ++i) {
			swap(n[i], n[len - i - 1]);
		}
		cout << n << endl;
	}

	system("pause");
	return 0;
}
#endif

//������󹫹��ַ����ĳ���
int main()
{
	string a, b, ret;
	int count;  //������󹫹��ַ����ĳ���
	while (cin >> a >> b) {
		count = 0;
		if (a.size() > b.size())
			swap(a, b);
		for (int i = 0; i < a.size(); ++i) {
			for (int j = i; j < a.size(); ++j) {
				string temp = a.substr(i, j - i + 1);
				int flag = b.find(temp);
				if (flag < 0)  //˵����b��û�ҵ������ַ���
					break;
				else if (temp.size() > ret.size()) {
					ret = temp;
					count = ret.size();
				}
			}
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}