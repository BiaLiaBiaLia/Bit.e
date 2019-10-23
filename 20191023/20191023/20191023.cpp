#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
using namespace std;

#if 0
//shared_ptr
//缺陷：1.不是线程安全(加锁)
//      2.只能管理new的资源(仿函数---定制删除器)
//定制删除器
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
#endif

//存在循环引用问题(加入weak_ptr)
#include <memory.h>

struct ListNode
{
	//ListNode* next;
	//ListNode* pre;

	ListNode(int d)
		:data(d)
		//next(nullptr)
		//pre(nullptr)
		//data(d)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "ListNode():" << this << endl;
	}

	//shared_ptr<ListNode> next;
	//shared_ptr<ListNode> pre;
	weak_ptr<ListNode> next;
	weak_ptr<ListNode> pre;

	int data;
};

void TestList()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->next = sp2;
	sp2->pre = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	TestList();

	system("pause");
	return 0;
}