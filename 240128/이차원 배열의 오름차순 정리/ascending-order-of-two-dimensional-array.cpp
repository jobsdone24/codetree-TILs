#include<iostream>
#define MAX_N 100000
using namespace std;

typedef long long ll;
int main() {
	ll n,k;
	cin >> n >> k;
	ll lo = 1;
	ll hi = n * n;
	ll dap = 1e9;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		
		//k번째 오는 수가 mid 라면
		ll val = 0;
		for (int i = 1; i <= n; i++) {
			val += min(n, mid / i);
		}
		
		if (val >= k) {
			hi = mid - 1;
			dap = min(dap, mid);
		}
		else lo = mid + 1;
	}
	cout << dap;
}