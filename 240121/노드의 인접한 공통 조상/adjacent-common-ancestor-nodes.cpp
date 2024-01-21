#include<iostream>
#include<vector>
#define MAX_N 10'000
using namespace std;
vector<int> edge[MAX_N + 1];
int depth[MAX_N + 1];
int parent[MAX_N + 1];

void DFS(int x) {
    // 노드 x의 자식들을 살펴봅니다.
    for (int i = 0; i < (int)edge[x].size(); i++) {
        int y = edge[x][i];
        depth[y] = depth[x] + 1;
        DFS(y);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        parent[b] = a;
    }
    int a, b;
    cin >> a >> b;


    int root = 0;
    int start = 1;
    while (1) {
        if (parent[start] == 0) {
            root = start;
            break;
        }
        start = parent[start];
    }

    DFS(root);

    //step 1
    while (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) a = parent[a];
        else if (depth[a] < depth[b]) b = parent[b];
    }

    //step 2
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    cout << a;
}