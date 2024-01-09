#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    unordered_map<string,int> map;
    cin >> n;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        map[a]++;
    }
    
    int ans=0;
    for(auto nxt : map){
        ans = max(ans,nxt.second);
    }
    cout << ans;
    return 0;
}