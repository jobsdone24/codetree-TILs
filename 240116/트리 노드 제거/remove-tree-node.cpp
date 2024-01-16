#include<iostream>
#include<vector>
#define MAX_N 50
using namespace std;

vector<int> edge[MAX_N + 1];
bool visited[MAX_N + 1];
int cnt;

void Traversal(int num) {
	int size = (int)edge[num].size();
	bool check = false;
	for (int i = 0; i < size; i++) {
		int next = edge[num][i]; // 부모 num, 자식 next
		if (visited[next] == false) {
			visited[next] = true;
			Traversal(next);
			check = true;
		}
	}
	if (check == false) cnt++;
	
}

int main() {
	int n;
	cin >> n;
	int root = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == -1) root = i;	
		else edge[num].push_back(i);
	}

	int dnum;
	cin >> dnum;

	edge[dnum].clear();
	visited[dnum] = true;
	if (root == dnum) cout << 0;
	else {
		visited[root] = true;
		Traversal(root);
		cout << cnt;
	}
}