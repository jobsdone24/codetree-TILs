#include<iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	ll lo = 1;
	ll hi = n * n;
	ll dap = 1e9;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll val = 0; //val은 특정 수가 몇번째 수인지 확인하기

		for (int i = 1; i <= n; i++) {
			val += min(n, mid / i); //최대 n개 까지 올 수 있으니까
		}

		//확인했다면
		if (val >= k) {
			hi = mid - 1;
			dap = min(dap, mid);
		}
		else lo = mid + 1;
	}
    cout << dap;
	return 0;
}