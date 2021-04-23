#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

int n;
vector <int> s;

pair <int, int> solve(int l, int r) {
	// l = r.
	bool f; // 1 - первый, 0 - второй
	int first = 0, sec = 0;
	if (n % 2) {
		sec += s[l];
		if (l != 0)
			l--;
		if (r != s.size() - 1)
			r++;
		f = 0;
	}
	else {
		first += s[l];
		sec += s[l];
		if (l != 0)
			l--;
		if (r != s.size() - 1)
			r++;
		f = 1;
	}
	while (l != 0 && r != n - 1) {
		if (f) {
			int mx;
			if (s[r] > s[l] && r != n - 1) {
				first += s[r];
				r++;
			}
			else {
				if (l != 0) {
					first += s[l];
					l--;
				}
			}
		}
		else {
			int mx;
			if (s[r] > s[l] && r != n - 1) {
				sec += s[r];
				r++;
			}
			else {
				if (l != 0) {
					sec += s[l];
					l--;
				}
			}
		}
	}
	if (first > sec) {
		return  { 1, first };
	}
	else {
		return { 2, sec };
	}
}

int main() {
	int mx_1 = 0, mx_2 = 0;
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n; i++)
	{
		pair <int, int> a;
		a = solve(i, i);
		if (a.first == 1) {
			mx_1 = max(mx_1, a.second);
		}
		else {
			mx_2 = max(mx_2, a.second);
		}
	}
	if (mx_1 == mx_2) {
		cout << 0;
	}
	else
	{
		if (mx_1 > mx_2) {
			cout << 1 << ' ' << mx_1;
		}
		else {
			cout << 2 << ' ' << mx_2;
		}
	}
}
