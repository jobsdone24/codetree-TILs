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
	unordered_map<int, int> changer;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> node[i];
		changer[node[i]] = i;
	}

	//트리 만들기
	int idx = 0; //자식으로 달아햐 할 크기
	for (int i = 1; i < n - 1; i++) {
		int par = idx;
		if (node[i] + 1 == node[i + 1]) {
			int si = i;
			while (node[si] + 1 == node[si + 1]) {
				edge[par].push_back(si);
				si++;
				parent[si] = par;
			}
			edge[par].push_back(si);
			parent[si] = par;
			i = si;
			idx++;
		}
		else {
			edge[par].push_back(i);
			parent[i] = par;
			idx++;
		}
	}

	if (node[n - 2] + 1 != node[n - 1]) {
		int par = idx;
		edge[par].push_back(n - 1);
		parent[n - 1] = par;
	}

	// 트리 깊이 확하기
	visited[0] = true;
	depthcnt[0] = 1;
	d[0] = 0;
	traversal(0, 1);

	k = changer[k];
	int kpar = parent[k];
	int size = edge[kpar].size();
	int dnum = d[k];
	cout << depthcnt[dnum] - size;
}