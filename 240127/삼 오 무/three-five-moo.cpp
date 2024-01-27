#include<iostream>
#include<climits>
using namespace std;

long long n;

bool IsPossible(long long target) {
	long long cnt = target/3 + target/5 - target/15;
    if(target-cnt >=n) return true;
	return false;
}

int main() {
	cin >> n;
	long long left = 1;
	long long right = INT_MAX;
	long long dap = INT_MAX;
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