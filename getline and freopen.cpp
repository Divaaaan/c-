#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	int a;
	cin >> a;
	cin.ignore(10, '\n');
	//getline(cin, s);
	getline(cin, s);
	cout << s;
}
