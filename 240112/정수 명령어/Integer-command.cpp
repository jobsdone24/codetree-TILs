#include<iostream>
#include<set>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		set<int> s;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			char arr[2];
			cin >> arr;

			if (arr[0] == 'I') {
				int x;
				cin >> x;
				s.insert(x);
			}

			else if (arr[0] == 'D') {
				int x;
				cin >> x;
				if (x == -1) {
					if (s.end() != s.begin()) {
						int num = *s.begin();
						s.erase(num);
					}
				}
				else {
					if (s.end() != s.begin()) {
						int num = *s.rbegin();
						s.erase(num);
					}
				}
			}
		}
		if (s.end() == s.begin()) cout << "EMPTY\n";
		else {
			cout << *(s.rbegin()) << " " << *(s.begin()) << "\n";

		}
	}
}