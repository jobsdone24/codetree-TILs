#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm> 
#define MAX_N 1000

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> word;
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        sort(w.begin(),w.end());
        word[w]++;
    }

    int ans = 0;
    for(auto it = word.begin() ; it != word.end(); it++){
        ans= max(ans,it->second);
    }
    cout << ans;

    return 0;
}