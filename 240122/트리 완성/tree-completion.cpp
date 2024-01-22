#include <iostream>
#define MAX_N 100000
using namespace std;

int uf[MAX_N + 1];
int minuscnt = 0;
int pluscnt = 0;
bool team[MAX_N+1];

int Find(int x) {
    if (uf[x] == x) return x;
    int root = Find(uf[x]);
    uf[x] = root;
    return root;
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);
    if (X == Y) minuscnt++;
    else uf[X] = Y;
}

int main() {
    int n, m;
    cin >> n >> m;

    //초기화 해주기
    for (int i = 1; i <= n; i++) uf[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b); //a와 b가 이어진 그룹
    }

    team[Find(1)] = true;

    for (int i = 1; i <= n; i++) {
        if (team[Find(i)] == false){
            pluscnt++;
            team[Find(i)] = true;
        }
    }

    cout << minuscnt + pluscnt;
    return 0;
}