#include<iostream>
#include<math.h>
using namespace std;

int N;
int dp[503][503] = { 0 };
int map[503][503] = { 0 };
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };

int find(int Y, int X) {
	//만약 값이 정해졌다면
	if (dp[Y][X] == -1) {
		return dp[Y][X];
	}
	else {
		//자기 자신 초기화
		int best = 1;
	
		for (int i = 0; i < 4; i++) {
			int ny = Y + dy[i];
			int nx = X + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (map[ny][nx] > map[Y][X]) {
				best = max(best, find(ny, nx) + 1);
			}
		}
		return dp[Y][X] = best;
	}
}



int main() {
	int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, find(i, j));
		}
	}
	cout << ans;
}