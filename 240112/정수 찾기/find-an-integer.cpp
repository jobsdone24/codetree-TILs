#include<iostream>
#include<unordered_set>
#define MAX_N 100000
using namespace std;


int main() {
	unordered_set<int> s;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (s.find(num) == s.end()) {
			cout << "0\n";
		}
		else cout << "1\n";
	}


}