//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <fstream>
#include <sstream>
//#include <time.h>
//#include <random>

using namespace std;


int main()
{
	map <string, int> m;
	std::fstream fs("text.txt", fstream::in);
	string t;
	while (!fs.eof()) {
		getline(fs, t);
		stringstream s(ios_base::in | ios_base::out);
		// s.str("")
		//s.clear();
		//cout << s.str() << endl;
		s << t;
		string name;
		string secname;
		s >> name;
		s >> secname;
		int sm = 0;
		while (!s.eof()) {
			int a;
			s >> a;
			sm += a;
		}
		m[name + secname] += sm;
	}
	for (auto a : m)
		cout << a.first << " " << a.second << endl;
	fs.close();
}
