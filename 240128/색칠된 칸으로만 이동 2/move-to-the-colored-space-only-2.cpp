#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<tuple>
#define MAX_N 100
using namespace std;
int n, m;
int map[MAX_N + 3][MAX_N + 3];
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };
vector<pair<int, int>> v;
bool visited[MAX_N + 1][MAX_N + 1] = {};

void bfs(int Y, int X, int k) {
	queue<pair<int, int> > q;
	q.push({ Y,X });
	visited[Y][X] = true;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
			if (abs(map[ny][nx] - map[y][x]) <= k) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

bool ispossible(int dist) {
	//dist를 통해 탐색이 가능한지 여부 확인하기

	memset(visited, 0, sizeof(visited));
	int y, x;
	tie(y, x) = v[0];
	bfs(y, x, dist);
	for (auto nxt : v) {
		if (visited[nxt.first][nxt.second] == false)return false;
	}
	return true;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (num == 1) v.push_back({ i,j });
		}
	}

	int left = 0;
	int right = 1000000000;
	int dap = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (ispossible(mid)) {
			right = mid - 1;
			dap = min(dap, mid);
		}
		else left = mid + 1;
	}
	cout << dap;
}