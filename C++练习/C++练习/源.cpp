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

auto i = func(0,1);
#include<vector>
extern "C"
{
	int main();
}
int main()
{
	cout << "main" << endl;
	
	func(1, 2);
	/*func(1, 2);
	func(3, 4);*/
	return 0;
}