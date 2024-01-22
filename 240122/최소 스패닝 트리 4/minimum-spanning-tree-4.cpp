#include<iostream>
#include<algorithm>
#include<tuple>
#define MAX_N 10'000
#define MAX_M 100'000
using namespace std;

tuple<int, int, int> edge[MAX_M + 1];
int uf[MAX_N + 1];
int team[MAX_N + 1];

int Find(int x) {
    if (uf[x] == x)return x;
    int root = Find(uf[x]);
    uf[x] = root;
    return root;
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);
    uf[X] = Y;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        char temp;
        cin >> temp;
        team[i] = temp - 'a'; //a팀은 0 b팀은 1
    }
    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        edge[i] = { weight,a,b };
    }
    sort(edge, edge + m);

    for (int i = 1; i <= n; i++) uf[i] = i;

    int hap = 0;
    for (int i = 0; i < m; i++) {
        int w, f, s;
        tie(w, f, s) = edge[i];
        if (team[f] == team[s])continue;
        if (Find(f) != Find(s)) {
            Union(f, s);
            hap += w;
        }
    }
    if (hap == 0)hap = -1;
    cout << hap;
}