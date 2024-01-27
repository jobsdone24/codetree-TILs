#include <iostream>
#include<math.h>
#define MAX_N 100'000
using namespace std;
int arr[MAX_N + 1];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < m; i++) {
        int left = 0;
        int right = n - 1;
        int target;
        cin >> target;
        int lowerbound = n;
        int flag = 0;
        //lower bound
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {
                right = mid - 1;
                if(arr[mid]==target) flag = 1;
                lowerbound = min(lowerbound, mid);
            }
            else left = mid + 1;
        }
        if(flag == 0) cout << -1<<"\n";
        else cout << lowerbound+1<<"\n";
    }
    return 0;
}