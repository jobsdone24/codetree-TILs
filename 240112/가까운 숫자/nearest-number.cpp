#include<iostream>
#include<set>
#include<climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    int small = INT_MAX;
    int first;
    cin >> first;
    small = first;
    cout << small << "\n";
    s.insert(0);
    s.insert(first);
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        if (s.upper_bound(num) != s.end()) {
            auto iter = s.upper_bound(num);
            int n1 = *(iter);
            small =min(small, n1 - num);
        }

            auto iter = s.upper_bound(num);
            iter--;
            int n2 = *(iter);
            small = min(small, num - n2);
         s.insert(num);         
        cout << small << "\n";
    }

}