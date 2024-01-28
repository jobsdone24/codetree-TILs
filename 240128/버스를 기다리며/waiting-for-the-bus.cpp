#include<iostream>
#include<algorithm>
#define MAX_N 100'000
#define MAX 1'000'000'000
using namespace std;

int N, M,C;
int arr[MAX_N + 1];

bool ispossible(int dist) {
	//dist의 거리를 가지고 다 터트릴 수 있는지 확인하기
	int start = 0;
	int bus = 0;
    int buscnt=0;
	for (int i = 0; i < N; i++) {
		if (start == 0){
            bus++;
            start = arr[i];
		}
        if (arr[i] - start <= dist){
            buscnt++;
            if(buscnt==C){
                start=0;
                buscnt = 0;
            }
		}
        else {
			bus++;
			start = 0;
            buscnt= 0;
        }
        //if(dist == 0) cout <<i<<"번째 진행상황 : "<< start <<" "<<buscnt<<" "<<bus<<"\n";
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