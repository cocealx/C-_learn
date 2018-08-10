//
//  main.cpp
//  Demo
//
//  Created by 杜国超 on 16/12/28.
//  Copyright © 2016年 杜国超. All rights reserved.
//

#include<iostream>
using namespace std;

class MYClass
{
public:
	static void staticfunc();
	void test(int a, int b);
	virtual void sing();
	virtual void run();
};

void MYClass::staticfunc()
{
	std::cout << "MYClass staticfunc" << std::endl;
}

void MYClass::test(int a, int b)
{
	std::cout << "MYClass test=" << a + b << std::endl;
}

void MYClass::sing()
{
	std::cout << "MYClass Sing" << std::endl;
}

void MYClass::run()
{
	std::cout << "MYClass run" << std::endl;
}

class ChildClass : public MYClass
{
public:
	void test(int a, int b);
	virtual void sing();
};

void ChildClass::test(int a, int b)
{
	std::cout << "ChildClass test=" << a - b << std::endl;
}

void ChildClass::sing()
{
	std::cout << "ChildClass Sing" << std::endl;
}

typedef	void    (MYClass::* MYClass_FUNC)(int, int);
typedef	void    (MYClass::* MYClass_FUNC1)();

typedef	void	(ChildClass::* ChildClass_FUNC2)(int, int);
typedef	void    (ChildClass::* ChildClass_FUNC3)();

typedef	void(*STATIC_FUNC4)();

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

#include<iostream>
#include<string>
#include<map>
using namespace std;
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


//纯虚函数能不能是析构函数

class base
{
	
public:
	//virtual base() = 0;
	////{

	////}
	virtual int fun() = 0;
	virtual ~base() = 0;
};
base::~base()
{
	cout << "base" << endl;
}
int base::fun()
{
	return 0;
}
class dir :public base
{
public:
	~dir()
	{
		cout << "dir" << endl;
	}
	int fun()
	{
		return 0;
	}
};
union s
{
	char a;
	int b[5];
	double c;
};
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
#include<iostream>
#include<string>
using namespace std;
void reserve(string &str, int left, int right)
{
	while (left<right)
	{
		swap(str[left], str[right]);
		++left;
		--right;
	}
}
void  find(string&str)
{
	int size = str.size();
	int i = 0;
	int left = 0;
	int right = -1;
	for (; i<size; i++)
	{
		if (str[i] == ' ')
		{
			right = i - 1;
			reserve(str, left, right);
			while (str[i] == ' ')
			{
				++i;
			}
			left = i;
		}
	}
	reserve(str, left, size - 1);
}
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{

	char buf[1024];
	//memset(buf, 0, sizeof(buf));
	//scanf("%s", buf);
	
	gets_s(buf);
	string str(buf);
	cout << str << endl;
	find(str);
	reserve(str,0,str.size()-1);
	cout << str << endl;
}