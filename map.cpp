#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<map>

using namespace std;

int main()
{
	pair<int, string> a;
	a.first = 3;
	a.second = "123";
	map<int, string> e;
	e[5] = "123";
	cout << e[0];
	e.insert(a);
	e.insert({ 8, "qwe" });
	e.insert(pair<int,string>(5, "qwe"));
	e.insert(pair<int, string>{5, "qwe"});
	e.insert(make_pair(1, "xaf"));
	cout << endl;
	for (auto it = e.begin(); it != e.end(); it++)
	{
		cout << it->second << " ";
	}
	cout << endl;
	for (auto x : e)
	{
		cout << x.second;
	}
	cout << endl;
	for (auto it = e.begin(); it != e.end(); it++)
	{
		if (it->second == "qwe")
		{
			it--;
			auto tmp = it;
			it++;
			e.erase(it);
			it = tmp;
		}
	}
}
