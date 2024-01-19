#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<int> s;
int test(int x) {
	int num = x;
	while (num != 1) {
		num /= 2;
		if (s.find(num) != s.end()) return num;
	}
	return 0;
}
int main() {
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		int t = test(num);
		if (t == 0) s.insert(num);
		cout << t<<'\n';
	}
}