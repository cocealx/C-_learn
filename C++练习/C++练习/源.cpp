#include<stdio.h>
#include<iostream>
using namespace std;
extern "C"
{
	int  func(int a, int b)
	{
		cout << "func" << endl;
		++a;
		++b;
		a = b;
		return a;
	}
}

auto i = func(0, 1);
//#include<vector>
//extern "C"
//{
//	int main();
//}
//int main()
//{
//	cout << "main" << endl;
//	
//	func(1, 2);
//	/*func(1, 2);
//	func(3, 4);*/
//	return 0;
//}
//移动构造函数和移动赋值运算符
//class A
//{
//public:
//	char*a;
//	A()
//	{
//		a = new char[1];
//	}
//	A(const A&&b):a(b.a)
//	{
//		b.a=NULL;
//	}
//};
//int main()
//{
//
//}

#define C_SINGLETON_H

//#include<iostream>
//using namespace std;
//class CSingleton
//{
//private:
//	CSingleton(){ cout << "单例对象创建！" << endl; };
//	CSingleton(const CSingleton &);
//	CSingleton& operator=(const CSingleton &);
//	
//	~CSingleton(){ cout << "单例对象销毁！" << endl; };
//
//public:
//	static CSingleton*getInstance()
//	{
//		static CSingleton myInstance; // 单例对象在这里！
//		return &myInstance;
//	}
//	static void  print()
//	{
//		cout << "dl" << endl;
//	}
//};

//#include<iostream>
//using namespace std;
//class CSingleton
//{
//private:
//	CSingleton(){ cout << "单例对象创建！" << endl; };
//	CSingleton(const CSingleton &);
//	CSingleton& operator=(const CSingleton &);
//	~CSingleton(){ cout << "单例对象销毁！" << endl; };
//	static CSingleton *myInstance;
//public:
//	
//	static CSingleton* getInstance()
//	{
//		return myInstance;
//	}
//
//private:
//	 //定义一个内部类
//	class CGarbo{
//	private:
//		int c;
//		CGarbo(){};
//		~CGarbo()
//		{
//			if (nullptr != myInstance)
//			{
//				delete myInstance;
//				myInstance = nullptr;
//			}
//			CSingleton b;
//			cout << b.a << endl;
//		}
//	};
//private:
//		
//	 /*定义一个内部类的静态对象
//	 当该对象销毁时，顺带就释放myInstance指向的堆区资源*/
//	static CGarbo m_garbo;
//	int a;
//};
//class A
//{
//private:
//	A()
//	{
//		a = 0;
//	}
//	int a;
//};
//CSingleton * CSingleton::myInstance = new CSingleton();
//int main()
//{
//	
//	CSingleton *p1 = CSingleton::getInstance();
//	CSingleton *p2 = CSingleton::getInstance();
//	CSingleton *p3 = CSingleton::getInstance();
//	//CSingleton d1(*p1);
//	cout << p1 << endl;
//	cout << p2 << endl;
//	cout << p3 << endl;
//	/*cout << &d1 << endl;*/
////	CSingleton::myInstance = new CSingleton();
////	A*pa = new A();
//	return 0;
//}


///利用智能指针和互斥锁实现线程安全
#include<iostream>
#include<exception>
#include<pthread.h>
#include<unistd.h>
#include<string>
#include<vector>
#include<assert.h>
#include<boost/noncopyable.hpp>
#include<boost/shared_ptr.hpp>
#include<memory>
using namespace std;
using namespace boost;
class Mutex :noncopyable{//互斥量的封装
public:
	Mutex(){
		pthread_mutex_init(&mutex, NULL);
	}
	void lock() const{
		pthread_mutex_lock(&mutex);
	}
	void unlock() const{
		pthread_mutex_unlock(&mutex);
	}
	~Mutex(){
		pthread_mutex_destroy(&mutex);
	}
private:
	mutable pthread_mutex_t mutex;
};
class MutexLockGuard :noncopyable{//RAII管理互斥量
public:
	explicit MutexLockGuard(Mutex& mutex) :mutex_(mutex){//显示构造
		mutex_.lock();
	}
	~MutexLockGuard(){
		mutex_.unlock();
	}
private:
	Mutex& mutex_;//注意是引用，否则会出错
};
Mutex mutex;
shared_ptr<vector<int> > vec_ptr;
void* worker1(void* arg){//线程1输出容器元素
	int i = 0;
	do{
		cout << "read vector" << endl;
		{//以下操作限制在一个域中
			shared_ptr<vector<int> > temp_ptr;//作为观察者
			{
				MutexLockGuard guard(mutex);//获取锁
				temp_ptr = vec_ptr;//拷贝shared_ptr对象，被管理对象引用计数加1
				assert(!temp_ptr.unique());
			}
			for (vector<int>::iterator it = temp_ptr->begin(); it != temp_ptr->end(); it++){//用观察者shared_ptr作为输出
				cout << *it << " ";
			}
			cout << endl;
		}
		sleep(0.1);
	} while (++i<5);//5次输出操作
}
void* worker2(void* arg){//线程2向容器添加元素
	int i = 0;
	do{
		{//限制作用域，退出作用域后临时对象会被析构
			cout << "write vector" << endl;
			MutexLockGuard guard(mutex);//获取锁
			if (!vec_ptr.unique()){//若有其它读者，不会有多个写者因为上一句锁已经保证了只有一个写者进入此临界区
				vec_ptr.reset(new vector<int>(*vec_ptr));//写时拷贝，此时若有读者，那么读者读取的元素是旧的那个vector，而新的vector将由写者操作
				cout << "copy on write" << endl;
			}
			assert(vec_ptr.unique());
			vec_ptr->push_back(i * 100);//写入操作
		}
		sleep(0.1);
	} while (++i<5);
}
int main(){
	pthread_t pid1, pid2;
	vec_ptr.reset(new vector<int>(1, -1));
	pthread_create(&pid1, NULL, worker1, NULL);
	pthread_create(&pid2, NULL, worker2, NULL);
	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);
	return 0;
}