#include <iostream>
#include <vector>
#include <string>
using namespace std;

//iNOC��Ʒ��-������ǵı���
#if 0
void YH(int n)
{
	vector<vector<int> > vv(n);
	for (int i = 0; i < n; ++i) {
		vv[i].resize(2 * n - 1);
	}

    //��n�е�Ԫ�صĵ�һ�������һ����Ҫ��ǰ��ֵΪ1.�����е�Ԫ�أ�����һ���⣬���չ�ʽ
    // a[i][j]=a[i][j-1]+a[i][j]+a[i][j+1];
	vv[0][n - 1] = vv[n - 1][0] = vv[n - 1][2 * n - 2] = 1;

	if (n < 3)
	{
		cout << "-1" << endl;
		return;
	}

	//��������
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < 2 * n - 2; ++j)
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j + 1];
	}

	for (int i = 0; i < 2 * n - 1; ++i)
		if (vv[n - 1][i] % 2 == 0)
		{
			cout << i + 1 << endl;
			return;
		}
	cout << -1 << endl;
}
int main()
{
	int n;
	while (cin >> n) {
		YH(n);
	}

	system("pause");
	return 0;
}
#endif

//�������������
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2) {
		string result;//��Ž���ַ���
		int len1 = s1.length();
		int len2 = s2.length();
		int len = len1 > len2 ? len1 : len2;//��ַ�������
		int m = 0;//��Ž���λ
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		for (int i = 0; i < len; ++i) {
			int v1 = i < s1.length() ? s1[i] - '0' : 0;
			int v2 = i < s2.length() ? s2[i] - '0' : 0;
			int val = (v1 + v2 + m) % 10;
			m = (v1 + v2 + m) / 10;
			result.insert(result.begin(), val + '0');//����ͷ����������ټ��Ͻ���λ��ֵ
		}

		if (1 == m) {       //���������ڽ�λ�����ٲ���һ��1
			result.insert(result.begin(), m + '0');
		}

		cout << result << endl;
	}

	system("pause");
	return 0;
}