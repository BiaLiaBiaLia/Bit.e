#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0
//基类
class Base
{
public:
	void SetBase(int b)
	{
		_b = b;
	}

	void PrintfBase()
	{
		cout << _b << endl;
	}
public:
	int _b;
};

//派生类
class Derived:public Base
{
public:
	int _d;
};


int main()
{
	//派生类继承了基类中的成员变量
	cout << sizeof(Derived) << endl;

	//派生类继承了基类中的成员函数
	Derived d;
	d.SetBase(10);
	d.PrintfBase();

	system("pause");
	return 0;
}
#endif


#if 0
//三种继承方式之间的区别:基类中不同权限的成员在子类中的权限
//public
class Base
{
public:
	void SetBase(int pub,int pro,int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

	void PrintfBase()
	{
		cout << _pub << " " << _pro << " " << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

//派生类----一定要对基类进行扩展
//public继承方式：基类中public和protected访问权限修饰的成员在子类中的权限不变
//                基类中private 修饰的成员在子类中不能直接被访问||不可见，但已被继承
class Derived :public Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;

		//基类中protected修饰的成员，在子类中的权限是protected的
		_pro = proD;

		//public继承方式，基类中private成员在派生类中不能直接访问
		//_pri = priD;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D :public Derived
{
public:
	void TestFunc()
	{
		_pro = 10;
	}
};

int main()
{
	cout << sizeof(Derived) << endl;

	Derived d;
	d._pub = 10;
	//d.pro=20;

	system("pause");
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

	void PrintfBase()
	{
		cout << _pub << " " << _pro << " " << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

//派生类----一定要对基类进行扩展
//protected继承方式：基类中被public修饰的成员在子类中的权限降为protected
//                   基类中被protected修饰的成员在子类中的权限不变
//                   基类中被private 修饰的成员在子类中不能直接被访问 || 不可见，但已被继承
class Derived :protected Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;

		//基类中protected修饰的成员，在子类中的权限是protected的
		_pro = proD;

		//protected继承方式，基类中private成员在派生类中不能直接访问
		//_pri = priD;
	}

};

class D :public Derived
{
public:
	void TestFunc()
	{
		_pro = 10;
		_pub = 20;
	}
};

int main()
{
	Derived d;
	//d._pub = 10;

	system("pause");
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

	void PrintfBase()
	{
		cout << _pub << " " << _pro << " " << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

//派生类----一定要对基类进行扩展
//private继承方式：基类中被public和protected修饰的成员在子类中的权限降为private
//                 基类中被private 修饰的成员在子类中不能直接被访问 || 不可见，但已被继承
class Derived :private Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;
		_pro = proD;

		//_pri = priD;
	}
};

class D :public Derived {
public:
	void TestFunc()
	{
		//_pub = 10;
		//_pro=20;
	}
};
int main()
{


	system("pause");
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

	void PrintfBase()
	{
		cout << _pub << " " << _pro << " " << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

//class默认继承权限为private
//struct默认继承权限为public
struct Derived : Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;
		_pro = proD;

		//_pri = priD;
	}
};

class D :public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;
		_pro = 20;
	}
};

int main()
{
	Derived d;
	d._pub = 10;

	system("pause");
	return 0;
}
#endif

//赋值兼容规则----public
class Base
{
public:
	void SetBase(int b)
	{
		_b = b;
	}

	void PrintfBase()
	{
		cout << _b<< endl;
	}
protected:
	int _b;
};

class Derived :public Base
{
public:
	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}
protected:
	int _d;
};

//如果是public的继承方式，子类与基类的关系：is-a
//is-a：可以将子类对象看成是一个基类对象
//      函数调用（在类外）：在类外所有用到的基类对象的位置都可以使用派生类对象
//      对象模型：对象中各个成员变量在内存中的布局形式

//1.可以将子类对象直接赋值给基类对象
//2.可以让基类的指针或者引用直接指向子类的对象
int main()
{
	Base b;
	b.SetBase(10);
	
	Derived d;
	d.SetDerived(20, 30);
	
	/*b.SetBase(40);
	b.PrintfBase();*/

	d.SetBase(40);
	d.PrintfBase();
	
	b = d;

	Base* pb = &b;
	pb = &d;

	system("pause");
	return 0;
}