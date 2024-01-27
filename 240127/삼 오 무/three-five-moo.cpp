#include<iostream>
using namespace std;

int n;

bool IsPossible(int target) {
	int cnt = target/3 + target/5 - target/15;
    if(target-cnt >=n) return true;
	return false;
}

int main() {
	cin >> n;
	int left = 1;
	int right = 1e9;
	int dap = 2*1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (IsPossible(mid)){
            right = mid - 1;
            dap = min(dap,mid);
        }
        else{
            left = mid +1;
		}
	}
    cout << dap;
}