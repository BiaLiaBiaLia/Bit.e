#include <iostream>
using namespace std;

//C++��Ԥ���ڴ�й©-->����ָ��
//��һ�������ԭ��ָ̬��
//RAII
//���ƣ��û�����Ҫ������Դ��ʱȥ�ͷ�
//ȱ�ݣ�ǳ����

//����ָ��ԭ��RAII+��������ָ�����Ƶ���Ϊ+���ǳ����
//C++98---auto_ptr(1.0):���ǳ������ʽ--->��Դ��ת��
//ȱ�ݣ����������ͬʱ����ͬһ����Դ
#if 0
namespace bia
{
	template <class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//ap2(ap1);
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//ap1=ap2
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}

		//����������ָ�����Ƶ���Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T& operator->()
		{
			return _ptr;
		}

	protected:
		T* _ptr;
	};
}

void TestFunc()
{
	//����ָ��
	int a = 10;
	int* p1 = &a;
	int* p2(p1);

	*p1 = 20;
	*p2 = 30;

	bia::auto_ptr<int> ap1(new int);

	//�����ʽ������Դת��
	bia::auto_ptr<int> ap2(ap1);
	//*ap1 = 10;//�����---ap1�Լ�����Դת�Ƹ���ap2���Լ�����Դ�Ͽ�����
	*ap2 = 20;

	bia::auto_ptr<int> ap3(new int);
	ap3 = ap2;
}
int main()
{
	TestFunc();

	system("pause");
	return 0;
}
#endif

//�Ľ���auto_ptr(2.0)
//ԭ��RAII+����ָ�����Ƶ���Ϊ+���ǳ����:��Դ����Ȩ��ת�ƣ�����Դ�ͷŵ�Ȩ����
//ȱ�ݣ����ܻ����Ұָ��
#if 0
namespace bia
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(_ptr)
			,_owner(false)
		{
			if (_ptr)
				_owner = true;
		}

		auto_ptr(const auto_ptr<T>& ap)
			: _ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				//�ȴ�����ǰ�ľ���Դ
				if (_ptr&&_owner)
					delete _ptr;

				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr&&_owner)
				delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T& operator->()
		{
			return _ptr;
		}

	protected:
		T* _ptr;
		//mutable  �ɱ�ģ���constǡ���෴
		mutable bool _owner;//��Դ������ӵ���ߣ�����Դ���ͷ�Ȩ���Ķ���
	};
}

void TestFunc()
{
	bia::auto_ptr<int> ap1(new int);
	bia::auto_ptr<int> ap2(ap1);
	bia::auto_ptr<int> ap3;
	ap3 = ap2;

	*ap1 = 10;
	*ap2 = 20;
	*ap3 = 30;
}
int main()
{
	TestFunc();

	system("pause");
	return 0;
}

//���飺ʲô����¶���Ҫʹ��auto_ptr
#endif

//C++11������ָ��
//unique_ptr:RAII+����ָ����Ϊ+���ǳ�����������ռ��Դ����ֹ��������
//��ֹ��������
//1.C++98����������&&��ֵ���������  ֻ����������+����Ȩ��private
//2.C++11:
//unique_ptr(const unique_ptr<T>&)=delete;
//unique_ptr<T>& operator=(const unique_ptr<T>&)=delete;
//ȱ�ݣ�����֮�䲻�ܹ�����Դ
namespace bia
{
	template <class T>
	class unique_ptr
	{
		//RAII
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}

		//����ָ��������Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T& operator->()
		{
			return _ptr;
		}
/*	private://C++98  ֻ����������+private
		unique_ptr(const unique_ptr<T>& ap);
		unique_ptr<T>& operator=(const unique_ptr<T>& ap);
*/
		unique_ptr(const unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;
	protected:
		T* _ptr;
	};
}

void TestFunc()
{
	bia::unique_ptr<int> ap1(new int);
	//bia::unique_ptr<int> ap2(ap1); �޷����ÿ������캯��
	bia::unique_ptr<int> ap2;
	//ap2=ap1;�޷����ø�ֵ�����
}

int main()
{
	TestFunc();

	system("pause");
	return 0;
}