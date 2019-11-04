#include <iostream>
#include <stack>
using namespace std;

//用两个栈实现队列
//入队：将元素进栈A
//出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；
//如果不为空，栈B直接出栈。
class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		int x;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				x = stack1.top();
				stack2.push(x);
				stack1.pop();
			}
		}
		x = stack2.top();
		stack2.pop();
		return x;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.pop() << " ";
	cout << s.pop() << endl;

	system("pause");
	return 0;
}