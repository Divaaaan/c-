#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;



int main()
{
	vector <int> a;
	a.push_back(1);
	vector <int> b(10, 7);
	a.resize(14, 8); // добавление (размер нового, чем(новые элементы))
	a.resize(10); // удаление с конца 
	a.assign(18, 8); // (размер нового, чем(все элементы))
	a.size();
	a.clear();
	a.back(); // последний эл.
	a.front(); // первый 
	//a.erase()
	//a[i]
	for (auto it = a.begin(); it != a.end(); it++) {
		cout << *it;
	}
	for (auto e : a) {
		cout << e;
	}
	a.pop_back();
	a.erase(a.begin());//del (указатель 1, [последний])
	//a.insert()
}
