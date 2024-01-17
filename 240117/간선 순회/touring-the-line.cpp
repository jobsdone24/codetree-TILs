#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include<queue>
#define MAX_N 50000
using namespace std;

int n, d;
vector<pair<int, int> > edge[MAX_N + 1];
bool visited[MAX_N + 1];
priority_queue<pair<int, int> > pq;

void Traversal(int num, int dist, int depth) {
    bool check = false;

    for (int i = 0; i < (int)edge[num].size(); i++) {
        int next, length;
        tie(next,length) = edge[num][i];            
        if (visited[next] == false) {
            visited[next] = true;
            Traversal(next, dist+length,depth+1);
            check = true;
        }
    }
    
    //깊이 클수록, 거리 작을수록 
    if (check == false) pq.push({ depth,-dist });
}

int main() {

    cin >> n >> d;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }

    //특정 점에서 시작
    visited[1] = true;

    priority_queue<int> select;

    for (int i = 0; i < edge[1].size(); i++) {
        Traversal(edge[1][i].first, edge[1][i].second, 1);
        int depth, length;
        tie(depth, length) = pq.top();
        select.push(length);
        while (!pq.empty()) pq.pop();
    }
    int hap = 0;
    int cnt = 0;
    while (!select.empty()) {
        hap += select.top();
        select.pop();
        if (cnt++ == 2)break;
    }
    
    if (-hap % d == 0) {
        cout << -hap / d;
    }
    else  cout << (-hap / d) + 1;
    return 0;
}