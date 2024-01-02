#include <iostream>
#include<math.h>
using namespace std;
const int INF = 1000000007;

int main() {
	long long s[1004] = { 0 };
	long long gop[1004]={0};
	int n;
	cin >> n;
	s[1] = 1;
	s[2] = 2;
	gop[1]=2;
	gop[2] =4;
	for (int i = 3; i <= n; i++) {
		s[i] = s[i - 1] + s[i - 2];
		gop[i] = 2*gop[i-1] % INF;
	}

	cout << (s[n]%INF *gop[n]) % INF - s[n] + 1;
	
}