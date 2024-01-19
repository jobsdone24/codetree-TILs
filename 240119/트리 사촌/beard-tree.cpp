#include<iostream>
#include<vector>
#define MAX_N 1000
using namespace std;
int node[MAX_N + 1];
int parent[MAX_N + 1];

int main() {
	int n, k;
	int finding_node;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> node[i];
		if (k == node[i]) finding_node = i;
	}

	//트리 만들기
	int idx = 0;
	for (int i = 2; i <= n; i++) {
		if (node[i] > node[i - 1] + 1) idx++;
		parent[i] = idx;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!parent[parent[i]] || !parent[parent[finding_node]]) continue;
		if (parent[i] != parent[finding_node] && parent[parent[i]] == parent[parent[finding_node]]) ans++;
	}
	cout << ans;
}