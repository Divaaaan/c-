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
#include <bitset>
//#include <time.h>
//#include <random>

using namespace std;


int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int n, lenSq;
	cin >> n;
	lenSq = sqrt(n) + 1;
	vector <long long int> s(n);
	vector <long long int> sq(lenSq);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sq[i / lenSq] += s[i];
	}
	int n_test;
	cin >> n_test;
	for (int j = 0; j < n_test; j++)
	{
		char ch;
		cin >> ch;
		if (ch == 's') {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			long long int sm;
			sm = 0;
			if (l / lenSq != r / lenSq) {
				for (int i = l / lenSq + 1; i <= r / lenSq - 1; i++) {
					sm += sq[i];
				}
				for (int i = l; i < (l / lenSq + 1) * lenSq; i++)
				{
					sm += s[i];
				}
				for (int i = (r / lenSq) * lenSq; i <= r; i++)
				{
					sm += s[i];
				}
			}
			else {
				for (int i = l; i < r + 1; i++)
				{
					sm += s[i];
				}
			}
			cout << sm << ' ';
		}
		else {
			int e;
			int e_num;
			cin >> e;
			e--;
			cin >> e_num;
			int dif;
			dif = e_num - s[e];
			sq[e / lenSq] += dif;
			s[e] = e_num;
		}
	}
}
