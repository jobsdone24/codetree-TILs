#include<iostream>
#define MAX_N 200'000
using namespace std;

int lnode[MAX_N + 1];
int rnode[MAX_N + 1];
int ans;

void DFS(int x, long long num) {
	if (lnode[x] == -1 && rnode[x] == -1) {
		ans = x;
		return;
	}

	if (lnode[x] == -1) DFS(rnode[x], num);
	else if (rnode[x] == -1) DFS(lnode[x], num);
	else if (num % 2 == 0) DFS(rnode[x], num / 2);
	else DFS(lnode[x], (num) / 2);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lnode[i] >> rnode[i];
	}
	long long k;
	cin >> k;
	DFS(1, k);
	cout << ans;
}