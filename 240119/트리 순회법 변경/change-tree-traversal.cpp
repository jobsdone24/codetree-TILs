#include<iostream>
#include<unordered_map>
#define MAX_N 10'000
using namespace std;

unordered_map<int, int> lnode;
unordered_map<int, int> rnode;
int n;
int a[MAX_N + 1];

void postorder(int x) {
	if (x == 0)return;
	postorder(lnode[x]);
	postorder(rnode[x]);
	cout << x << "\n";

}
void check(int start, int end) {
	if (start >= end) return;
	bool flag = false;
	for (int i = start + 1; i <= end; i++) {
		if (a[start] < a[i]) {
			//큰 것
			check(i, end);
			rnode[a[start]] = a[i];
			//작은 것
			check(start + 1, i - 1);
			if (start + 1 <= i - 1) lnode[a[start]] = a[start + 1];
			flag = true;
			return;
		}
	}
	if (flag == false) {
		lnode[a[start]] = a[start + 1];
		check(start + 1, end);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	check(1, n);
	postorder(a[1]);
}