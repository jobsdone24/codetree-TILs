#include<iostream>
#include<vector>
#define MAX_N 100'000
#define MAX_H 17
using namespace std;
vector<pair<int, int> > edge[MAX_N + 1];
int depth[MAX_N + 1];
bool visited[MAX_N + 1];
int parent[MAX_H + 1][MAX_N + 1];  //parent[h][i] i번 노드에서 h까지 위로 올라갔을때의 노드 정보
int weight[MAX_N + 1]; // ROOT부터 x 까지 가중치 길이

void DFS(int x) {
    // 노드 x의 자식들을 살펴봅니다.
    for (int i = 0; i < (int)edge[x].size(); i++) {
        int y = edge[x][i].first;
        int w = edge[x][i].second;

        if (visited[y] == false) {
            visited[y] = true;
            depth[y] = depth[x] + 1;
            weight[y] = weight[x] + w;
            parent[0][y] = x;
            DFS(y);
        }
    }
}


int LCA(int a, int b) {
    if (depth[a] < depth[b]) return LCA(b, a);

    //level 1 위치를 같게 해주기
    if (depth[a] != depth[b]) {
        for (int h = MAX_H; h >= 0; h--) {
            if (depth[a] - depth[b] >= (1 << h)) a = parent[h][a];
        }
    }

    if (a == b) return a;

    //level 2 동시에 올리기
    for (int h = MAX_H; h >= 0; h--) {
        if (parent[h][a] != parent[h][b]) {
            a = parent[h][a];
            b = parent[h][b];
        }
    }

    return parent[0][a];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }
    visited[1] = true;
    depth[1] = 1;
    DFS(1);

    //점화식 실행
    for (int h = 1; h <= MAX_H; h++) {
        for (int i = 1; i <= n; i++) {
            parent[h][i] = parent[h - 1][parent[h - 1][i]];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;

        cin >> a >> b;
        int num = LCA(a, b);
        int hap = 0;
        hap += weight[a] - weight[num];
        hap += weight[b] - weight[num];
        cout << hap<< "\n";
    }
}