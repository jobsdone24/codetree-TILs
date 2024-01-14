#include<iostream>
#include<set>
#define MAX_N 100000
using namespace std;

pair<int, int> saving[MAX_N];
int n, m;
int main() {
	cin >> n >> m;

	set<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		s.insert({ a,b });
	}

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		if (s.lower_bound({ k,0 }) == s.end()) {
			cout << "-1 -1\n";
		}
		else {
			auto iter = s.lower_bound({ k,0 });
			cout << iter->first << " " << iter->second << "\n";
			s.erase(*iter);
		}
	}

}