#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int m[10] = { 0 };//���������
		int x[10] = { 0 };//��Ӧ���������
		for (int i = 0; i < n; i++)
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> x[i];
		int v[120000] = { 0 };
		int max = 0;
		for (int i = 0; i < n; i++)
			max += m[i] * x[i];

		for (int i = 0; i < n; i++)//��n�ֲ�ͬ�������������ѭ��
		{
			for (int k = max; k >= 0; k--)//��0~max������������ѭ��
			{
				for (int j = 1; j <= x[i]; j++)//��i��������x[i]����1~x[i]ѭ��
				{
					if (k == 0 || (v[k] == 1 && v[k + j * m[i]] != 1))//���ĳһ�������ڣ���С�����أ���ô������һ������������ض�����
						v[k + j * m[i]] = 1;
				}
			}
		}
		int cnt = 1;
		for (int i = 1; i <= max; i++)
			if (v[i] == 1)
				cnt++;
		cout << cnt << endl;
	}

	system("pause");
	return 0;
}