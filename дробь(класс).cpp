#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

struct Fraction {
	int numerator;
	unsigned int denominator;
	Fraction(int n = 0, int d = 1) {
		if (d <= 0) {
			cout << "not correct cin";
			return;
		}
		numerator = n;
		denominator = d;
	}
	Fraction sm(Fraction a) {
		Fraction ret;
		ret.numerator = this->numerator * a.denominator + this->denominator * a.numerator;
		ret.denominator = this->denominator * a.denominator;
		return ret;
	}
	Fraction dif(Fraction a) {
		Fraction ret;
		ret.numerator = this->numerator * a.denominator - this->denominator * a.numerator;
		ret.denominator = this->denominator * a.denominator;
		return ret;
	}
	Fraction mult(Fraction a) {
		Fraction ret;
		ret.numerator = this->numerator * a.numerator;
		ret.denominator = this->denominator * a.denominator;
		return ret;
	}
	Fraction division(Fraction a) {
		Fraction ret;
		ret.numerator = this->numerator * a.denominator;
		ret.denominator = this->denominator * a.numerator;
		return ret;
	}
	void dl() {
		int j, less, num = this->numerator, den = this->denominator;//num - числитель, den - знаменатель
		do {
			if (num < den)                                    //Что меньше num иле den
				less = num;                               //Если все дроби правильные
			else                                                   //этот if можно убрать,
				less = den;                                //а less присвоить значение знаменателя
			for (j = less; j > 0; j--) {                      //Наибольший общий делитель (НОД)
				if (!(num % j) && !(den % j)) {     //Если num и den делятся без остатка
					num /= j;                          //значит НОД найден, делим на него
					den /= j;                           //числитель и знаменатель 
					break;                               //Выходим из цикла for
				}
			}
		} while (j != 1);
		cout << num << "/" << den;
	}
};

/*struct dot{
	int x, y;
	double space(dot d2) {
		return sqrt(pow((x - d2.x), 2) + pow((y - d2.y), 2));
	}
	void set_x(int x) {
		this -> x = x;
	}
};*/


int main()
{

}
