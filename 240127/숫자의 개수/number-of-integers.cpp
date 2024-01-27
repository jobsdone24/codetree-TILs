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
        
        //lower bound
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {
                right = mid - 1;
                lowerbound = min(lowerbound, mid);
            }
            else left = mid + 1;
        }

        left = 0;
        right = n - 1;
        int upperbound = n;
        //upper bound
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > target) {
                right = mid - 1;
                upperbound = min(upperbound, mid);
            }
            else left = mid+1;
        }
        cout << upperbound-lowerbound<<"\n";
    }
    return 0;
}