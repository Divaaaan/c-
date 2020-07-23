#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
//#include <time.h>
//#include <random>

using namespace std;




int main()
{
	vector <int> v;
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	stack <int> s;
	string a;
	getline(cin, a);
	while (!cin.eof()) {
		if (a == "-") {
			if (s.size() == 0) {
				cout << "ERROR";
				return 0;
			}
			s.pop();
		}
		else {
			s.push(stoi(a));
		}
		getline(cin, a);
	}
	if (s.size() != 0) {
		while (s.size() != 0) {
			v.push_back(s.top());
			s.pop();
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << " ";
		}
	}
	else {
		cout << "EMPTY";
	}
}
