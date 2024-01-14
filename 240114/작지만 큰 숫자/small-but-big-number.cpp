#include<iostream>
#include<set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	set<int> s;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		auto iter = s.upper_bound(num);
		
		if (iter ==s.end() && s.size()>0) {
			iter--;
			cout << *iter << "\n";
			s.erase(*iter);
		
		}
		else if (iter == s.end() || iter == s.begin()) {
			cout << -1 << "\n";
		}
		else {
			iter--;
			cout << *iter << "\n";
			s.erase(*iter);
		}
	}
}