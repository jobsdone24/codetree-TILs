#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (s.lower_bound(num) != s.end()) cout << *(s.lower_bound(num)) << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}