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
#include <queue>
//#include <fstream>
//#include <sstream>
//#include <bitset>
//#include <time.h>
//#include <random>

using namespace std;

vector <vector<pair<int, int>>> g;
vector <char> u;
vector <int> p;
vector <int> d;
int inf = 2009000999;
set<pair<int, int>> q;

void alg(int start) {
	d[start] = 0;
	q.insert({ d[start],  start });
	while (!q.empty()) {
		int v;
		v = q.begin()->second;
		q.erase(q.begin());
		for (auto j : g[v]) {
			int to;
			to = j.first;
			int len;
			len = j.second;
			if (d[v] + len < d[to]) {
				q.erase({ d[to], to });
				d[to] = d[v] + len;
				p[to] = v;
				q.insert({ d[to], to });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m, s;
	cin >> n >> m >> s;
	g.resize(n, vector<pair<int, int>> ());
	p.resize(n);
	d.resize(n, inf);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b, c });
		g[b].push_back({ a,c });
	}
	alg(s);
	for (auto i : d) {
		cout << i << ' ';
	}
}
