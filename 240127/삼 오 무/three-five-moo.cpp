#include<iostream>
using namespace std;

int n;

bool IsPossible(int target) {
	int cnt = 0;
	for (int i = 1; i <= target; i++) {
		if (i % 3 == 0 || i % 5==0) continue;
		else cnt++;
		
		if (cnt > n-1) return false;
    }

    //cnt수가 n-1인것
	return true;
}

int main() {
	cin >> n;
	int left = 1;
	int right = 1e9;
	int dap = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (IsPossible(mid)==false) right = mid - 1;
		else{
            left = mid + 1;
            dap = max(dap,mid);
		}
	}
    for(int i=dap+1; ;i++){
        if(i%3 ==0 || i%5==0)continue;
        cout <<i;
        break;
    }
}