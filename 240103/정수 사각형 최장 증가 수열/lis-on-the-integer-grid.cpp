/*
방법 1 tabulation
	작은 것 부터 크게 가기
	key point -> 정렬시키기

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int N;
int dp[103][103] = { 0 };
void show() {
	int big = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (big < dp[i][j]) big = dp[i][j];
		}
	}
	cout << big;
}

int main() {
	int map[103][103] = { 0 };
	int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };

	cin >> N;
	
	vector<tuple<int, int, int>> kan;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			kan.push_back({ map[i][j],i,j });
			
			//dp 초기화
			dp[i][j] = 1;
		}
	}
	
	//정렬
	sort(kan.begin(), kan.end());

	//작은 수 부터 주변 4방향 확인후 1씩 올리기
	for (int i = 0; i < kan.size(); i++) {
		int y, x;
		tie(ignore, y, x) = kan[i];
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (map[ny][nx] > map[y][x]) {
				dp[ny][nx] = max(dp[ny][nx], dp[y][x] + 1);
			}
		}
	}
	show();
}