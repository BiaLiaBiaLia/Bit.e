#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

#if 0
class WashRoom
{
public:
	void GoToManRoom()
	{
		cout << "往前一小步，文明一大步" << endl;
	}

	void GoToLadyRoom()
	{
		cout << "往后一小步，-----" << endl;
	}
};

//抽象类
class Person
{
public:
	//纯虚函数
	virtual void GoToWC(WashRoom& wc) = 0;

protected:
	string _name;
	int _age;
};

#if 0
//在派生类中必须重写基类中的纯虚函数
//否则子类也是抽象类，无法实例化对象
class Man :public Person
{
public:

};
#endif

class Man :public Person
{
public:
	virtual void GoToWC(WashRoom& wc)
	{
		wc.GoToManRoom();
	}
};

class Woman :public Person
{
	virtual void GoToWC(WashRoom& wc)
	{
		wc.GoToLadyRoom();
	}
};

void TestWC(size_t n)
{
	Person* p;
	WashRoom wc;
	for (size_t i = 0; i < n; i++)
	{
		if (rand() % 2)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}

		p->GoToWC(wc);
		delete p;

		Sleep(2000);
	}
}
int main()
{
	//Person p;  抽象类不能实例化对象
	//Man m;

	TestWC(10);

	system("pause");
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	int _b;
};

class Derived:public Base
{
public:
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

public:
	int _d;
};

//函数指针变类型
typedef void(*PVFT)();

int main()
{
	PVFT p;
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;

	Base b;
	b._b = 10;

	Derived d;
	d._b = 1;
	d._d = 2;

	//需要获取虚表的地址：对象前4个字节
	//&d;  对象首地址
	//(int*)&d   整形指针---指向对象前4个字节
	//*(int*)(&d)   将对象前4个字节中的内容取出--->整形数据 和虚表地址在数据值上是相等的
	PVFT* pVFT=(PVFT*)(*(int*)(&d));

	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}

	system("pause");
	return 0;
}
#endif

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	int _b;
};

class Derived :public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	int _d;
};

typedef void(*PVFT)();

void PrintVFT(Base& b,const string& s)
{
	cout << s << endl;
	PVFT* pVFT=(PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	Base b;
	b._b = 1;

	Derived d;
	d._b = 1;
	d._d = 2;
	
	PrintVFT(b, "Base VFT:");
	PrintVFT(d, "Derived VFT:");

	system("pause");
	return 0;
}