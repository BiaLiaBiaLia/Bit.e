#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0
double Division(int a, int b)
{
	//��b==0ʱ�׳��쳣
	if (b == 0)
		throw "Divison by zero condition!";
	else
		return ((double)a / (double)b);
}

void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char*errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unkown exception" << endl;
	}

	system("pause");
	return 0;
}
#endif

//�쳣�������׳�
double Division(int a, int b)
{
	//��b==0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	//������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	//�������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦��
	//���ﲶ�����������׳�ȥ
	int* array = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}

	catch (...)
	{
		cout << "delete[]" << array << endl;
		delete[]array;
		throw;
	}

	cout << "delete[]" << array << endl;

	delete[]array;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}

	system("pause");
	return 0;
}
