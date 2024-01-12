#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int> > s;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert({ x,y });
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (s.lower_bound({ x,y }) != s.end()) cout << s.lower_bound({ x,y })->first << " " << s.lower_bound({ x,y })->second << "\n";
        else cout << "-1 -1" << "\n";
    }

    return 0;
}