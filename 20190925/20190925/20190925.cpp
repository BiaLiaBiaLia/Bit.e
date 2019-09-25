#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//多态：
#if 0
//普通人
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	string _job;
	int _age;
};

class Student:public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuId;
	double _score;
};

class soldier :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "军人优先" << endl;
	}
};

//在程序运行时，根据基类引用实际引用的子类对象，选择调用对应类的虚函数
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}
//如果多态的实现条件没有完全满足，全部调用基类的虚函数
int main()
{
	Person p;
	Student st;
	soldier so;

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);

	system("pause");
	return 0;
}
#endif

#if 0
//协变
class Base
{
public:
	virtual Base* TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
		return this;
	}
};

class Derived :public Base
{
public:
	virtual Derived* TestFunc()
	{
		cout << "Derived::TestFunc()" << endl;
		return this;
	}
};

void TestVirtualFunc(Base* pd)
{
	pd->TestFunc();
}
int main()
{
	Base b;
	Derived d;

	TestVirtualFunc(&b);
	TestVirtualFunc(&d);

	system("pause");
	return 0;
}
#endif

#if 0
class A
{};

class B:public A
{};

A a;
B b;

//基类返回基类的指针或引用，子类返回子类的指针或引用
//注意：基类和子类不一定是Base类或者Derived类
//      只要是具有继承关系的子类和基类都可以，都属于协变
class Base
{
public:
	virtual A& TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
		return a;
	}
};

class Derived :public Base
{
public:
	virtual B& TestFunc()
	{
		cout << "Derived::TestFunc()" << endl;
		return b;
	}
};

void TestVirtualFunc(Base* pd)
{
	pd->TestFunc();
}
int main()
{
	Base b;
	Derived d;

	TestVirtualFunc(&b);
	TestVirtualFunc(&d);

	system("pause");
	return 0;
}
#endif

#if 0
//析构函数
//常见的面试题：析构函数能不能是虚函数？如果可以，什么情况下建议将基类的析构函数设置成虚函数
class Base
{
public:
	virtual ~Base()
	{
		cout << "Base::~Base()"<<endl;
	}
protected:
	int _b;
};

class Derived :public Base
{
public:
	Derived()
	{
		_p = new int[10];
	}

	~Derived()
	{
		if (_p)
		{
			delete[] _p;
		}
		cout << "Derived::~Derived()" << endl;

		//call Base::~Base();
	}
protected:
	int* _p;
};

int main()
{
	Base* pb = new Derived;
	delete pb;

	system("pause");
	return 0;
}
#endif

#if 0
//C++98--编译器不能帮助用户进行重写检测
//C++11----override:让编译器帮助用户检测派生类是否对基类的某个虚函数进行重写
//         是：编译成功
//         否：编译报错
//注意：override只能修饰子类的虚函数
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	//void TestFunc2()----编译报错：基类中TestFunc2()不是虚函数
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
};

class Derived :public Base
{
public:
	//与基类的函数名字不同
	//virtual void TetsFunc1()override----报错，函数名不同，没有构成重写
	virtual void TestFunc1()override
	{
		cout << "Derived::TetsFunc1()" << endl;
	}

	//基类TestFunc2不是虚函数
	virtual void TestFunc2()override
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	//virtual void TestFunc3(int)override----报错，与基类中虚函数的参数列表不同
	virtual void TestFunc3()override
	{
		cout << "Derived::TestFunc3()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}

int main()
{
	Base b;
	Derived d;

	TestFunc(b);
	TestFunc(d);

	system("pause");
	return 0;
}
#endif

//final如果修饰虚函数：表明该虚函数不能被派生类重写
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
};

class Derived :public Base
{
public:
	virtual void TestFunc1()final
	{
		cout << "Derived::TetsFunc1()" << endl;
	}
};

class D:public Derived
{
	//virtual void TestFunc1()----报错，无法重写
	//{
	//	cout << "Derived::TetsFunc1()" << endl;
	//}
};

void TestFunc(Base& b)
{
	b.TestFunc1();
}

int main()
{
	Base b;
	Derived d;
	D dd;

	TestFunc(b);
	TestFunc(d);
	TestFunc(dd);

	system("pause");
	return 0;
}