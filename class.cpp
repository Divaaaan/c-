#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>

using namespace std;

struct Name {
//private:
	int a;
	double b, c;
//public:
	Name(int a, double nb, double nc = 0)
	{
		this -> a = a;
		b = nb;
		c = nc;
	}

	Name()
	{
		a = 0;
		b = 0;
		c = 0;
	}

	Name(int na) : a(na), b(0), c(0) {};
	~Name()
	{
		cout << "krak";

	 }
};

class Class {
	int a;
};

int main()
{
	Name a (1, 2, 3);
	Name a1{ 1, 2, 3 };
	Name a2 = { 1, 2, 3 };
	Name a3 = Name{ 1, 2, 3 };
	Name a4 = Name(1, 2, 3);
	a3 = a4;

	a.b = 5;
	Name *e = new Name;
	delete e;
	Name* p = &a;
	(*p).b = 8;
	p->b = 8;
	Class o;
}
