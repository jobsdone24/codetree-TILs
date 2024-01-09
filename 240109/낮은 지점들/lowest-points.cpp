#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int,int> target;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >>y;
        if(target.find(x) != target.end()){
            int num = target[x];
            if(y<num) target[x] = y;
        }
        else target.insert({x,y});
    }

    int sum=0;
    for(auto it = target.begin(); it != target.end(); it++){
        sum += it->second;
    }
    cout << sum;
    return 0;
}