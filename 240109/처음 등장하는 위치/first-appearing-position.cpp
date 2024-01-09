#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,int> m;

    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        if(m.find(number)== m.end()){
            m[number] = i+1;
        }
    }

    for(auto it = m.begin(); it != m.end();it++){
        cout << it->first <<' '<< it->second<<"\n";
    }
    return 0;
}