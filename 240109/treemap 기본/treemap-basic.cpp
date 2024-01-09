#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		string order;
		cin >> order;
		if (order[0] == 'a') {
			int k, v;
			cin >> k >> v;
			m[k] = v;
		}
		else if (order[0] == 'r') {
			int k;
			cin >> k;
			m.erase(k);
		}
		else if (order[0] == 'f') {
			int k;
			cin >> k;
			if (m.find(k) != m.end())cout << m[k] << "\n";
			else cout << "None\n";
		}
		else {
			if (m.empty())cout << "None\n";
			else {
				for (auto it = m.begin(); it != m.end(); it++) {
					cout << it->second << " ";
				}cout << "\n";
			}
		}
	}

}