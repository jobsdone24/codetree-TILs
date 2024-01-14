#include<iostream>
#include<set>
using namespace std;

int main() {
	long long n,t;
	set<long long> s;

	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		long long x, v;
		cin >> x >> v;

		long long target = x + v * t;
		while (1) {
			//더이상 없앨 것이 없을 때
			if (s.lower_bound(target) == s.end()) {
				break;
			}
			else {
				auto it = s.lower_bound(target);
				s.erase(it);
			}
		}
		s.insert(target);
	}
	cout << s.size();

}