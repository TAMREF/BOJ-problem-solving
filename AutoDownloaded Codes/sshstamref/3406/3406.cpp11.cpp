#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool die(string s) {
	s += "0";
	int n = s.size();
	int l = (n & -n);
	int cnt = n / l;
	for (int i = 1; i < cnt; ++i) {
		for (int k = 0; k < l-1; ++k) {
			if (s[i*l+k] != s[i*l-2-k]) return false;
		}
		if (s[i*l-1] != '0') return false;
	}
	return true;
}

int main() {
	int n;
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		if (die(s)) cout << "DIES" << '\n';
		else cout << "LIVES" << '\n';
	}
}
