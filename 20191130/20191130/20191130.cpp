#include <iostream>
#include <vector>
#include <string>
using namespace std;

//С�׵�����֮·
#if 0
int gcd(int x, int y)  //���Լ��(շת�����)
{
	if (x < y)
		swap(x, y);
	return y == 0 ? x : gcd(y, x%y);
}

int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		int c = a;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			if (v[i] <= c)  //<=��ǰ����ֵʱ��ֱ������v[i]
				c += v[i];
			else
			{
				int comnum = gcd(v[i], c);  //�������Լ��
				c += comnum;
			}
		}
		cout << c << endl;
	}

	system("pause");
	return 0;
}
#endif

//��һ���ַ����е�һ��ֻ����һ�ε��ַ�
char FindFirst(string str) {
	int hashtable[256] = { 0 };
	for (int i = 0; i < str.size(); ++i) {
		hashtable[str[i]]++;
	}

	for (int i = 0; i < str.size(); ++i) {
		if (1 == hashtable[str[i]])
			return str[i];
	}
	return 0;
}

int main()
{
	string s;
	while (cin>>s) {
		char result = FindFirst(s);
		if (result == 0)
			cout << -1 << endl;
		else
			cout << result << endl;
	}

	system("pause");
	return 0;
}