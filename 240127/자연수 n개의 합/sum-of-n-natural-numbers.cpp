#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    ll s;
    ll n;
    cin >> s >> n;
    ll left = 1;
    ll right = n;
    ll dap =0;
    ll mid = 0;

    while(left<=right){
        mid = (left+right)/2;
        if(mid*(1+mid)/2 <= s){
            left = mid+1;
            dap = max(dap,mid);
        }
        else right = mid-1;
    }
    cout << dap;

    return 0;
}