#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>

using namespace std;

struct dot {
	int x, y;
	double dist(dot d2)
	{
		return sqrt((x - d2.x) * (x - d2.x) - (y - d2.y) * (y - d2.y));
	}
	dot(int nx = 0, int ny = 0) {
		x = nx;
		y = ny;
	}
	void scan()
	{
		cin >> x >> y;
	}
};

struct segment {
	dot x, y;
	void scan() {
		x.scan();
		y.scan();
	}
	double length()
	{
		return x.dist(y);
	}
};

int main()
{
	cin
}
