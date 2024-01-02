#include <iostream>
#include<math.h>
using namespace std;
const int INF = 1000000007;

int main() {
	long long s[1004] = { 0 };
	int n;
	cin >> n;
	s[1] = 1;
	s[2] = 2;
	for (int i = 3; i <= n; i++) {
		s[i] = s[i - 1] + s[i - 2];
	}

	long long temp = (long long)pow(2, n) % INF;
	cout << (s[n] * temp) % INF - s[n] + 1;
	
}