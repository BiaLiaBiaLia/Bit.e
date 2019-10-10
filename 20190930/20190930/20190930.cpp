#include <iostream>
using namespace std;

#if 0
//ͬ������
//�������������о�����ͬ���Ƶĳ�Ա����Ա����������ʱ
//���ͨ����������������ͬ���Ƶĳ�Աʱ�����ȵ����������Լ���
//����ǳ�Ա����ͬ�������Ա�����������Ƿ���ͬ�޹�
//����ǳ�Ա����ͬ�������Ա������ԭ���Ƿ���ͬ�޹�
//�����ȵ����������Լ���ͬ����Ա
//�����Ҫ���û���ĳ�Ա��ֻ����ͬ����Աǰ���ӻ���������Լ��������޶���
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

	d.Base::TestFunc(10);//�����е�ͬ������

	system("pause");
	return 0;
}
#endif

#if 0
//�������û�ж��幹�캯�����߻������Ĭ�ϵĹ��캯�����޲εĺ�ȫȱʡ�Ĺ��캯����
//1.��������Բ��ö���
//2.�����������Ҫ���������飬���Լ��Ĺ��캯����ʾ��������
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
	//�����������������ɵ�Ĭ�Ϲ��캯��
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

//�����������޲εĹ��캯��ʱ�������������ʽ�����Լ��Ĺ��캯��
//���ұ��������ʼ���б��λ����ʾ���û���Ĺ��캯������������������
//���ಿ�ֳ�Ա�ĳ�ʼ��
class Derived :public Base
{
public:
	Derived(int b,int d)
		:Base(b)
		,_d(d)
	{}

    //�������û����ʾ�����Լ��Ŀ������캯�����������Ƿ��嶼����
	//���������ʾ�����Լ��Ĺ��쿽�������������������ʾ���忽�����캯��
	//������Ҫ���俽�������ʼ���б��λ����ʾ���û���Ŀ������캯��
	Derived(const Derived& d)
		:Base(d)
		,_d(d._d)
	{}

	/*û���漰����Դ����ʱ�����������û����ʾ�����Լ��ĸ�ֵ��������أ�������������һ��Ĭ�ϵ�
	��Ĭ�ϵĸ�ֵ��������ؿ��������ĸ�ֵ

	��������漰����Դ������������Ҫ���Լ��Ŀ������캯����ʾ����
	���������ڲ���ʾ���û���ĸ�ֵ�����������ɻ��ಿ�ֵĸ�ֵ��
	������Լ����еĳ�Ա��ֵ
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

	//��������󣺻��ಿ��+�����ಿ��
	~Derived()
	{
		//�����������Լ�����Դ
		cout << "Derived::~Derived" << endl;

		//�����������������һ�����֮�����һ���������������Ļ�����
		//������������������ڻ��ಿ�ֵ���Դ
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

	//��������󣺻��ಿ��+�����ಿ��
	~Derived()
	{
		//�����������Լ�����Դ
		cout << "Derived::~Derived" << endl;

		//�����������������һ�����֮�����һ���������������Ļ�����
		//������������������ڻ��ಿ�ֵ���Դ
		//call Base::~Base();
	}

	char _d;
};

/*
1.��ӡ���
    Base::Base
    Derived::Derived()
    Derived::~Derived
    Base::~Base 
2.�������ô��򣨴���/�����ĸ���Ķ��󣬾͵����ĸ���Ĺ���//����������
    �����๹��
	���๹��
	����������
	��������
*/
void TestDerived()
{
	Derived d(10, 20);
	/*
	����������Ĺ��캯��
	    �����û���Ĺ��캯��
	�������������������
	    �������������Լ�����Դ
	    ���������Լ��ӵ�call ~Base(){}
    */
}

int main()
{
	TestDerived();

	system("pause");
	return 0;
}