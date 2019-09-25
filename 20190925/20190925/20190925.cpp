#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//��̬��
#if 0
//��ͨ��
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
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
		cout << "��������" << endl;
	}
};

//�ڳ�������ʱ�����ݻ�������ʵ�����õ��������ѡ����ö�Ӧ����麯��
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}
//�����̬��ʵ������û����ȫ���㣬ȫ�����û�����麯��
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
//Э��
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

//���෵�ػ����ָ������ã����෵�������ָ�������
//ע�⣺��������಻һ����Base�����Derived��
//      ֻҪ�Ǿ��м̳й�ϵ������ͻ��඼���ԣ�������Э��
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
//��������
//�����������⣺���������ܲ������麯����������ԣ�ʲô����½��齫����������������ó��麯��
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
//C++98--���������ܰ����û�������д���
//C++11----override:�ñ����������û�����������Ƿ�Ի����ĳ���麯��������д
//         �ǣ�����ɹ�
//         �񣺱��뱨��
//ע�⣺overrideֻ������������麯��
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	//void TestFunc2()----���뱨��������TestFunc2()�����麯��
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
	//�����ĺ������ֲ�ͬ
	//virtual void TetsFunc1()override----������������ͬ��û�й�����д
	virtual void TestFunc1()override
	{
		cout << "Derived::TetsFunc1()" << endl;
	}

	//����TestFunc2�����麯��
	virtual void TestFunc2()override
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	//virtual void TestFunc3(int)override----������������麯���Ĳ����б�ͬ
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

//final��������麯�����������麯�����ܱ���������д
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
	//virtual void TestFunc1()----�����޷���д
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