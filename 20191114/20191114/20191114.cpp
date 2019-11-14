#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//将一个数变成斐波那契数最少需要多少步
#if 0
int Fibonacci(int x) {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	int a = v[0], b = v[1], c = 0;
	for (int i = 2; i <= x; ++i) {
		c = a + b;
		a = b;
		b = c;

		v.push_back(c);
	}
	return c;
}
int main()
{
	int N;
	cin >> N;

	int result = 0, i = 2;
	result = Fibonacci(i);
	while (N > result) {
		++i;
		result = Fibonacci(i);
	}
	int a = Fibonacci(i - 1);
	int c = (result - N) > (N - a) ? (N - a) : (result - N);

	cout << c << endl;

	system("pause");
	return 0;
}
#endif
/*
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n % 2 != 0)
			return false;

		stack<char> m;
		char *str = &A[0];
		if (*str == '(' || *str == ')') {
			m.push(*str++);
		}

		int size = 1;
		while (size >= 0 && *str!='\0') {
			if (*str == '(') {
				m.push(*str);
				++size;
				++str;
			}
			else if (*str == ')') {
				m.pop();
				--size;
				++str;
			}
			else
				return false;
		}
		return true;
	}
};
*/

//合法序列括号判断
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n % 2 != 0)
			return false;

		int size = 0;
		if (A[0] == '(' || A[0] == ')') {
			++size;
		}

		for (int i = 1; i < A.length(); ++i)
		{
			if (size >= 0) {
				if (A[i] == '(') {
					++size;
				}
				else if (A[i] == ')') {
					--size;
				}
				else
					return false;
			}
			else
				return false;
		}

		if (size == 0)
			return true;
	}
};

int main()
{
	Parenthesis p;
	string str = "(()())";
	int lenth = str.length();

	cout << p.chkParenthesis(str, lenth) << endl;

	system("pause");
	return 0;
}