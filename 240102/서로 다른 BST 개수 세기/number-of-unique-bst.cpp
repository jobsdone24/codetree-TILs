#include<iostream>
using namespace std;
int main() {
	int tree[20] = { 0 };
	int n;
	cin >> n;

	tree[0] = 1;
	tree[1] = 1;
	tree[2] = 2;
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			tree[i] += tree[j] * tree[i -1 -j];
		}
	}
	cout << tree[n];
}