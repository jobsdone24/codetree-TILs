#include<iostream>
#define MAX_N 10'000
#define MAX_T 1'000'000
#include<queue>
#include<functional>
using namespace std;

int N, T;
int arr[MAX_N + 1];
bool ispossible(int k) {
	//k명의 사람으로도 가능하다면
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < k; i++) {
		if (arr[i] > T) return false;
		pq.push(arr[i]);
	}

	for (int i = k; i <N; i++) {
		int num = pq.top();
		pq.pop();
		if (num + arr[i] > T)return false;
		pq.push(num + arr[i]);
	}
	return true;
}

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	int left = 1;
	int right = MAX_N;
	int dap = MAX_N;
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