#include<iostream>
#include<algorithm>
using namespace std;

//Ҫ��n�Ķ�����ֵ����m�ĵ�jλ����iλ��ֻ��Ҫ��n������jλ��Ȼ���ٽ��л����㣨|������
class BinInsert 
{
public:
	int binInsert(int n, int m, int j, int i) 
	{
		m <<= j;
		return n | m;
	} 
};

//�������һ��ż����ӽ�����������
//�ж�����
bool isPrime(int num)
{   
	int tmp = sqrt(num);

//ֻ�����������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
	for (int i = 2; i <= tmp; i++)
	{        
		if (num %i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	int half; 
	int i; 
	while (cin >> num) {
		half = num / 2;
		//���м��������� 
		for (i = half; i > 0; i--) 
		{          
			if (isPrime(i) && isPrime(num - i))     
				break;     
		}
		cout << i << endl << num - i << endl;
	}

	system("pause");
	return 0;
}