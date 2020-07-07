#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

string str_(string& a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'A') {
			a[i] = 'Z';
		}
		else {
			a[i] --;
		}
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	string* s = new string[n];
	int* s2 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s2[i] = 0;
	}
	int n_f;
	cin >> n_f;
	for (int i = 0; i < n_f; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++) {
			if (a.size() == s[j].size()) {
				int num_of_fail = 0;
				for (int t = 0; t < s[j].size(); t++) {
					if (s[j][t] != a[t]) {
						num_of_fail++;
					}
				}
				if (num_of_fail == 1) {
					s2[j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << s2[i] << " ";
	}
}
