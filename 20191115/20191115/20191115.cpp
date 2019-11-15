#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

//����С������
#if 0
int main()
{
	int A, B;
	cin >> A >> B;

	int t1 = A > B ? A : B;//�����
	int t2 = A > B ? B : A;//��С��
	int i = 1;
	while ((i*t1) % t2 != 0) {
		++i;
	}
	cout << i * t1 << endl;

	system("pause");
	return 0;
}
#endif

//�������򷽷�
vector<string> vs;
//�ֵ�������
bool lexicographically() {
	int i = 0;
	while ((i + 1) < vs.size()) {//ȷ�������������ַ���
		if (vs[i].compare(vs[i + 1]) > 0)
			return 0;
		++i;
	}
	return 1;
}

//��������
bool lengths() {
	int i = 0;
	while (i + 1 < vs.size()) {
		if (vs[i].size() > vs[i + 1].size())
			return 0;
		++i;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		vs.push_back(s);
	}

	int a = lexicographically();
	int b = lengths();

	if (1 == a && 0 == b)
		cout << "lexicographically" << endl;
	else if (1 == a && 1 == b)
		cout << "both" << endl;
	else if (0 == a && 1 == b)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;

	system("pause");
	return 0;
}
