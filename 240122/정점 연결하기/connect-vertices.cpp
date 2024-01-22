#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int uf[MAX_N + 1];

int Find(int x) {
    if (uf[x] == x) return x;
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
    int n;
    cin >> n;
    
    //초기화 해주기
    for (int i = 1; i <= n; i++) uf[i] = i;

    for (int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b); //a와 b가 이어진 그룹
    }
    int A = Find(1);
    vector<int> ateam;
    vector<int> bteam;

    for (int i = 1; i <= n; i++) {
        if (A == Find(i)) ateam.push_back(i);
        else bteam.push_back(i);
    }
    sort(ateam.begin(), ateam.end());
    sort(bteam.begin(), bteam.end());

    cout << ateam[0] << " " << bteam[0] << "\n";

    return 0;
}