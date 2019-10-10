#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0
//继承与静态成员
class B
{
public:
	void Test()
	{
		cout << "B:" << &_count << endl;
	}
	static int _count;
};

int B::_count = 0;

class D1:public B
{
public:
	void TestFunc()
	{
		cout << "D1:" << &_count << endl;
		_count = 10;
	}
};

class D2 :public B
{
public:
	void TestFunc()
	{
		cout << "D2:" << &_count << endl;
		_count = 10;
	}
};

int main()
{
	B b;
	b.Test();

	D1 d1;
	d1.TestFunc();

	D2 d2;
	d2.TestFunc();

	system("pause");
	return 0;
}
#endif

#if 0
//继承与友元
class B
{
	friend void TestFunc();
public:
protected:
	int _b;
};

class D :public B
{
protected:
	int _d;
};

void TestFunc()
{
	//该函数是基类的友元函数
	//可以在该函数中访问基类保护或者私有的成员
	B b;
	b._b = 10;

	//不能访问子类中私有或者保护的成员
	//D d;
	//d._d = 10;
	//结论：友元关系不能被继承
}
#endif

#if 0
//不同继承方式下，派生类的对象模型
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

//派生类将两个基类中的成员都继承到子类中
//在派生类对象模型中：先继承哪个类，该基类中的成员就在对象模型的最上方
class D :public B1,public B2
{
public:
	int _d; 
};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	system("pause");
	return 0;
}
#endif

#if 0
//面试题：什么是菱形继承？菱形继承有什么缺陷？如何解决？

class B
{
public:
	int _b;
};

class C1 :public B
{
public:
	int _c1;
};

class C2 :public B
{
public:
	int _c2;
};

class D :public C1, public C2
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;

	D d;
	//C1从B中继承了一个_b，C2从B中继承了一个_b
	//D：从C1中继承一个_b，从C2中继承一个_b
	//D中就有两份_b
	//如果直接通过派生类对象访问_b,编译器不知道访问哪个_b
	//编译报错：访问不明确
	//以上就是菱形继承缺陷：菱形继承的二义性
    //d._b = 1;

	//想让代码通过编译：让访问变得明确
	//1.在_b前增加基类的名称
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	//2.能否让最顶层基类成员（B）在D类中只保存一份
	//可以——菱形虚拟继承
	system("pause");
	return 0;
}
#endif

#if 0
class B
{
public:
	int _b;
};

class D :virtual public B
{
public:
	int _d;
};

//虚拟继承和普通单继承有什么区别？
int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = 1;
	d._d = 2;

	system("pause");
	return 0;
}
#endif

//菱形虚拟继承
class B
{
public:
	int _b;
};

class C1 :virtual public B
{
public:
	int _c1;
};

class C2 :virtual public B
{
public:
	int _c2;
};

class D :public C1, public C2
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;

	D d;
	//C1从B中继承了一个_b，C2从B中继承了一个_b
	//D：从C1中继承一个_b，从C2中继承一个_b
	//D中就有两份_b
	//如果直接通过派生类对象访问_b,编译器不知道访问哪个_b
	//编译报错：访问不明确
	//以上就是菱形继承缺陷：菱形继承的二义性
	//d._b = 1;

	//想让代码通过编译：让访问变得明确
	//1.在_b前增加基类的名称
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	//2.能否让最顶层基类成员（B）在D类中只保存一份
	//可以——菱形虚拟继承
	d._b = 0;

	system("pause");
	return 0;
}