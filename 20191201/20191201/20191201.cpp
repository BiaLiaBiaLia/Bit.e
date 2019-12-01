#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

//����������
#if 0
int main()
{
	int size;
	while (cin >> size) {
		vector<int> v(size);
		for (int i = 0; i < size; ++i) {
			cin >> v[i];
		}

		int result = v[0];
		int sum1 = 0, sum2 = 0;  //sum1��ʾsum[i-1]��sum2��ʾ sum[i]    ���sum[i] = max(sum[i-1], 0) + nums[i]
		for (int i = 1; i < size; ++i) {
			//���㵽num[i]������������� 
			sum2 = sum1 >= 0 ? sum1 + v[i] : v[i];
			if (sum2 > result)
				result = sum2;
			if (sum2 < 0)
				sum2 = 0;
			sum1 = sum2;
		}
		cout << result << endl;
	}

	system("pause");
	return 0;
}
#endif

//�Ϸ����������ж�
class Parenthesis {
public:    bool chkParenthesis(string A, int n)
{
	stack<char> sc;
	for (auto ele : A)
	{
		switch (ele)
		{
		case '(':
			sc.push(ele);
			break;
		case ')':
		{
			if (sc.empty() || sc.top() != '(')
				return false;
			else
				sc.pop();
		}
		break;
		default:
			return false;
		}
	}
	return true;
}
}; 