#include<iostream>
using namespace std;

int n, m;

bool IsPossible(int target) {
	int cnt = 0;

	return cnt >= m;
}

int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= 1e9; i++) {
		if (i % 3 == 0 || i % 5 == 0)continue;
		cnt++;
        if(cnt==4){
            cout <<i;
            break;
    }
    }
}