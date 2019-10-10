#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0
//�̳��뾲̬��Ա
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
//�̳�����Ԫ
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
	//�ú����ǻ������Ԫ����
	//�����ڸú����з��ʻ��ౣ������˽�еĳ�Ա
	B b;
	b._b = 10;

	//���ܷ���������˽�л��߱����ĳ�Ա
	//D d;
	//d._d = 10;
	//���ۣ���Ԫ��ϵ���ܱ��̳�
}
#endif

#if 0
//��ͬ�̳з�ʽ�£�������Ķ���ģ��
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

//�����ཫ���������еĳ�Ա���̳е�������
//�����������ģ���У��ȼ̳��ĸ��࣬�û����еĳ�Ա���ڶ���ģ�͵����Ϸ�
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
//�����⣺ʲô�����μ̳У����μ̳���ʲôȱ�ݣ���ν����

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
	//C1��B�м̳���һ��_b��C2��B�м̳���һ��_b
	//D����C1�м̳�һ��_b����C2�м̳�һ��_b
	//D�о�������_b
	//���ֱ��ͨ��������������_b,��������֪�������ĸ�_b
	//���뱨�����ʲ���ȷ
	//���Ͼ������μ̳�ȱ�ݣ����μ̳еĶ�����
    //d._b = 1;

	//���ô���ͨ�����룺�÷��ʱ����ȷ
	//1.��_bǰ���ӻ��������
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	//2.�ܷ����������Ա��B����D����ֻ����һ��
	//���ԡ�����������̳�
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

//����̳к���ͨ���̳���ʲô����
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

//��������̳�
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
	//C1��B�м̳���һ��_b��C2��B�м̳���һ��_b
	//D����C1�м̳�һ��_b����C2�м̳�һ��_b
	//D�о�������_b
	//���ֱ��ͨ��������������_b,��������֪�������ĸ�_b
	//���뱨�����ʲ���ȷ
	//���Ͼ������μ̳�ȱ�ݣ����μ̳еĶ�����
	//d._b = 1;

	//���ô���ͨ�����룺�÷��ʱ����ȷ
	//1.��_bǰ���ӻ��������
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	//2.�ܷ����������Ա��B����D����ֻ����һ��
	//���ԡ�����������̳�
	d._b = 0;

	system("pause");
	return 0;
}