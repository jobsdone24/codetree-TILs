#include<iostream>
#include<vector>
#include<unordered_map> 
#define MAX_N 1000
using namespace std;

vector<int> edge[MAX_N + 1];
int node[MAX_N + 1];
unordered_map<int, int> d;
int depthcnt[11];

bool visited[MAX_N + 1];

void traversal(int x, int depth) {
	for (int i = 0; i < (int)edge[x].size(); i++) {
		int next = edge[x][i];
		d[next] = depth;
		depthcnt[depth]++;
		if (visited[next] == false) {
			visited[next] = true;
			traversal(next, depth + 1);
		}
	}
}

int main() {
	int n, k;
	int parent[MAX_N + 1] = { 0 };
	int finding_node;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> node[i];
		if (k == node[i]) finding_node = i;
	}

	//트리 만들기
	int idx = 0;
	for (int i = 1; i < n - 1; i++) {
		if (node[i] + 1 == node[i + 1]) {
			int si = i;
			while (node[si] + 1 == node[si + 1]) {
				edge[idx].push_back(si);
				si++;
				parent[si] = idx;
			}
			edge[idx].push_back(si);
			parent[si] = idx;
			i = si;
			idx++;
		}
		else {
			edge[idx].push_back(i);
			parent[i] = idx;
			idx++;
		}
	}

	if (node[n - 2] + 1 != node[n - 1]) {
		edge[idx].push_back(n - 1);
		parent[n - 1] = idx;
	}

	// 트리 깊이 확하기
	visited[0] = true;
	depthcnt[0] = 1;
	d[0] = 0;
	traversal(0, 1);
	
	int kpar = parent[finding_node];
	int size = edge[kpar].size();
	int dnum = d[finding_node];
	cout << depthcnt[dnum] - size;
}