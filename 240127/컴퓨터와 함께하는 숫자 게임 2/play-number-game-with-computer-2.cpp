#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

long long m;
long long BinarySearch(long long target) {
	long long left = 0;
	long long right = m-1;
	long long mid = 0;
	long long cnt = 0;
    target--;

	while (left <= right) {
		cnt++;
        mid = (left + right) / 2;
		if (mid < target) {
			left = mid + 1;
		}
		else if (mid > target) {
			right = mid - 1;
		}
		else {
			break;
		}
	}
	return cnt;
}

int main() {

	long long a, b;
	cin >> m >> a >> b;
	long long small = LLONG_MAX;
	long long big = 0;
	for (long long i = a; i <= b; i++) {
		long long num = BinarySearch(i);
		small = min(small, num);
		big = max(big, num);
	}
	cout << small << ' ' << big << "\n";
}