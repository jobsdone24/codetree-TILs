#include<iostream>
#include<string.h>
#include<queue>
#define MAX_N 100
using namespace std;
int n;
int map[MAX_N + 3][MAX_N + 3];
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };

bool visited[MAX_N + 1][MAX_N + 1] = {};
bool bfs(int Y,int X,int k) {
	int cnt = 0;
	queue<pair<int,int> > q;
	q.push({Y,X});
	visited[Y][X] = true;
	int target = n * n;
	if (target % 2 == 1) target = target / 2 + 1;
	else target = target / 2;

	while (!q.empty()) {
	
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		if (target <= cnt)break;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
			if (abs(map[ny][nx] - map[y][x]) <= k) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
	return cnt >= target;
}

bool ispossible(int dist) {
	//dist를 통해 탐색이 가능한지 여부 확인하기
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				if (bfs(i, j, dist)) return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int left = 0;
	int right = 1000000;
	int dap = 1000000;
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