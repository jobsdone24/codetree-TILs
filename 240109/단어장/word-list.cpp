#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> m;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        m[input]++;
    }
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << " "<<it->second<<"\n";
    }
}