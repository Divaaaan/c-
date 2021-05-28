#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <deque>
#include <fstream>
#include <map>
#include <sstream>
#include <queue>

using namespace std;

vector <int> s;
vector <pair<int, int>> t;



int mx(int i, int tl, int tr, int l, int r, int izm) {
	if (i < t.size()) {
		t[i].first += izm;
		t[i].second += izm;
	}
	if (l > r) {
		return -1000000000;
	}
	if (tl == l && tr == r) {
		return t[i].first;
	}
	int tm = (tl + tr) / 2;
	int izm_2 = t[i].second;
	t[i].second = 0;
	return max(mx(i * 2 + 1, tl, tm, l, min(tm, r), izm_2), mx(i * 2 + 2, tm + 1, tr, max(tm + 1, l),  r, izm_2));

}

void update(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return;
	}
	if (tl == l && tr == r) {
		t[v].first++;
		t[v].second++;
	}
	else {
		int tm = (tl + tr) / 2;
		update(v * 2 + 1, tl, tm, l, min(tm, r));
		update(v * 2 + 2, tm + 1, tr, max(tm + 1, l), r);
		t[v].first = max(t[v * 2 + 1].first, t[v * 2 + 2].first);
	}
}

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	t.resize(n * 4);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		if (mx(0, 0, n - 1, l, r - 1, 0) >= k) {
			cout << "No" << endl;
			continue;
		}
		update(0, 0, n - 1, l, r - 1);
		cout << "Yes" << endl;
	}
}
