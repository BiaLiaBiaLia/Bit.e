#include <iostream>
#include <string>
using namespace std;

//多继承下的多态
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1::TestFunc1" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "B1::TestFunc2" << endl;
	}

	int _b1;
};

class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B1::TestFunc3" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "B1::TestFunc4" << endl;
	}

	int _b2;
};

class D :public B1, public B2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "D::TestFunc4" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "D::TestFunc5" << endl;
	}

	int _d;
};

typedef void(*PVFT)();

void PrintVFT1(B1&b,const string str)
{
	cout << str << endl;

	PVFT* pVFT = (PVFT*)(*(int *)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << "" << endl;
}

void PrintVFT2(B2&b,const string str)
{
	cout << str << endl;

	PVFT* pVFT = (PVFT*)(*(int *)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << "" << endl;
}

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;

	PrintVFT1(d, "B1:");
	PrintVFT2(d, "B2:");

	system("pause");
	return 0;
}