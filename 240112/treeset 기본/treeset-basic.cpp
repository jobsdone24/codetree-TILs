#include<iostream>
#include<set>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	set<int> s;
	for (int i = 0; i < n; i++) {
		char arr[15];
		cin >> arr;
		if (arr[0] == 'a') {
			int x;
			cin >> x;

			if (s.find(x) == s.end()) s.insert(x);
		}
		else if (arr[0] == 'r') {
			int x;
			cin >> x;
			s.erase(x);
		}
		else if (arr[0] == 'f') {
			int x;
			cin >> x;

			if (s.find(x) == s.end()) cout << "false\n";
			else cout << "true\n";
		}
		else if (arr[0] == 'l'&&arr[1]=='o') {
			int x;
			cin >> x;

			if (s.lower_bound(x) != s.end()) cout << *(s.lower_bound(x)) << "\n";
			else cout << "None\n";
		}
		else if (arr[0] == 'u') {


			int x;
			cin >> x;

			if (s.upper_bound(x) != s.end()) cout << *(s.upper_bound(x)) << "\n";
			else cout << "None\n";
		}
		else if (arr[0] == 'l') {
	

			if (s.rbegin() !=s.rend()) cout << *(s.rbegin()) << "\n";
			else cout << "None\n";
		}
		else if (arr[0] == 's') {

			if (s.rbegin() != s.rend()) cout << *(s.begin()) << "\n";
			else cout << "None\n";
		}
	}

}