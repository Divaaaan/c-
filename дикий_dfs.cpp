#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int dfs(int s, vector <char>& used, vector <int>& pr, vector<vector<int>> g) {
	pr[s] = 0;
	used[s] = true;
	for (auto r : g[s]) {
		if (!used[r]) {
			pr[s] = max(pr[s], dfs(r, used, pr, g) + 1);
		}
	}
	return pr[s];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector <vector<int>> g(1e5);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n_day;
		cin >> n_day;
		for (int j = 0; j < n_day; j++) {
			int a;
			cin >> a;
			g[a - 1].push_back(i);
		}
	}

	vector <vector<int>> s(n);
	for (int i = 0; i < 1e5; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			for (int t = j + 1; t < g[i].size(); t++) {
				s[g[i][j]].push_back(g[i][t]);
			}
		}
	}
	vector <char> used(n);
	vector <int> pr(n, -1);
	for (int i = 0; i < n; i++)
		dfs(i, used, pr, s);
	int mx = 0;
	for (auto i : pr) {
		mx = max(mx, i);
	}
	cout << mx + 1;
}
