#include <iostream>
#include <unordered_map>
#include<vector>

using namespace std;

int main() {
    unordered_map<int,int> um;
    vector<int> v;
    int n,m;

    cin >> n >> m;

for(int i=0;i<n;i++){
    int number;
    cin >> number;
    if(um.find(number)!=um.end()){
        um[number]++;
    }
    else um.insert({number,1});
}
for(int i=0;i<m;i++){
    int number;
    cin >> number;
    cout << um[number]<<" ";
}
    
    return 0;
}