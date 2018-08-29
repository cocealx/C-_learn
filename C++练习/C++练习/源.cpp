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
//�ƶ����캯�����ƶ���ֵ�����
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
//	CSingleton(){ cout << "�������󴴽���" << endl; };
//	CSingleton(const CSingleton &);
//	CSingleton& operator=(const CSingleton &);
//	
//	~CSingleton(){ cout << "�����������٣�" << endl; };
//
//public:
//	static CSingleton*getInstance()
//	{
//		static CSingleton myInstance; // �������������
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
//	CSingleton(){ cout << "�������󴴽���" << endl; };
//	CSingleton(const CSingleton &);
//	CSingleton& operator=(const CSingleton &);
//	~CSingleton(){ cout << "�����������٣�" << endl; };
//	static CSingleton *myInstance;
//public:
//	
//	static CSingleton* getInstance()
//	{
//		return myInstance;
//	}
//
//private:
//	 //����һ���ڲ���
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
//	 /*����һ���ڲ���ľ�̬����
//	 ���ö�������ʱ��˳�����ͷ�myInstanceָ��Ķ�����Դ*/
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


///��������ָ��ͻ�����ʵ���̰߳�ȫ
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
class Mutex :noncopyable{//�������ķ�װ
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
class MutexLockGuard :noncopyable{//RAII��������
public:
	explicit MutexLockGuard(Mutex& mutex) :mutex_(mutex){//��ʾ����
		mutex_.lock();
	}
	~MutexLockGuard(){
		mutex_.unlock();
	}
private:
	Mutex& mutex_;//ע�������ã���������
};
Mutex mutex;
shared_ptr<vector<int> > vec_ptr;
void* worker1(void* arg){//�߳�1�������Ԫ��
	int i = 0;
	do{
		cout << "read vector" << endl;
		{//���²���������һ������
			shared_ptr<vector<int> > temp_ptr;//��Ϊ�۲���
			{
				MutexLockGuard guard(mutex);//��ȡ��
				temp_ptr = vec_ptr;//����shared_ptr���󣬱�����������ü�����1
				assert(!temp_ptr.unique());
			}
			for (vector<int>::iterator it = temp_ptr->begin(); it != temp_ptr->end(); it++){//�ù۲���shared_ptr��Ϊ���
				cout << *it << " ";
			}
			cout << endl;
		}
		sleep(0.1);
	} while (++i<5);//5���������
}
void* worker2(void* arg){//�߳�2���������Ԫ��
	int i = 0;
	do{
		{//�����������˳����������ʱ����ᱻ����
			cout << "write vector" << endl;
			MutexLockGuard guard(mutex);//��ȡ��
			if (!vec_ptr.unique()){//�����������ߣ������ж��д����Ϊ��һ�����Ѿ���֤��ֻ��һ��д�߽�����ٽ���
				vec_ptr.reset(new vector<int>(*vec_ptr));//дʱ��������ʱ���ж��ߣ���ô���߶�ȡ��Ԫ���Ǿɵ��Ǹ�vector�����µ�vector����д�߲���
				cout << "copy on write" << endl;
			}
			assert(vec_ptr.unique());
			vec_ptr->push_back(i * 100);//д�����
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