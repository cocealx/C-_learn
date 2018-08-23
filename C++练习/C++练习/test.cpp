//
//  main.cpp
//  Demo
//
//  Created by 杜国超 on 16/12/28.
//  Copyright © 2016年 杜国超. All rights reserved.
//

//#include<iostream>
//using namespace std;
//
//class MYClass
//{
//public:
//	static void staticfunc();
//	void test(int a, int b);
//	virtual void sing();
//	virtual void run();
//};
//
//void MYClass::staticfunc()
//{
//	std::cout << "MYClass staticfunc" << std::endl;
//}
//
//void MYClass::test(int a, int b)
//{
//	std::cout << "MYClass test=" << a + b << std::endl;
//}
//
//void MYClass::sing()
//{
//	std::cout << "MYClass Sing" << std::endl;
//}
//
//void MYClass::run()
//{
//	std::cout << "MYClass run" << std::endl;
//}
//
//class ChildClass : public MYClass
//{
//public:
//	void test(int a, int b);
//	virtual void sing();
//};
//
//void ChildClass::test(int a, int b)
//{
//	std::cout << "ChildClass test=" << a - b << std::endl;
//}
//
//void ChildClass::sing()
//{
//	std::cout << "ChildClass Sing" << std::endl;
//}
//
//typedef	void    (MYClass::* MYClass_FUNC)(int, int);
//typedef	void    (MYClass::* MYClass_FUNC1)();
//
//typedef	void	(ChildClass::* ChildClass_FUNC2)(int, int);
//typedef	void    (ChildClass::* ChildClass_FUNC3)();
//
//typedef	void(*STATIC_FUNC4)();

//int main(int argc, const char * argv[])
//{
//	//父类成员函数指针指向父类成员函数
//	MYClass_FUNC func1 = &MYClass::test;
//	MYClass_FUNC1 func2 = &MYClass::sing;
//
//	//父类成员函数指针指向子类覆盖后的或重写后的父类成员函数(不允许)
//	//    MYClass_FUNC func3 = &ChildClass::test;
//	//    MYClass_FUNC1 func4 = &ChildClass::sing;
//
//	//子类成员函数指针指向父类和子类成员函数
//	ChildClass_FUNC2 func5 = &MYClass::test;
//	ChildClass_FUNC2 func6 = &ChildClass::test;
//
//	//子类成员函数指针指向父类和子类成员函数
//	ChildClass_FUNC3 func7 = &MYClass::sing;
//	ChildClass_FUNC3 func8 = &ChildClass::sing;
//
//	//父类成员函数指针指向父类和子类成员函数
//	MYClass_FUNC1 func9 = &MYClass::run;
//	MYClass_FUNC1 func10 = &ChildClass::run;
//
//	//静态成员函数
//	STATIC_FUNC4 func11 = &MYClass::staticfunc;
//
//	MYClass Ca;
//	ChildClass Cb;
//	int a = 6;
//	int b = 4;
//	MYClass&pc = Cb;
//	pc.sing();
//	typedef void*(*hand)(void*);
//	hand handle = (hand(*(int*)(&func1)));
//	handle(NULL);
//	std::cout << "**************************" << std::endl;
//	//(pc.*func5)(a, b);
//	//(pc.*func6)(a, b);
//	std::cout << "**************************" << std::endl;
//	(Ca.*func1)(a, b);
//	(Cb.*func1)(a, b);
//
//	std::cout << "**************************" << std::endl;
//	
//	(Ca.*func2)();
//	(Cb.*func2)();
//	std::cout << "**************************" << std::endl;
//	(Cb.*func5)(a, b);
//	(Cb.*func6)(a, b);
//	//func7指向基类 func8指向派生类 查看能否实现多态调用（不能，在编译期间已经确定了调用方法）
//	std::cout << "**************************" << std::endl;
//	(Cb.*func7)();
//	(Cb.*func8)();
//
//	std::cout << "**************************" << std::endl;
//	(Ca.*func9)();
//	(Ca.*func10)();
//
//	std::cout << "**************************" << std::endl;
//	func11();
//
//}
//#define ARRAY(arr) (sizeof(arr)/sizeof(arr[0]))
//#pragma pack(2)
//class A
//{
//public:
//	char d;
//	int c;
//	short b;
//	
//	//没有在类外定义，会出现链接时错误，相当于是一种声名一样。
//	static int a;
//};
////const int b = 20;
//#define OFFSET(Type, value)  ((int)(&((Type*)0)->value))
//int main()
//{
//	const int a = 10;
//	const int b = 20;
//	const int*p = &b;
//	int array[a+b];
//	int *p1 = (int*)&b;
//	//cout << A::a << endl;
//	cout << b << endl;
//	*p1 = 30;
//	cout << b << endl;
//	cout << ARRAY(array) << endl;
//	cout << sizeof(A) << endl;
//	cout << OFFSET(A, c) << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//
//int main()
//{
//	string s1 = "你好,中国";
//	string s2 = "你好,中国";
//	string s3 = "你们";
//	map<string, string>ret;
//	ret.insert(make_pair(s1, s2));
//	map<string, string>::iterator it = ret.find(s3);
//	if (it!=ret.end())
//		cout << it->first << endl;
//	else
//		cout << "not equal" << endl;
//	return 0;
//}


////纯虚函数能不能是析构函数
//
//class base
//{
//	
//public:
//	//virtual base() = 0;
//	////{
//
//	////}
//	virtual int fun() = 0;
//	virtual ~base() = 0;
//};
//base::~base()
//{
//	cout << "base" << endl;
//}
//int base::fun()
//{
//	return 0;
//}
//class dir :public base
//{
//public:
//	~dir()
//	{
//		cout << "dir" << endl;
//	}
//	int fun()
//	{
//		return 0;
//	}
//};
//union s
//{
//	char a;
//	int b[5];
//	double c;
//};
//int main()
//{
////	base a;
//	dir b;
//	int a[5][5];
//	cout << sizeof(s) << endl;
//	cout << (int*)(a + 1)-(int*)a << endl;
//	cout << (*a + 1)-(int*)a << endl;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//int find(vector<int>&sum, int num)
//{
//	int left = 0;
//	int right = sum.size() - 1;
//	int mid = left + (right - left) >> 1;
//	while (left<=right)
//	{
//		mid = left + (right - left) >> 1;
//		if (mid <= 1)
//			return mid;
//		if (sum[mid] >= num&& sum[mid - 1] < num)
//		{
//				return mid;
//		}	
//		else if (sum[mid] > num&&sum[mid - 1] > num)
//		{
//			right = mid - 1;
//		}
//		else if (sum[mid] < num&&sum[mid - 1] < num)
//		{
//			left = mid;
//		}
//		else if (sum[mid - 1] == num)
//			return mid - 1;
//	}
//	return -1;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> sum;
//	sum.resize(n);
//	cin >> sum[0];
//	for (int i = 1; i < n; ++i)
//	{
//		cin >> sum[i];
//		sum[i] += sum[i - 1];
//	}
//	int m = 0;
//	cin >> m;
//	int num = 0;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> num;
//		cout << find(sum, num) << endl;;
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int find(vector<int>&sum, int num)
//{
//	int left = 0;
//	int right = sum.size();
//	int mid = -1;
//	while (left<right)
//	{
//		mid = left + ((right - left) >> 1);
//		if (sum[mid] == num)
//			return mid;
//		else if ((mid == 0 && num<sum[mid]) || (num>sum[mid - 1] && num<sum[mid]))
//			return mid;
//		else if (num<sum[mid])
//			right = mid;
//		else
//			left = mid + 1;
//	}
//	return -1;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> sum;
//	sum.resize(n);
//	cin >> sum[0];
//	for (int i = 1; i < n; ++i)
//	{
//		cin >> sum[i];
//		sum[i] += sum[i - 1];
//	}
//	int m = 0;
//	cin >> m;
//	int num = 0;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> num;
//		cout << find(sum, num)+1 << endl;
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	/*priority_queue<int,greater<int>()> q1;*/
//	//priority_queue<int, less<int>()> q1;
//
//	 char arr[] = "abcdef";
//	 printf("%d\n", strlen((char*)&arr));//6
//	 cout << typeid(&arr).name() << endl;;
//	 printf("%d\n", strlen((char*)&arr + 1));//随机值
//	 cout << typeid(&arr).name() << endl;;
//	printf("%d\n", strlen(&arr[0] + 1));//5
//	cout << typeid(&arr[0]).name() << endl;;
//	const char *p = "abcdef";
//	printf("%d\n", strlen((char*)&p));//随机值
//	printf("%d\n", strlen((char*)&p + 1));//随机值
//	printf("%d\n", strlen(&p[0] + 1));//5
//	return 0;
//}
//void reserve(string &str, int left, int right)
//{
//	while (left<right)
//	{
//		swap(str[left], str[right]);
//		++left;
//		--right;
//	}
//}
//void  find(string&str)
//{
//	int size = str.size();
//	int i = 0;
//	int left = 0;
//	int right = -1;
//	for (; i<size; i++)
//	{
//		if (str[i] == ' ')
//		{
//			right = i - 1;
//			reserve(str, left, right);
//			while (str[i] == ' ')
//			{
//				++i;
//			}
//			left = i;
//		}
//	}
//	reserve(str, left, size - 1);
//}
//#include<stdio.h>
//#include<stdlib.h>
//#define _CRT_SECURE_NO_WARNINGS
//int main()
//{
//
//	char buf[1024];
//	//memset(buf, 0, sizeof(buf));
//	//scanf("%s", buf);
//	
//	gets_s(buf);
//	string str(buf);
//	cout << str << endl;
//	find(str);
//	reserve(str,0,str.size()-1);
//	cout << str << endl;
//}


//class A
//{
//	A&a;
//	A&b;
//};
//struct str_t
//{
//	long long len;
//	char data[32];
//};
//struct data1_t
//{
//	long long len;
//	int data[2];
//};
//struct data2_t
//{
//	long long len;
//	char*data[1];
//};
//struct data3_t
//{
//	long long len;
//	void*data[];
//};
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//	struct str_t str;
//	memset((void*)&str, 0, sizeof(struct str_t));
//	str.len = sizeof(struct str_t) - sizeof(int);
//	_snprintf_s(str.data, str.len,str.len, "hello");
//	struct data3_t* pData = (struct data3_t*)printf("data:%s%s\n", str.data, (char*)(&(pData->data[0])));
////	cout << sizeof(A) << endl;
//	return 0;
//}
#include<iostream>

#include<string>
using namespace std;
//int main()
//{
//	string str("12345");
//	string str2(str.substr(1, 2));
//	cout << str2 << endl;
//	char p[] = "S\065AB";
//	return 0;
//}

class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
	virtual void fun(int q)
	{

	}
	static void * operator new(size_t, void *_Where) 
	{
		return NULL;
	}
};
class C :public A
{
public:
	virtual void fun(int q)
	{

	}

};
class B :public A
{
public:
	B()
	{

	}
	~B()
	{

	}
	inline void add()
	{
		cout << "123" << endl;
	}
	virtual void fun(int q)
	{

	}
};


///不能重新定义placement new （定位 new）
//static void * operator new(size_t, void *_Where)
//{
//	return NULL;
//}
//#include<string>	
//#include<vector>
//#include<memory>
//
//vector<vector<int>> sloution(const vector<int>&det,int i,vector<vector<int>>&ret,vector<int>temp)
//{
//	if (i == det.size())
//		ret.push_back(temp);
//	for (int j = i; j < det.size(); ++j)
//	{
//		temp.push_back(det[i]);
//		sloution(det,++j,ret,temp);
//		temp.pop_back();
//	}
//	return ret;
//}
//int main()
//{
//	vector<int>temp;
//	temp.push_back(1);
//	temp.push_back(2);
//	temp.push_back(3);
//	vector<int>ttemp;
//	vector<vector<int>>ret;
//	sloution(temp, , ret, ttemp);
//	return 0;
//}
//int main()
//{
//	char buf[1024];
//	A*a = new(buf)A[2];
//	B b;
//	C c;
//	C*ct = dynamic_cast<C*>(a);
//	b.~B();
//	b.add();
//
//	//子类向基类转换或者基类向子类
//	a = static_cast<A*>(&b);
//	B*pb = static_cast<B*>(a);
//
//	const int ci = 100;
//	//不能去掉类型的const，volitale属性
//	//int* tci = static_cast<int*>(&ci);
//	int  i;
//	//无关类型之间不能转换
//	//double *p = static_cast<double*>(&i);
//
//	void *v = static_cast<void*>(&i);
//
//	double *p = reinterpret_cast<double*>(ci);
//	
//	string s("121212");
//	auto it = s.begin();
//	std::advance(it, -2);
//	cout << distance(it, s.end()) << endl;;
//	cout << distance(s.end(), s.begin()) << endl;
//	vector<int>re;
//	re.reserve(3);
//	re.push_back(1);
//	re.push_back(1);
//	re.push_back(1);
//	cout << re.capacity() << endl;;
//	re.push_back(1);
//	cout << re.capacity() << endl;;
//
//	vector<int>vt;
//	shared_ptr<vector<int>> st (new vector<int>(20,20));
//	unique_ptr<int> ui (new int[10]);
//	unique_ptr<int>ui1;
//	ui.swap(ui1);
//	return 0;
//}

/////单例模式
class dl{
	dl()
	{
		++count;
	}
	dl(const dl&)
	{

	}
	static int count;
public:
	static dl&Get()
	{
		static dl te;
		return te;
	}
	static void pr()
	{
		cout << count << endl;
	}
};
int dl::count = 0;

#include<vector>
//int main()
//{
//	//dl&t = dl::Get();
//	//dl&t1 = dl::Get();
//	//dl&t2 = dl::Get();
//	//dl&t3 = dl::Get();
//	//dl::pr();
//	//vector<int> s;
//	//s.back();
//
//
//	return 0;
//}