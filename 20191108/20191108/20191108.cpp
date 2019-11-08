#include <iostream>
using namespace std;


class Solution
{
public:
//��̨��
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж���������
//�����һ��������һ�ף���ôʣ�µ�n-1��̨�ף�������f(n-1)
//�����һ�����������ף���ôʣ�µ�n - 2��̨�ף�������f(n - 2)
//���������ּ���ɵã�f(n) = f(n - 1) + f(n - 2)
	int jumpFloor(int number)
	{
		if (number <= 0)
			return 0;
		if (number <= 2)
			return number;

		int x = 1;//��һ��̨��ֻ��һ������
		int y = 2;//��һ��̨��ֻ����������
		int z;
		for (int i = 3; i <= number; ++i)
		{
			z = x + y;
			x = y;
			y = z;
		}
		return z;
	}


//��̬��̨��
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж���������
//��n = n ʱ
//��һ������һ�׺󣬺��滹��f(n-1)��������
//��һ���������׺󣬺��滹��f(n-2)������......��һ������n�׺󣬺��滹�� f(n-n)������
//f(n) = f(n-1) + f(n-2) +...+ f(2) + f(1) + 1
//f(n - 1) = f(n - 2) + ... + f(2) + f(1) + 1
//����һ�� �ã�f(n)=2*f(n-1)
	int jumpFloorII(int number)
	{
		if (number <= 0)
			return 0;
		if (1 == number)
			return 1;

		int f = 1;//��ʾn=1ʱ��ֻ��һ������
		for (int i = 2; i <= number; ++i)
		{
			f = 2 * f;
		}
		return f;
	}
};

int main()
{
	Solution s;
	cout << s.jumpFloor(5) << endl;
	cout << s.jumpFloorII(5) << endl;

	system("pause");
	return 0;
}
