#include <iostream>
#include <stack>
using namespace std;

//������ջʵ�ֶ���
//��ӣ���Ԫ�ؽ�ջA
//���ӣ��ж�ջB�Ƿ�Ϊ�գ����Ϊ�գ���ջA������Ԫ��pop����push��ջB��ջB��ջ��
//�����Ϊ�գ�ջBֱ�ӳ�ջ��
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