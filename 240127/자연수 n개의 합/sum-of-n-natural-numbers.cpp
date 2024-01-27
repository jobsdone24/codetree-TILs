#include <iostream>
#include<math.h>
typedef long long ll;
using namespace std;

int main() {
    ll s;
    cin >> s;
    ll left = 1;
    ll right = sqrt(1e18*2)+10;
    ll dap = 0;
    ll mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (mid * (1 + mid) / 2 <= s) {
            left = mid + 1;
            dap = max(dap, mid);
        }
        else right = mid - 1;
    }
    cout << dap;

    return 0;
}