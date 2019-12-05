#include<iostream>
#include<algorithm>
using namespace std;

//要把n的二进制值插入m的第j位到第i位，只需要把n先左移j位，然后再进行或运算（|）即可
class BinInsert 
{
public:
	int binInsert(int n, int m, int j, int i) 
	{
		m <<= j;
		return n | m;
	} 
};

//查找组成一个偶数最接近的两个素数
//判断素数
bool isPrime(int num)
{   
	int tmp = sqrt(num);

//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
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
		//从中间向两边找 
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