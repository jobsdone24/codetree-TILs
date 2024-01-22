#include<iostream>
#include<algorithm>
#include<tuple>
#include<math.h>
#define MAX_N 200
using namespace std;

tuple<double, int, int> edge[MAX_N * MAX_N];
int uf[MAX_N + 1];
pair<int, int> dot[MAX_N + 1];

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
        int a, b;
        cin >> a >> b;
        dot[i] = { a,b };
    }

    int size = 0;
    //가중치 만들기
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long x1, x2, y1, y2;
            tie(x1, y1) = dot[i];
            tie(x2, y2) = dot[j];
            double w = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            edge[size++] = { w,i,j };
        }
    }

    sort(edge, edge + size);

    for (int i = 1; i <= n; i++) uf[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    double hap = 0;
    for (int i = 0; i < size; i++) {
        double w;
        int f, s;
        tie(w, f, s) = edge[i];
        if (Find(f) != Find(s)) {
            Union(f, s);
            hap += w;

        }
    }
    printf("%.2f", hap);
}