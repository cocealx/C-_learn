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

int main(int argc, const char * argv[])
{
	//父类成员函数指针指向父类成员函数
	MYClass_FUNC func1 = &MYClass::test;
	MYClass_FUNC1 func2 = &MYClass::sing;

	//父类成员函数指针指向子类覆盖后的或重写后的父类成员函数(不允许)
	//    MYClass_FUNC func3 = &ChildClass::test;
	//    MYClass_FUNC1 func4 = &ChildClass::sing;

	//子类成员函数指针指向父类和子类成员函数
	ChildClass_FUNC2 func5 = &MYClass::test;
	ChildClass_FUNC2 func6 = &ChildClass::test;

	//子类成员函数指针指向父类和子类成员函数
	ChildClass_FUNC3 func7 = &MYClass::sing;
	ChildClass_FUNC3 func8 = &ChildClass::sing;

	//父类成员函数指针指向父类和子类成员函数
	MYClass_FUNC1 func9 = &MYClass::run;
	MYClass_FUNC1 func10 = &ChildClass::run;

	//静态成员函数
	STATIC_FUNC4 func11 = &MYClass::staticfunc;

	MYClass Ca;
	ChildClass Cb;
	int a = 6;
	int b = 4;
	MYClass&pc = Cb;
	pc.sing();
	std::cout << "**************************" << std::endl;
	//(pc.*func5)(a, b);
	//(pc.*func6)(a, b);
	std::cout << "**************************" << std::endl;
	(Ca.*func1)(a, b);
	(Cb.*func1)(a, b);

	std::cout << "**************************" << std::endl;
	
	(Ca.*func2)();
	(Cb.*func2)();
	std::cout << "**************************" << std::endl;
	(Cb.*func5)(a, b);
	(Cb.*func6)(a, b);
	//func7指向基类 func8指向派生类 查看能否实现多态调用（不能，在编译期间已经确定了调用方法）
	std::cout << "**************************" << std::endl;
	(Cb.*func7)();
	(Cb.*func8)();

	std::cout << "**************************" << std::endl;
	(Ca.*func9)();
	(Ca.*func10)();

	std::cout << "**************************" << std::endl;
	func11();
}
