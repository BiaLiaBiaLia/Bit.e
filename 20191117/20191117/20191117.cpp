#include <iostream>
#include <string>
#include <stack>
using namespace std;

//求连续最大bit数
#if 0
int main()
{
	int x;

	while (cin >> x) {
		int count = 0;
		int max = 0;
		while (x) {
			if (x & 1) {
				++count;
				if (count > max)
					max = count;
			}
			else
				count = 0;
			x >>= 1;
		}
		cout << max << endl;
	}

	system("pasue");
	return 0;
}
#endif

//合法括号序列判断
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
	    stack<char> sc;
		for (auto ele : A) {
			switch (ele) {
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

int main()
{
	Parenthesis p;
	string str="(()())";
	cout << p.chkParenthesis(str, 6) << endl;

	system("pause");
	return 0;
}