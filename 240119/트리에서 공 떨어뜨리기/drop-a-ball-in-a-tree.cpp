#include<iostream>
#define MAX_N 200'000
using namespace std;

int lnode[MAX_N + 1];
int rnode[MAX_N + 1];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lnode[i] >> rnode[i];
	}
	long long k;
	cin >> k;
	int cur = 1;
	while (k) {
		// 리프노드인 경우
		if (lnode[cur] == -1 && rnode[cur] == -1) {
			cout << cur;
			break;
		}
		else if (lnode[cur] == -1) cur = rnode[cur];
		else if (rnode[cur] == -1)cur = lnode[cur];
		else {
			//두개 다 있는 경우
			if (k % 2 == 0)cur = rnode[cur];
			else cur = lnode[cur];

			k = (k+1)/2;
		}
	}
}