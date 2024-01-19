#include <iostream>
#include <vector>
#include <tuple>
#include<string.h>
#define MAX_N 50000

using namespace std;

// 변수 선언:
int n;
vector<pair<int, int> > edge[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];
int dist_node[MAX_N+1];
pair<int, int> max_dist; // 정점 이동 클수록, 길이 작을 수록
int last_node;

void DFS(int x,int cnt) {
    for (int i = 0; i < edge[x].size(); i++) {
        int y, d;
        tie(y, d) = edge[x][i];

        if (visited[y]) continue;

        visited[y] = true;
        dist[y] = dist[x] + d;
        pair<int, int> temp = {cnt+1,-dist[y] };
        if (max_dist < temp) {
            max_dist = temp;
            last_node = y;
        }

        DFS(y,cnt+1);
    }
}

int main() {
    int d;
    cin >> n>>d;

    for (int i = 1; i <= n - 1; i++) {
        int x, y, dd;

        cin >> x >> y >> dd;

        edge[x].push_back({ y, dd });
        edge[y].push_back({ x, dd });
    }

    visited[1] = true;
    DFS(1,0);

    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
    visited[last_node] = true;
    DFS(last_node,0);
    int length = -max_dist.second;
    if (length % d == 0) cout << length / d;
    else cout << (length / d) + 1;
}