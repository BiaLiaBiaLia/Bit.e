#include <iostream>
#include <stack>
using namespace std;

//包含min函数的栈
class Solution {
public:
	void push(int value) {
		s1.push(value);
		if (s2.empty()) {  //保证s2中至少有一个值
			s2.push(value);
		}
		else if (value <= s2.top()) {  //小于等于都存放
			s2.push(value);
		}
	}
	void pop() {
		if (s1.top() == s2.top())
			s2.pop();
		s1.pop();
	}
	int top() {
		return s1.top();
	}
	int min() {
		return s2.top();
	}
private:
	stack<int> s1;
	stack<int> s2;
};

void Test()
{
	Solution s;
	s.push(5);
	s.push(2);
	s.push(8);
	s.push(9);
	s.push(4);
	s.push(7);
	s.push(3);

	cout << s.min() << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}