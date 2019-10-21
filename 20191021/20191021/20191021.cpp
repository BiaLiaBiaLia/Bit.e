#include <iostream>
using namespace std;

//C++中预防内存泄漏-->智能指针
//让一个类管理原生态指针
//RAII
//优势：用户不需要关心资源何时去释放
//缺陷：浅拷贝

//智能指针原理：RAII+类对象具有指针类似的行为+解决浅拷贝
//C++98---auto_ptr(1.0):解决浅拷贝方式--->资源的转移
//缺陷：多个对象不能同时访问同一份资源
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

		//让类对象具有指针类似的行为
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
	//常规指针
	int a = 10;
	int* p1 = &a;
	int* p2(p1);

	*p1 = 20;
	*p2 = 30;

	bia::auto_ptr<int> ap1(new int);

	//解决方式：将资源转移
	bia::auto_ptr<int> ap2(ap1);
	//*ap1 = 10;//会崩溃---ap1以及将资源转移给了ap2，自己与资源断开链接
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

//改进：auto_ptr(2.0)
//原理：RAII+具有指针类似的行为+解决浅拷贝:资源管理权的转移（对资源释放的权力）
//缺陷：可能会产生野指针
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
				//先处理以前的旧资源
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
		//mutable  可变的，与const恰好相反
		mutable bool _owner;//资源真正的拥有者（对资源有释放权力的对象）
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

//建议：什么情况下都不要使用auto_ptr
#endif

//C++11：智能指针
//unique_ptr:RAII+类似指针行为+解决浅拷贝（对象独占资源，防止被拷贝）
//防止被拷贝：
//1.C++98：拷贝构造&&赋值运算符重载  只声明不定义+访问权限private
//2.C++11:
//unique_ptr(const unique_ptr<T>&)=delete;
//unique_ptr<T>& operator=(const unique_ptr<T>&)=delete;
//缺陷：对象之间不能共享资源
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

		//具有指针类似行为
		T& operator*()
		{
			return *_ptr;
		}

		T& operator->()
		{
			return _ptr;
		}
/*	private://C++98  只声明不定义+private
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
	//bia::unique_ptr<int> ap2(ap1); 无法调用拷贝构造函数
	bia::unique_ptr<int> ap2;
	//ap2=ap1;无法调用赋值运算符
}

int main()
{
	TestFunc();

	system("pause");
	return 0;
}