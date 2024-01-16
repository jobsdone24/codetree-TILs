#include<iostream>
#include<vector>
#define MAX_M 1000
#define MAX_N 10000
using namespace std;

vector<int> edge[MAX_N + 1];
bool visited[MAX_N + 1];
bool gameover;
int parent[MAX_N + 1];

void Traversal(int num) {
	if (gameover)return;
	for (int i = 0; i < (int)edge[num].size(); i++) {
		int next = edge[num][i]; // 부모 num, 자식 next
		if (visited[next] == false) {
			visited[next] = true;
			Traversal(next);
		}
		else {
			gameover = true;
			break;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	int last;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		parent[b] = a;
		last = b;
	}
	int root = 0;
	// 루트 노드 찾기
	while (1) {
		int p = parent[last];
		if (p == 0) {
			root = last;
			break;
		}
		last = p;
	}

	//루트노드 방문 처리했을때 visited한곳에 또 간다면 out
	visited[root] = true;
	Traversal(root);

	if (gameover == true)cout << 0;
	else cout << 1;
}