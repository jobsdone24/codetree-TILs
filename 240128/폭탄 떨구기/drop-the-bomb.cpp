#include<iostream>
#include<algorithm>
#define MAX_N 50'000
#define MAX 1'000'000'000
using namespace std;

int N, K;
int arr[MAX_N + 1];

bool ispossible(int dist) {
	//dist의 거리를 가지고 다 터트릴 수 있는지 확인하기
	int cur = arr[0] + dist;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (cur + dist < arr[i]) {
			cnt++;
			cur = arr[i] + dist;
		}
	}
	return cnt <= K;
}

int main() {
	cin >> N >> K;
	int left = 0;
	int right = MAX;
	int dap = MAX;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	while (left <= right) {
		int mid = (left + right) / 2;
		if (ispossible(mid)) {
			right = mid - 1;
			dap = min(dap, mid);
		}
		else left = mid + 1;
	}
	cout << dap;
}