#include<string>
#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		vector<vector<int>> V(N, vector<int>(2, 0));//��ʼ����ά����
		string rule;
		for (auto &i : V)
			for (auto &j : i)
				cin >> j;
		cin >> rule;
		int count = 0;
		stack<char> cal;//�洢����ʽ����ĸ
		for (int i = 0; i < rule.size(); i++)
		{
			if (rule[i] == ')')
				if (cal.size() != 1)
				{
					vector<int> temp2 = V[cal.top() - 'A'];
					cal.pop();
					vector<int> &temp1 = V[cal.top() - 'A'];
					count += temp1[1] * temp1[0] * temp2[1];
					temp1[1] = temp2[1];
				}
				else;
			else if (rule[i] != '(')
				cal.push(rule[i]);
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}