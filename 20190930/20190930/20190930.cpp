#include <iostream>
using namespace std;

#if 0
//同名隐藏
//基类与派生类中具有相同名称的成员（成员变量或函数）时
//如果通过派生类对象调用相同名称的成员时，优先调用派生类自己的
//如果是成员变量同名，与成员变量的类型是否相同无关
//如果是成员函数同名，与成员函数的原型是否相同无关
//都优先调用派生类自己的同名成员
//如果想要调用基类的成员，只需在同名成员前增加基类的名称以及作用域限定符
class Base
{
public:
	void SetBase(int b)
	{
		_b = b;
	}

	void TestFunc(int)
	{
	}

	void PrintfBase()
	{
		cout << _b << endl;
	}

	int _b;
};

class Derived :public Base
{
public:
	void SetDerived(int b, int d)
	{
		_b = b;
	}

	void TestFunc()
	{}

	int _b;
};

int main()
{
	cout << sizeof(Derived) << endl;

	Derived d;
	d._b = 10;
	d.Base::_b = 2;

	d.Base::TestFunc(10);//基类中的同名函数

	system("pause");
	return 0;
}
#endif

#if 0
//如果基类没有定义构造函数或者基类具有默认的构造函数（无参的和全缺省的构造函数）
//1.派生类可以不用定义
//2.如果派生类需要做其他事情，将自己的构造函数显示给出就行
class Base
{
public:
	Base(int b=10)
		: _b(b)
	{}

	void SetBase(int b)
	{
		_b = b;
	}

	void TestFunc(int)
	{
	}

	void PrintfBase()
	{
		cout << _b << endl;
	}

	int _b;
};

class Derived :public Base
{
public:
	//编译器给派生类生成的默认构造函数
	//Derived()
	//	:Base(10)
	//{}

	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}

	void TestFunc()
	{}

	char _d;
};

int main()
{
	Derived d;

	system("pause");
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{}

	Base(const Base& b)
		:_b(b._b)
	{}

	Base& operator=(const Base& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}
		return *this;
	}

	void SetBase(int b)
	{
		_b = b;
	}

	void TestFunc(int)
	{
	}

	void PrintfBase()
	{
		cout << _b << endl;
	}

	~Base()
	{
		cout << "Base::~Base" << endl;
	}

	int _b;
};

//如果基类具有无参的构造函数时，派生类必须显式定义自己的构造函数
//并且必须在其初始化列表的位置显示调用基类的构造函数，完成派生类对象中
//基类部分成员的初始化
class Derived :public Base
{
public:
	Derived(int b,int d)
		:Base(b)
		,_d(d)
	{}

    //如果基类没有显示定义自己的拷贝构造函数，派生类是否定义都可以
	//如果基类显示定义自己的构造拷贝函数，派生类必须显示定义拷贝构造函数
	//并且需要在其拷贝构造初始化列表的位置显示调用基类的拷贝构造函数
	Derived(const Derived& d)
		:Base(d)
		,_d(d._d)
	{}

	/*没有涉及到资源管理时：如果派生类没有显示定义自己的赋值运算符重载，编译器会生成一份默认的
	该默认的赋值运算符重载可以完整的赋值

	如果类中涉及到资源管理：派生类需要将自己的拷贝构造函数显示给出
	必须在其内部显示调用基类的赋值运算符重载完成基类部分的赋值，
	再完成自己特有的成员赋值
	*/
	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			Base::operator=(d);
			_d = d._d;
		}
		return *this;
	}

	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}

	void TestFunc()
	{}

	//派生类对象：基类部分+派生类部分
	~Derived()
	{
		//派生类清理自己的资源
		cout << "Derived::~Derived" << endl;

		//编译器在派生类最后一条语句之后插入一条基类析构函数的汇编语句
		//清理派生类对象中属于基类部分的资源
		//call Base::~Base();
	}

	char _d;
};

void TestDerived()
{
	Derived d1(10, 20);
	Derived d2(30, 40);

	d1 = d2;
}

int main()
{
	TestDerived();

	system("pause");
	return 0;
}
#endif

class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base::Base" << endl;
	}

	~Base()
	{
		cout << "Base::~Base" << endl;
	}

	int _b;
};

class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{
		cout << "Derived::Derived()" << endl;
	}

	//派生类对象：基类部分+派生类部分
	~Derived()
	{
		//派生类清理自己的资源
		cout << "Derived::~Derived" << endl;

		//编译器在派生类最后一条语句之后插入一条基类析构函数的汇编语句
		//清理派生类对象中属于基类部分的资源
		//call Base::~Base();
	}

	char _d;
};

/*
1.打印结果
    Base::Base
    Derived::Derived()
    Derived::~Derived
    Base::~Base 
2.函数调用次序（创建/析构哪个类的对象，就调用哪个类的构造//析构函数）
    派生类构造
	基类构造
	派生类析构
	基类析构
*/
void TestDerived()
{
	Derived d(10, 20);
	/*
	调用派生类的构造函数
	    ：调用基类的构造函数
	调用派生类的析构函数
	    ：析构派生类自己的资源
	    ：编译器自己加的call ~Base(){}
    */
}

int main()
{
	TestDerived();

	system("pause");
	return 0;
}