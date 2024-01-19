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
	int k;
	cin >> k;
	int cur = 1;
	while (k) {
		// 리프노드인 경우
		if (lnode[cur] == -1 && rnode[cur] == -1) {
			cout << cur;
			break;
		}
		else if (lnode[cur] == -1) cur = cur * 2 + 1;
		else if (rnode[cur] == -1)cur = cur * 2;
		else {
			//두개 다 있는 경우
			if (k % 2 == 0)cur = cur * 2 + 1;
			else cur = cur * 2;

			k /= 2;
		}
	}
}