#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<climits>
#define MAX_N 10000
using namespace std;

int numcnt[MAX_N + 1];

int main() {
	int n;
	priority_queue<int> pq;

	vector<int> v;
	cin >> n;
	int hap = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		hap += num;
		numcnt[num]++;
		pq.push(-num);
		v.push_back(num);
	}

	double big = 0;
	
	for (int i = 0; i < n - 2; i++) {
		int num = v[i];
		hap -= num;
		numcnt[num]--;

		int thap = hap;
		while (!pq.empty()) {
			int tmp = -pq.top();
			pq.pop();
			if (numcnt[tmp] != 0) {
				thap -= tmp;
				double solv = 1.0 * thap / (n - i - 2);
				if (solv > big) big = solv;
				pq.push(-tmp);
				break;
			}
		}
	}
	printf("%.2f", big);
}