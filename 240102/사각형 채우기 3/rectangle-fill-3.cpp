#include <iostream>
#include<math.h>
using namespace std;
const int INF = 1000000007;

int main() {
	long long s[1008] = { 0 };
	int n;
	cin >> n;
	s[0] = 1;
	s[1] = 2;
	s[2] = 7;
	for (int i = 3; i <= n; i++) {
		s[i] = 2 * s[i - 1] + 3 * s[i - 2];
		s[i] %= INF;
		for (int j = 3; j <= i; j++) {
			s[i] += 2 * s[i - j];
		}
		s[i] %= INF;
	}
	cout << s[n];

}