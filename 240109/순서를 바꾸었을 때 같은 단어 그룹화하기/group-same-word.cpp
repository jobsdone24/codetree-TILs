#include <iostream>
#include <unordered_map>
#include <string>
#define MAX_N 1000
using namespace std;

int wordsize[MAX_N];

int main() {
    int n;
    cin >> n;
    unordered_map<char, int> word[MAX_N];
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        
        wordsize[i] = w.size();

        //단어 개수 확인
        for (int j = 0; j < w.size(); j++) word[i][w[j]]++;
    }

    int ans = 0;
    // N * N 으로 돌면서 확인하기
    for (int i = 0; i < n; i++) {
        int group = 0;
        for (int j = i; j < n; j++) {
            if (wordsize[i] == wordsize[j]) {
                bool flag = false;
                for (auto it = word[i].begin(); it != word[i].end(); it++) {
                    char temp = it->first;
                    int cnt = it->second;
                    if (word[j][temp] != cnt) {
                        flag = true;
                        break;
                    }
                }
            if (flag==false) group++;
            }
        }
        ans = max(ans, group);
    }
    cout << ans;

    return 0;
}