#include<iostream>
#include<string>
#include<unordered_map>
#define MAX_S 100'000
using namespace std;

int p = 31;
int m = (int)1e9 + 7;
long long p_pow[MAX_S + 1];
int n, l;
unordered_map<long long, int> um;

int ToInt(char x) {
	return x - 'a' + 1;
}

int main() {
	string S;
	cin >> l >> S;
	n = S.size();

	//p_pow 만들기
	p_pow[0] = 1;
	for (int i = 1; i <= n; i++) {
		p_pow[i] = (p_pow[i - 1] * p) % m;
	}
	
	// p_h 구하기
	long long p_h = 0;
	for (int i = 0; i < l; i++) {

		p_h = (p_h + ToInt(S[i]) * p_pow[l - 1 - i]) % m;
	}
	um[p_h]++;

	//전체 순회하기
	for (int i = 1; i <= n - l; i++) {
		p_h = (p_h * p - (ToInt(S[i - 1]) * p_pow[l]) + ToInt(S[l+i- 1])) % m;
		if (p_h < 0)p_h += m;
		um[p_h]++;
	}
	int big = 0;
	for (auto nxt : um) {
		int cnt = nxt.second;
		if (big < cnt) big = cnt;
	}
	
	cout << big;
}