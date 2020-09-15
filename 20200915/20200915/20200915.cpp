#include <iostream>
#include <string>
#include <stack>
#include <bitset>
using namespace std;

//À¨ºÅÆ¥ÅäÎÊÌâ
#if 0
int main()
{
	string str;
	while (cin >> str) {
		stack<char> s;
		int len = str.length();
		if (len == 0) {
			cout << "true" << endl;
			break;
		}
		for (auto& i : str) {
			if (i == '(' || i == '[' || i == '{')
				s.push(i);
			else if (i == ')' && !s.empty() && s.top() == '(')
				s.pop();
			else if (i == ']' && !s.empty() && s.top() == '[')
				s.pop();
			else if (i == '}' && !s.empty() && s.top() == '{')
				s.pop();
			else {
				s.push(i);
				break;
			}

		}
		if (s.empty())
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	system("pause");
	return 0;
}
#endif

//É¾³ý×Ö·û´®ÖÐÖØ¸´×Ö·û  
int main()
{
	string str;
	string res;
	bitset<26> bs;
	while (cin >> str) {
		for (auto &i : str) {
			int j = i - 'a';
			if (!bs.test(j)) {
				res += i;
				bs.set(j);
			
		}
			cout << res << endl;
	}
	return 0;
}