#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    unordered_set<int> us1;

    int n;
    cin >> n;

    // n 입력
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        us1.insert(num);
    }

    cout << us1.size();

    return 0;
}