#include<iostream>
#include<set>
#include<tuple>
using namespace std;
set<long long> s;

int main() {
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		long long x,v;
		cin >> x >> v;
		long long target = x + v*T;
		while(1){
			auto iter = s.lower_bound(target);
			if(iter == s.end())break;
			else s.erase(iter);
		}
		s.insert(target);
	}
	cout << s.size();
}