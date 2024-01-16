#include<iostream>
#include<vector>
#define MAX_M 1000
#define MAX_N 10000
using namespace std;

vector<int> edge[MAX_N + 1];
bool visited[MAX_N + 1];
bool gameover;

int root = 0;
bool nodecnt[MAX_N + 1]; //노드의 개수를 새기
int totalcnt; //총 노드 개수
int deg[MAX_N + 1];


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
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		nodecnt[a] = nodecnt[b] = true;
		deg[b]++;
	}

	//루트가 여러개인 경우
	for (int i = 1; i <= MAX_N; i++) {
		if (nodecnt[i] && deg[i] == 0) {
			if(root ==0) root = i;
			else {
				gameover = true;
				break;
			}
		}
	}

	//루트가 없는 경우
	if (root == 0) gameover = true;

	if (gameover == true)cout << 0;
	else {
		//루트노드 방문 처리했을때 visited한곳에 또 간다면 out
		visited[root] = true;
		Traversal(root);

		if (gameover == true )cout << 0;
		else cout << 1;
	}
}