#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n,m;
    unordered_map<string,int> string_to_int;
    unordered_map<int,string> int_to_string;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string a;
        cin >> a;
        string_to_int[a] = i;
        int_to_string[i] = a;
    }

    for(int i=0;i<m;i++){
        string a;
        cin >> a;
        if(a[0]>='a' && a[0]<='z'){
            cout <<string_to_int[a]<<"\n";
        }
        else cout<< int_to_string[stoi(a)]<<"\n";

    }

    return 0;
}