#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//��һ����ͨ�����ٲ�����Ϊ쳲�������
#if 0
int changeTOFibo(const int& a) {
	if (1 == a)
		return 0;
	vector<int> Fb;
	Fb.push_back(0);
	Fb.push_back(1);
	int i = 1;
	int x = 0, y = 0;
	while (Fb[i] < a) {
		x = Fb[i];
		int temp = Fb[i] + Fb[i - 1];
		Fb.push_back(temp);
		++i;
		y = Fb[i];
	}
	return (a - x) < (y - a) ? (a - x) : (y - a);
}

int main()
{
	int n;
	while (cin >> n)
		cout << changeTOFibo(n) << endl;

	system("pause");
	return 0;
}
#endif


//�Ϸ�����ƥ��
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (1 == n % 2)
			return false;
		stack<char> temp;
		for (auto &e : A) {
			if (e == '(')
				temp.push('C');
			else if (e == ')' && !temp.empty())
				temp.pop();
			else
				return false;
		}
		if (temp.empty())
			return true;
		return false;
	}
};