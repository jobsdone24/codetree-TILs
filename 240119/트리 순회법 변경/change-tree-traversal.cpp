#include <iostream>
#define MAX_N 10000

using namespace std;

// 변수 선언
int n;
int preorder[MAX_N + 1], postorder[MAX_N + 1];
int cnt = 1;

void DFS(int l, int r) {
	if (l > r) return;
	if (l == r){
		postorder[cnt++] = preorder[l];
		return;
	}
	int right_tree = r + 1;
	for (int i = l + 1; i <= r; i++) {
		if (preorder[l] < preorder[i]) {
			right_tree = i;
			break;
		}
	}

	DFS(l + 1, right_tree - 1);
	DFS(right_tree, r);
	postorder[cnt++] = preorder[l];
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> preorder[i];

	DFS(1, n);
	for (int i = 1; i <= n; i++) {
		cout << postorder[i] << "\n";
	}
	return 0;
}