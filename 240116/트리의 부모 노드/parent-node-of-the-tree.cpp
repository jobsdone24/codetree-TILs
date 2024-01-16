#include<iostream>
#include<vector>
#define MAX_N 100000
using namespace std;

vector<int> tree[MAX_N + 1];
int parent[MAX_N + 1];
bool visited[MAX_N + 1];

void Traversal(int num) {
	for (int i = 0; i < (int)tree[num].size(); i++) {
		int next = tree[num][i]; // 부모 num, 자식 next
		if (visited[next] == false) {
			visited[next] = true;
			parent[next] = num; //next의 부모는 num이다.
			Traversal(next);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	//루트노드 방문 처리
	visited[1] = true;
	Traversal(1);

	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";

}