#include<iostream>
#include<vector>
#include<tuple>
#include<string.h>
#define MAX_N 1000
using namespace std;

vector<pair<int,int> > edge[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1][MAX_N + 1];

int n, m;

void Traversal(int num, int length, int start) {
	for (int i = 0; i < (int)edge[num].size(); i++) {
		int next, worth;
		tie(next,worth) = edge[num][i]; // 부모 num, 자식 next
		if (visited[next] == false) {
			visited[next] = true;
			if (dist[start][next] == 0) {
				dist[start][next] = length + worth;
				dist[next][start] = length + worth;
			}
			else {
				if (dist[start][next] > length + worth)
				{
					dist[start][next] = length + worth;
					dist[next][start] = length + worth;
				}
			}
			Traversal(next,length+worth,start);
		}
	}
}

void show() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << dist[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b>>c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}

	//두 정점의 정보가 주어짐, 거리 바로 구하기
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		Traversal(i, 0,i);
		memset(visited, 0, sizeof(visited));
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}
}