#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>

using namespace std;


int main()
{
	string s2 = "1234";
	cout << s2[0] << " " << s2.size() << endl;
	s2 = string("12") + "123";
	s2 += "1";
	cout << s2;
	cout << s2.c_str() << endl; // возвращает строку типа char*
	//s2.clear();
	//s2.erase(s2.begin());// удаление (указатель (итератор) на первый элемент)
	cout << s2 << endl;
	cout << s2.find("12", 2) << endl; //первое вхождение строчки "12" начиная с символа 2 (второй параметр можно опустить)
	//возвращает string::npos либо -1 в случае, если не нашёл
	cout << s2.substr(3, 2); //подстрока с 3го два символа
}
