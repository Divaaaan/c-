#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<vector<pair<int, int>>> dp[2];

pair<int, int> rec(int l, int r, int p)
{
	pair<int, int> ans;
	if (dp[p][l][r].first != -1)
		return dp[p][l][r];
	if (l == r)
	{
		if (p == 0)
			ans = { v[l], 0 };
		else
			ans = { 0, v[l] };
		dp[p][l][r] = ans;
		return ans;
	}
	auto vl = rec(l + 1, r, (p + 1) % 2);	
	auto vr = rec(l, r - 1, (p + 1) % 2);
	if (p == 0)
		if (v[l] + vl.first > v[r] + vr.first)
			ans = { v[l] + vl.first, vl.second };
		else
			ans = { v[r] + vr.first, vr.second };
	else
		if (v[l] + vl.second > v[r] + vr.second)
			ans = {vl.first, v[l] + vl.second };
		else
			ans = { vr.first, v[r] + vr.second };
	dp[p][l][r] = ans;
	return ans;
}

int main()
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dp[0].resize(n, vector<pair<int, int>>(n, {-1, -1}));
	dp[1].resize(n, vector<pair<int, int>>(n, {-1, -1 }));
	auto e = rec(0, n - 1, 0);
	if (e.first > e.second)
		cout << 1;
	else if (e.first == e.second)
		cout << 0;
	else
		cout << 2;
}
