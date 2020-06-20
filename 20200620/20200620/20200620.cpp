#include <iostream>
#include <vector>
using namespace std;

//������һ�úϷ����������Ľڵ㶼�������ֱ�ʾ�����ڸ�������������еĸ��ӹ�ϵ����������ĸ߶�
int func(int n, vector<vector<int> > &rows, int init)
{
	int max_length = 0;
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{

		if (rows[i][0] == init && count < 2)
		{
			count++;
			int length = func(n, rows, rows[i][1]);
			max_length = (max_length > length ? max_length : length);
		}
	}
	return max_length + 1;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int> > rows;
		int a1, a2;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a1 >> a2;
			vector<int> row(2);
			row[0] = a1;
			row[1] = a2;
			rows.push_back(row);
		}
		int height = 0;

		height = func(n, rows, 0);
		cout << height << endl;

	}

	system("pause");
	return 0;
}