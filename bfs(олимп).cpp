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

vector <vector<int>> g;
int n;
vector<bool> used;
vector<int> d;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	used.clear();
	d.clear();
	used.resize(n, false);
	d.resize(n);
	used[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
			}
		}
	}
}


int main() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		bfs(i);
		ans += d[i + 1];
	}
	bfs(n - 1);
	ans += d[0];
	cout << ans;
}
