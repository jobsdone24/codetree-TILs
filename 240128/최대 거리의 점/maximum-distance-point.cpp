#include<iostream>
#define MAX_N 200000
using namespace std;
int arr[MAX_N + 1];
int n, m;

bool IsPossible(int x) {
	//두 점 사이의 거리 최소값이 최대가 되려면 -> 가장 작은 점 부터 설정해야 함
	int cur = arr[0];
	int cnt = 1;
	int idx = 1;

	while (idx<n) {
		if (arr[idx] - cur >= x) {
			cnt++;
			cur = arr[idx];
		}
		idx++;
	}
	return cnt >= m;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];

	int left = 0;
	int right = (int)1e9;
	int dap = 0;
    
	while (left <= right) {
		//두 점의 거리를 최소 mid로 둠, 즉 mid보다 간격이 크거나 같아야 한다.
		int mid = (left + right) / 2;
		if (IsPossible(mid)) {
			left = mid + 1;
			dap = max(dap, mid);
		}
		else right = mid - 1;
	}
	cout << dap;
}