#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

vector <int> s;
vector <int> t;

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	while (b != 0) {
		int e = b;
		b = a % b;
		a = e;
	}
	return a;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = s[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(v * 2 + 1, tl, tm);
		build(v * 2 + 2, tm + 1, tr);
		t[v] = gcd(t[v * 2 + 1], t[v * 2 + 2]);
	}
}


int big_gcd(int l, int r, int v, int tl, int tr) {
	if (l > r) {
		return 0;
	}
	if (l == tl && r == tr) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return gcd(big_gcd(l, min(tm, r), v * 2 + 1, tl, tm), big_gcd(max(tm + 1, l), r, v * 2 + 2, tm + 1, tr));
}

void update(int i, int val, int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (i <= tm) {
		update(i, val, v * 2 + 1, tl, tm);
	}
	else {
		update(i, val, v * 2 + 2, tm + 1, tr);
	}
	t[v] = gcd(t[v * 2 + 1], t[v * 2 + 2]);
}

int main() {
	int n;
	cin >> n;
	s.resize(n);
	t.resize(n * 4);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	build(0, 0, n - 1);
	int m;
	char mode;
	int a, b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> mode >> a >> b;
		if (mode == 'g') {
			cout << big_gcd(a - 1, b - 1, 0, 0, n - 1) << ' ';
		}
		else {
			update(a - 1, b, 0, 0, n - 1);
		}
	}
}
