#include <iostream>
using namespace std;

//C++11 shared_ptr
//RAII+����ָ�����Ϊ+���ü���
//ȱ�㣺1.�����̰߳�ȫ  2.ֻ�ܹ���new����Դ
#if 0
namespace bia
{
	template <class T>
	class shared_ptr
	{
	public:
		//RAII
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(nullptr)
		{
			if (_ptr)
				_pcount = new int(1);
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			if (_pcount)
				++*_pcount;
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
					//�õ�ǰ��������Դ�Ͽ�
					Release();

					//��sp����
					_ptr = sp._ptr;
					_pcount = sp._pcount;
					if (_pcount)
						++*_pcount;
			}

			return *this;
		}

			~shared_ptr()
	     	{
			    Release();
		    }

			T& operator*()
			{
				return *_ptr;
			}

			T& operator->()
			{
				return _ptr;
			}

			int use_count()
			{
				return *_pcount;
			}

	private:
		void Release()
		{
			if (_ptr && 0 == --*_pcount)
			{
				delete _ptr;
				delete _pcount;
			}
		}
	protected:
		T* _ptr;
		int* _pcount;
	};
}

void TestShare_ptr()
{
	bia::shared_ptr<int> sp1(new int);
	bia::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	bia::shared_ptr<int> sp3(new int);
	bia::shared_ptr<int> sp4(sp3);
	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	cout << endl;

	sp3 = sp1;
	cout << sp3.use_count() << endl;

	sp4 = sp1;
	cout << sp4.use_count() << endl;


}

int main()
{
	TestShare_ptr();

	system("pause");
	return 0;
}
#endif

#if 0
#include <mutex>
namespace bia
{
	template <class T>
	class shared_ptr
	{
	public:
		//RAII
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_pcount(nullptr)
			,_pmutex(nullptr)
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
				AddRef();
		}

		shared_ptr<T>& operator =(const shared_ptr<T> sp)
		{
			if (this != &sp)
			{
				//�õ�ǰ��������Դ�Ͽ�
				Release();

				//��sp����
				_ptr = sp._ptr;
				_pcount = sp._count;
				if (_pcount)
					AddRef();
			}
			return *this;
		}

		~shared_ptr()
		{
			Release();
		}

		//��������ָ����Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T& operator->()
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
		}

		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				delete _ptr;
				delete _pcount;
			}
		}
	protected:
		T* _ptr;
		int* _pcount;
		mutex* _pmutex;//��֤�����İ�ȫ��
	};
}

//mutex: ���Ա�֤�����İ�ȫ��|| ���Ա�֤shared_ptr��
//       �����ܱ�֤shared_ptr������Դ�����ݵİ�ȫ��
struct A
{
	A()
	:a(0)
	,b(0)
	,c(0)
	{}

	int a;
	int b;
	int c;
};

void TestThread(bia::shared_ptr<A>& sp, int N)
{
	for (size_t i = 0; i < N; ++i)
	{
		sp->a++;
		sp->b++;
		sp->c++;
	}
}

#include <thread>

int main()
{
	bia::shared_ptr<A> sp(new A);
	thread t1(TestThread, sp, 100000);
	thread t2(TestThread, sp, 100000);

	t1.join();
	t2.join();

	system("pause");
	return 0;
}
#endif