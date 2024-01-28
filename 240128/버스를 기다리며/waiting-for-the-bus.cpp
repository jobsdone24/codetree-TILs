#include<iostream>
#include<algorithm>
#define MAX_N 100'000
#define MAX 1'000'000'000
using namespace std;

int N, M,C;
int arr[MAX_N + 1];

bool ispossible(int dist) {
	//dist의 거리를 가지고 다 터트릴 수 있는지 확인하기
	int start = arr[0];
	int bus = 1;
    int buscnt=1;
	for (int i = 1; i < N; i++) {
		//바뀌든 그냥 처음타던 버스를 옮겨서 탄다면
		if (arr[i] - start <= dist && buscnt+1<=C ){
            buscnt++;
		}
        else {
			bus++;
			start = arr[i];
            buscnt= 1;
        }
	}
	return bus <= M;
}

int main() {
	cin >> N >> M >> C;
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