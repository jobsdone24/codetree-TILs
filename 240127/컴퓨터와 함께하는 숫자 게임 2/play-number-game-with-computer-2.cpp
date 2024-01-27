#include<iostream>
#include<climits>
using namespace std;

long long m;
int BinarySearch(int target) {
	long long left = 1;
	long long right = m;
	long long mid = 0;
	int cnt = 0;

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
	int small = INT_MAX;
	int big = INT_MIN;
	for (int i = a; i <= b; i++) {
		int num = BinarySearch(i);
		small = min(small, num);
		big = max(big, num);
	}
	cout << small << ' ' << big << "\n";
}