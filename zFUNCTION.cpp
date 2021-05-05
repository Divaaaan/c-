#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void z_func(string& s, vector<int>& z)
{
	int n = s.size();
	z.assign(n, 0);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
	{
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);
		for (int j = i + z[i]; j < n && s[j] == s[j - i]; j++)
			z[i]++;
		if (r < i + z[i] - 1)
			l = i, r = i + z[i] - 1;
	}
}
//0 1 2 3 4 5 6 7 8 9
//a b a b c a b a b a
//0 0 3 0 0 4 0 2
//          l     r

int main() {
	int c = 0;
	string s, t;
	getline(cin, s);
	vector<int> z;
	z_func(s, z);
	for (int i =0; i < s.size(); i++)
	    cout  << z[i] << " ";
}
