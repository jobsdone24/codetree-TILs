#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if (temp[0] == 'a') {
            int a, b;
            cin >> a >> b;
            map[a] =  b;
        }
        else  if (temp[0] == 'f') {
            int a;
            cin >> a;
            if (map.find(a) == map.end()) cout << "None\n";
            else cout << map[a] << "\n";

        }
        else  if (temp[0] == 'r') {
            int a;
            cin >> a;
            map.erase(a);
        }

    }
    return 0;
}