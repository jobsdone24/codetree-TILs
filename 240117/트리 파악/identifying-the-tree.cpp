#include<iostream>
#include<vector>
#include<tuple>
#include<string.h>
#define MAX_N 100'000
using namespace std;

vector<int > edge[MAX_N + 1];
vector<int> leap;
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

int N;

void Traversal(int num, int cnt) {
	bool check = false;
	for (int i = 0; i < (int)edge[num].size(); i++) {
		int next = edge[num][i]; // 부모 num, 자식 next
		if (visited[next] == false) {
			visited[next] = true;
			dist[next] = cnt;
			Traversal(next,cnt+1);
			check = true;
		}
	}
	if (check == false) leap.push_back(num);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int i = 0; i <N-1; i++) {
		int a, b, c;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	//두 정점의 정보가 주어짐, 거리 바로 구하기
	visited[1] = true;
	Traversal(1, 1);

	int hap = 0;
	for (int i = 0; i < leap.size(); i++) {
		hap += dist[leap[i]];
	}
	if (hap % 2 == 0) cout << 0;
	else cout << 1;
	
}