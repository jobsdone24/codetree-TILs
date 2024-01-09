#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    unordered_set<int> us1;
    vector<int> us2;

    int n,m;
    cin >> n;

    // n 입력
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        us1.insert(num);
    }

    cin >>m;
    // m 입력
    for(int j=0;j<m;j++){
       int num;
        cin >> num;
        us2.push_back(num);
    }

    for(int i = 0; i < m; i++){
        int su = us2[i];
        if(us1.find(su) != us1.end()) cout << "1 ";
        else cout <<"0 "; 
    }

    return 0;
}