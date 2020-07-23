#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

int main() {
	vector<int> v1 = { 1, 2, 2, 4, 5 };
	shuffle(v1.begin(), v1.end(), default_random_engine(time(0)));
	for (auto i : v1)
		cout << i << " ";
	cout << endl;
	sort(v1.begin(), v1.end());
	for (auto i : v1)
		cout << i << " ";
}