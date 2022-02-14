#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define For(i,s,n) for(ll i = s;i <= n;i++)
#define repi(n) for (int i = 0; i < n; i++)
#define repj(n) for (int j = 0; j < n; j++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define t_cases ll t; cin >> t; while(t--)
#define debug(a) cout << a << "\n"

using namespace std;

string add_num_string(string e, string f) {
	string a, b;
	if (e.empty()) return f;
	else if (f.empty()) return e;
	else if (e.length() < f.length()) {a = f; b = e;}
	else {a = e; b = f;}
	int i = b.length() - 1, j = a.length() - 1, c = 0;
	while (i >= 0) {
		int c1 = (a[j] + b[i] + c - 96) / 10;
		a[j] = (a[j] + b[i] - 96 + c) % 10 + 48;
		c = c1;
		i--; j--;
	}
	while (j >= 0 and c > 0) {
		int c1 = (a[j] + c - 48) / 10;
		a[j] = (a[j] - 48 + c) % 10 + 48;
		c = c1;
		j--;
	}
	if (c > 0 and j < 0) a = "1" + a;
	return a;
}

bool comp_num_string(string a, string b) {
	if (a.length() != b.length()) return a.length() > b.length();
	else {
		int i = 0;
		while (a[i] == b[i] and i < a.length()) i++;
		if (i > a.length()) return false;
		else {
			return a[i] > b[i];
		}
	}
}