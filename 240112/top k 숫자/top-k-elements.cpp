#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int > s;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        if(s.find(num)== s.end()) s.insert(num);
    }
    
    auto it = s.rbegin();
    for(int i=0;i<k;i++){
        cout << *(it++)<< ' ';
    }

    return 0;
}