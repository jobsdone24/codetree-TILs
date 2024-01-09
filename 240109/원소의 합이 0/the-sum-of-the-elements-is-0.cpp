#include<iostream>
#include<unordered_map>
#define MAX_N 5000
using namespace std;

int A[MAX_N + 1];
int B[MAX_N + 1];
int C[MAX_N + 1];
int D[MAX_N + 1];

int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; j++) {
		cin >> A[j];
	}
	for (int j = 0; j < n; j++) {
		cin >> B[j];
	}
	for (int j = 0; j < n; j++) {
		cin >> C[j];
	}
	for (int j = 0; j < n; j++) {
		cin >> D[j];
	}

	unordered_map<int, int> AB;
	unordered_map<int, int> CD;

	//쌍 만들기25,000,000
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num_AB = A[i] + B[j];
			int num_CD = C[i] + D[j];
			AB[num_AB]++;
			CD[num_CD]++;
		}
	}

	int ans = 0;
	//AB 순회하면서 CD있는지 확인하기
	for (auto it = AB.begin(); it != AB.end(); it++) {
		int hap = it->first;
		int cnt = it->second;
		
		if (CD.find(-hap) != CD.end()) {
			int cnt2 = CD[-hap];
			ans += cnt * cnt2;
		}
	}
	cout << ans;
}