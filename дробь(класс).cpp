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
		int j, less, num = this->numerator, den = this->denominator;//num - ���������, den - �����������
		do {
			if (num < den)                                    //��� ������ num ��� den
				less = num;                               //���� ��� ����� ����������
			else                                                   //���� if ����� ������,
				less = den;                                //� less ��������� �������� �����������
			for (j = less; j > 0; j--) {                      //���������� ����� �������� (���)
				if (!(num % j) && !(den % j)) {     //���� num � den ������� ��� �������
					num /= j;                          //������ ��� ������, ����� �� ����
					den /= j;                           //��������� � ����������� 
					break;                               //������� �� ����� for
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
