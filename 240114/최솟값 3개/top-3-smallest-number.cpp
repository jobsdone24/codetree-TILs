#include <iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(-num);
        if (i < 2) {
            cout << -1 << "\n";
            continue;
        }
        int arr[4] = { 0 };
        for (int j = 0; j < 3; j++) {
            arr[j] = -pq.top();
            pq.pop();
        }
        long long sum = 1;
        for (int j = 0; j < 3; j++) {
            pq.push(-arr[j]);
            sum *= arr[j];
        }
        cout << sum << "\n";
    }
    return 0;
}