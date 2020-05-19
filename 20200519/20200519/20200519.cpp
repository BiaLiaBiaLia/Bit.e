#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
using namespace std;

template <class T>
class DelRef
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
};

template <class T>
class Free
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};

class FClose
{
public:
	void operator()(FILE*& pf)
	{
		if (pf)
		{
			fclose(pf);
			pf = nullptr;
		}
	}
};

namespace bia
{
	template <class T, class DF = DelRef<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(nullptr)
			, _pmutex(nullptr)
		{
			if (_ptr)
			{
				_pcount = new int(1);
				_pmutex = new mutex;
			}
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmutex(sp._pmutex)
		{
			if (_pcount)
			{
				AddRef();
			}
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//让当前对象与资源断开
				Release();

				//与sp共享
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				if (_pcount)
				{
					AddRef();
				}
				return *this;
			}
		}

		~shared_ptr()
		{
			Release();
		}

		//具有指针行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}
	private:
		void AddRef()
		{
			_pmutex->lock();
			++(*_pcount);
			_pmutex->unlock();
		}

		int SubRef()
		{
			_pmutex->lock();
			--(*_pcount);
			_pmutex->unlock();

			return *_pcount;
		}

		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				DF d;
				d(_ptr);
				delete _pcount;
			}
		}

	protected:
		T* _ptr;
		int* _pcount;
		mutex* _pmutex;
	};
}

void TestSharedPtr()
{
	bia::shared_ptr<int> sp1(new int);
	bia::shared_ptr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	bia::shared_ptr<FILE, FClose> sp3(fopen("1.txt", "rb"));
}

int main()
{
	TestSharedPtr();

	system("pause");
	return 0;
}