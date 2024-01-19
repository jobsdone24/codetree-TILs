#include <iostream>
#include <vector>
#include <tuple>
#define MAX_N 100'000
using namespace std;

int n;
vector<pair<int, int> > edge[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];
int max_dist;
int last_node;

// 모든 노드의 정점을 탐색하는 DFS를 진행합니다.
void DFS(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        int y, d;
        tie(y, d) = edge[x][i];

        // 이미 방문한 정점이면 스킵합니다.
        if (visited[y]) continue;

        visited[y] = true;
        dist[y] = dist[x] + d;

        if (dist[y] > max_dist) {
            max_dist = dist[y];
            last_node = y;
        }

        DFS(y);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
    max_dist = 0;
}

int main() {
    // 입력:
    cin >> n;

    int last = 0;
    for (int i = 1; i <= n - 1; i++) {
        int x, y, d;

        cin >> x >> y >> d;

        edge[x].push_back({ y, d });
        edge[y].push_back({ x, d });
        last = y;
    }

    // DFS를 통해 가장 먼 노드를 찾습니다.
    visited[last] = true;
    DFS(last);

    init();

    int start =  last_node;
    visited[last_node] = true;
    DFS(last_node);
    int end = last_node;

    init();
    visited[start] = true;
    visited[end] = true;
    DFS(start);
    int big = max(big, max_dist);

    init();
    visited[start] = true;
    visited[end] = true;
    DFS(end);
    big = max(big, max_dist);
   
    cout << big;
    return 0;
}