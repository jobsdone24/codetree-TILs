#include<iostream>
#define MAX_N 100'000
using namespace std;
typedef long long ll;
ll n, m;
int arr[MAX_N + 1];

bool IsPossible(ll x) {
	ll cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += x/arr[i];
    }

	if (cnt >= n) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];

	ll lo = 1;
    ll hi = 1e14;
	ll dap = 1e14;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (IsPossible(mid)) {
			hi = mid - 1;
			dap = min(dap, mid);
		}
		else lo = mid + 1;
	}
	cout << dap;
}