#include<iostream>
#include<set>
#include<climits>
#define MAX_N 100000

using namespace std;

int num[MAX_N+1];
int main() {
	int n, m;
	cin >> n >> m;
	
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		s.insert(num[i]);
	}
	//m보다 크거나 작은 수 확인하기

	int small = INT_MAX;
	for (int i = 0; i < n; i++) {
		int number = num[i];
		int pn = num[i] + m;
		int mn = num[i] - m;
		// pn, mn은 범위를 넘지 않는다.
		
		if (s.lower_bound(pn) != s.end()) {
			int temp = *s.lower_bound(pn);
			int gap = temp - number;
			if (gap >= m && small > gap) small = gap;
		}

		if (s.lower_bound(mn) != s.end()) {
			if (s.lower_bound(mn) != s.begin()) {
				auto iter = s.lower_bound(mn);
				iter--;
				int temp = *iter;
				int gap = number - temp;
				if (gap >= m && small > gap) small = gap;
			}
		}
	}
	cout << small;
	return 0;
}