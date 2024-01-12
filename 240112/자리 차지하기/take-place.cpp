#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<int> s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int ans = 0;
	bool flag = false;
	for (int i = 0; i < v.size(); i++) {
		int num = v[i];
		if (flag) break;
		//해당 수( 가능한 제일 큰수)가 없을 때
		if (s.find(num) == s.end()) {
			s.insert(num);
			ans++;
		}
		else {
		//해당 수가 있을 때
			auto iter = s.lower_bound(num);
			while (1) {
				if (iter == s.begin()) {
					flag = true;
					break;
				}
				iter--;
				if (s.find(*(iter)) == s.end()) {
					ans++;
					s.insert(*iter);
					break;
				}
			}
		}
	}
	cout << ans;
}