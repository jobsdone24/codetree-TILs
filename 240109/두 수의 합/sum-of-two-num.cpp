#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

int main() {
    int n,k;
    vector<int> v;
    unordered_map<int,int> check;
    unordered_map<int,int> count;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
        count[num]++;
        check[num] = k-num;
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        int num = v[i];

        if(check.find(num) != check.end()){
            if(check.find(k-num) != check.end()){
                if(num == k-num) cnt += count[k-num]-1;
                else cnt += count[k-num];
            }
        }
    }
    cout << (cnt+1)/2;
    return 0;
}