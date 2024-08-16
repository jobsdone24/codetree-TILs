#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int R, C;
int K;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct gol {
	int x, y;
	int d;		//북동남서//
};
struct gol gol[1005];

int map[75][75];

//n번 골렘이 d방향으로
//1 오른쪽 2 아래 3 왼쪽
void move(int n, int d) {

	//현재 위치//
	int x = gol[n].x;
	int y = gol[n].y;

	//초기화//
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		map[nx][ny] = 0;
	}

	//이동//
	gol[n].x += dx[d];
	gol[n].y += dy[d];
	
	x = gol[n].x;
	y = gol[n].y;

	//맵에 표시
	map[x][y] = n;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		map[nx][ny] = n;
	}

	//방향 회전//
	if (d == 1) {
		gol[n].d += 1;
		gol[n].d %= 4;
	}
	else if (d == 3) {
		gol[n].d += 3;
		gol[n].d %= 4;
	}

	return;
}

//n번 골룸의 이동//
//이동 성공 1//
int go(int n) {

	//위치//
	int x = gol[n].x;
	int y = gol[n].y;

	if (x + 1 == R) return 0;	//마지막일때//

	//전진 가능 할때//
	if (x + 2 <= R && map[x + 2][y] == 0 && map[x + 1][y - 1] == 0 && map[x + 1][y + 1] == 0) {
		move(n, 2);		//아래로 이동//
		return 1;
	}

	//왼쪽 이동 가능//
	else if (y - 2 > 0 && map[x][y - 2] == 0 && map[x - 1][y - 1] == 0 && map[x + 1][y - 1] == 0 && map[x + 1][y - 2] == 0 && map[x + 2][y - 1] == 0) {
		move(n, 3);
		return 1;
	}

	//오른쪽 이동 가능//
	else if (y + 2 <= C && map[x][y + 2] == 0 && map[x - 1][y + 2] == 0 && map[x + 1][y + 1] == 0 && map[x + 1][y + 2] == 0 && map[x + 2][y + 1] == 0) {
		move(n, 1);
		return 1;
	}

	else return 0;
}

//성공하면 1 실패하면 0//
int gol_go(int n) {

	while (1) {
		int ans = go(n);
		if (ans == 0) break;
	}

	if (gol[n].x >= 1) return 1;
	else return 0;
}
void show() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

}
void reset_map() {
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			map[i][j] = 0;
		}
	}
}


struct queue {
	int x, y;
};
struct queue queue[5000];
int h, r;
int check[100][100];

int get_score(int n) {

	//초기화//
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= C; j++) check[i][j] = 0;

	int x = gol[n].x;
	int y = gol[n].y;

	h = 0;
	r = 0;

	queue[r].x = x;
	queue[r++].y = y;
	check[x][y] = 1;

	int max_ans = 0;

	for (; h < r; h++) {

		if (max_ans < queue[h].x) max_ans = queue[h].x;

		for (int i = 0; i < 4; i++) {
			int nx = queue[h].x + dx[i];
			int ny = queue[h].y + dy[i];

			//탐색하지 않은 곳//
			if (nx >= 1 && ny >= 1 && nx <= R && ny <= C && check[nx][ny] == 0 && map[nx][ny]!=0) {

				//같은 색//
				if (map[queue[h].x][queue[h].y] == map[nx][ny]) {
					queue[r].x = nx;
					queue[r++].y = ny;
					check[nx][ny] = 1;
				}

				//다른 색//
				else {
					//출구
					int num = map[queue[h].x][queue[h].y];
					int out_x = gol[num].x + dx[gol[num].d];
					int out_y = gol[num].y + dy[gol[num].d];

					//나갈 수 있다면//
					if (queue[h].x == out_x && queue[h].y == out_y) {
						queue[r].x = nx;
						queue[r++].y = ny;
						check[nx][ny] = 1;
					}
				}

			}
		}
	}

	return max_ans;

}

int main(void) {

	cin >> R >> C >> K;

	for (int i = 1; i <= K; i++) {
		cin >> gol[i].y >> gol[i].d;
		gol[i].x = -1;
	}

	int ans = 0;

	for (int i = 1; i <= K; i++) {
		int doing = gol_go(i);

		if (doing == 0) reset_map();

		else ans+=get_score(i);

		//cout << "ans = "<<ans << endl;
		//show();
	}

	cout << ans;






	return 0;
}