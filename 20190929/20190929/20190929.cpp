#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0
//����
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

//������
class Derived:public Base
{
public:
	int _d;
};


int main()
{
	//������̳��˻����еĳ�Ա����
	cout << sizeof(Derived) << endl;

	//������̳��˻����еĳ�Ա����
	Derived d;
	d.SetBase(10);
	d.PrintfBase();

	system("pause");
	return 0;
}
#endif


#if 0
//���ּ̳з�ʽ֮�������:�����в�ͬȨ�޵ĳ�Ա�������е�Ȩ��
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

//������----һ��Ҫ�Ի��������չ
//public�̳з�ʽ��������public��protected����Ȩ�����εĳ�Ա�������е�Ȩ�޲���
//                ������private ���εĳ�Ա�������в���ֱ�ӱ�����||���ɼ������ѱ��̳�
class Derived :public Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;

		//������protected���εĳ�Ա���������е�Ȩ����protected��
		_pro = proD;

		//public�̳з�ʽ��������private��Ա���������в���ֱ�ӷ���
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

//������----һ��Ҫ�Ի��������չ
//protected�̳з�ʽ�������б�public���εĳ�Ա�������е�Ȩ�޽�Ϊprotected
//                   �����б�protected���εĳ�Ա�������е�Ȩ�޲���
//                   �����б�private ���εĳ�Ա�������в���ֱ�ӱ����� || ���ɼ������ѱ��̳�
class Derived :protected Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;

		//������protected���εĳ�Ա���������е�Ȩ����protected��
		_pro = proD;

		//protected�̳з�ʽ��������private��Ա���������в���ֱ�ӷ���
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

//������----һ��Ҫ�Ի��������չ
//private�̳з�ʽ�������б�public��protected���εĳ�Ա�������е�Ȩ�޽�Ϊprivate
//                 �����б�private ���εĳ�Ա�������в���ֱ�ӱ����� || ���ɼ������ѱ��̳�
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

//classĬ�ϼ̳�Ȩ��Ϊprivate
//structĬ�ϼ̳�Ȩ��Ϊpublic
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

//��ֵ���ݹ���----public
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

//�����public�ļ̳з�ʽ�����������Ĺ�ϵ��is-a
//is-a�����Խ�������󿴳���һ���������
//      �������ã������⣩�������������õ��Ļ�������λ�ö�����ʹ�����������
//      ����ģ�ͣ������и�����Ա�������ڴ��еĲ�����ʽ

//1.���Խ��������ֱ�Ӹ�ֵ���������
//2.�����û����ָ���������ֱ��ָ������Ķ���
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