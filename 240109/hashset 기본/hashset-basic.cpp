#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string a;
        int order;
        cin >> a >> order;

        if(a[0] == 'a') us.insert(order);
        else if(a[0] == 'r') us.erase(order);
        else if(a[0] == 'f'){
            if(us.find(order) != us.end()) cout << "true\n";
            else cout << "false\n";
        }
    }
    return 0;
}