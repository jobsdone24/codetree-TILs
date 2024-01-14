#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#define MAX_NUM 100000

using namespace std;
int arr1[MAX_NUM];
int arr2[MAX_NUM];
priority_queue<tuple<int, int, int> > pq;

int main(){
	int n, m, k;	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];

	for (int i = 0; i < m; i++)
		cin >> arr2[i];
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
	
	for (int i = 0; i < n; i++) {
		pq.push({ -(arr1[i] + arr2[0]),i,0 });
	}

	for (int i = 0; i < k - 1; i++) {
		int idx1, idx2;
		tie(ignore, idx1, idx2) = pq.top();
		pq.pop();

		idx2++;
		if (idx2 < m) {
			pq.push({ -(arr1[idx1] + arr2[idx2]),idx1, idx2 });
		}
	}
	int hap;
	tie(hap, ignore, ignore) = pq.top();
	cout << -hap;
}