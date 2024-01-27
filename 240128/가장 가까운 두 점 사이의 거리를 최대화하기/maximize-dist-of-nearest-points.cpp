#include<iostream>
#include<algorithm>
#define MAX_N 100'000
using namespace std;

int n;
pair<int, int> arr[MAX_N + 1];

//x만큼 각 영역 별로 차이를 뒀을때 가능, 불가능을 판단할 수 있는가?
bool ispossible(int x) {
	int cur = arr[0].first;
	for (int i = 1; i < n; i++) {
		if(cur+x <= arr[i].second)
        {
            cur = max(cur+x,arr[i].first);
            continue;
        }
		return false;
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr[i] = { s,e };
	}

	//오름차순 정렬
	sort(arr, arr + n);

	int left = 1;
	int right = 1e9;
	int dap = 0;
	while (left <= right) {
		int mid = (left+right)/2;
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