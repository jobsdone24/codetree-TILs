#include<iostream>
#define MAX_N 200'000
#include<string>
#include<queue>
using namespace std;

int arr[MAX_N + 1];
string A, B;
int bsize;
int asize;

bool IsPossible(int idx) {
	string temp;
	temp = A;
	for (int i = 0; i < idx; i++) temp[arr[i]-1] = ' ';
	int bidx = 0;

	for (int i = 0; i < asize;i++){
		if(bidx < bsize && temp[i] == B[bidx]) bidx++;
	}
	return bidx == bsize;
}

int main() {

	cin >> A >> B;
	asize = A.size();
	bsize = B.size();

	for (int i = 0; i < asize; i++) cin >> arr[i];
	int left = 0;
	int right = asize - 1;
	int dap = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		// mid에 해당하는 값까지 지웠을 때 가능한 지 확인하기
		if (IsPossible(mid)) {
			left = mid + 1;
			dap = max(dap, mid);
		}
		else right = mid - 1;
	}
	if (IsPossible(0))dap++;

	cout << dap;
}