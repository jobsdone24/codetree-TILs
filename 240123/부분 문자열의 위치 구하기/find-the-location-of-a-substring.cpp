#include<iostream>
#include<string>
#define MAX_N 500'000
using namespace std;

int CtoI(char x) {
	return x - 'a' + 1;
}

int p[2] = { 31,37 };
int m[2] = { (int)1e9 + 7 ,(int)1e9 + 9 };
long long p_pow[2][MAX_N+1]; //p_pow[i][j] i == 0 31을 j승 한 것을 m으로 나눈 나머지
int n, l;
int main() {
	string tar,pat;
	cin >> tar >> pat;
	n = (int)tar.size();
	l = (int)pat.size();

	// p_pow 만들어주기
	for (int i = 0; i < 2; i++) {
		p_pow[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			p_pow[i][j] = (p_pow[i][j - 1] * p[i]) % m[i];
		}
	}

	// pattern hash 만들기
	long long p_h[2] = {};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < l; j++) {
			p_h[i] = (p_h[i] + (CtoI(pat[j]) * p_pow[i][l - 1 - j])) % m[i];
		}
	}

	// target hash 만들기
	long long t_h[2] = {};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < l; j++) {
			t_h[i] = (t_h[i] + (CtoI(tar[j]) * p_pow[i][l - 1 - j])) % m[i];
		}
	}

	if (p_h[0] == t_h[0] && p_h[1] == t_h[1]) {
		cout << 0;
		return 0;
	}
		//text 문자열에서 찾기
	for (int i = 1; i <= n - l; i++) {
		for (int k = 0; k < 2; k++) {
			t_h[k] = (p[k] * t_h[k] - (CtoI(tar[i - 1]) * p_pow[k][l]) + CtoI(tar[i + l - 1])) % m[k];
			if (t_h[k] < 0) t_h[k] += m[k];

			if (t_h[0] == p_h[0] && t_h[1] == p_h[1]) {
				cout << i;
				return 0;
			}
		}

	}
    cout << -1;
}