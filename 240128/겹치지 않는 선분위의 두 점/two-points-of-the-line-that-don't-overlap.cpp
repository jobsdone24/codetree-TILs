#include<iostream>
#include<algorithm>
#define MAX_N 100'000
using namespace std;
typedef long long ll;
ll n, m;
pair<ll, ll> arr[MAX_N + 1];

bool ispossible(ll x) {
	ll cur = -(int)1e18;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		while (cur+x <= arr[i].second) {
			cur = max(arr[i].first, cur + x);
			cnt++;
		}
	}
	return cnt >= n;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		arr[i] = { s,e };
	}

	//오름차순 정렬
	sort(arr, arr + m);

	ll left = 0;
	ll right = 1e18;
	ll dap = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (ispossible(mid)) {
			//가장 가까운 거리를 mid라고 할때 가능한지 여부
			//가능 하다면 더 크게 하기 위해서는 mid가 더 커야한다-
			left = mid + 1;
			dap = max(dap, mid);
		}
		else right = mid - 1;
	}
	cout << dap;
}