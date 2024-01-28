#include<iostream>
#define MAX_N 100'000
using namespace std;

int n;
int X[MAX_N + 1];
int V[MAX_N + 1];

bool IsPossible(double time) {
	double hap = X[0] + time * V[0];
	double minus = X[0] - time * V[0];
	for (int i = 1; i < n; i++) {
		double xm = X[i] - time * V[i];
		double xh = X[i] + time * V[i];
		hap = min(hap, xh);
		minus = max(minus, xm);
	}
	return hap >= minus;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> X[i];
	for (int i = 0; i < n; i++) cin >> V[i];
	double lo = 0;
	double hi = 1e9;
	double dap = 1e9;
	
	for(int i=1;i<=50;i++){
		double mid = (lo + hi) / 2;
		if (IsPossible(mid)) {
			//만약 t초가 가능하다면 더 줄이기
			hi = mid ;
			dap = min(dap, mid);
		}
		else lo = mid ;
	}
	cout << fixed;
	cout.precision(4);
	cout << dap;
}