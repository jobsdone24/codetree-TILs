#include<iostream>
#define MAX_N 100'000
using namespace std;

int uf[MAX_N + 1];

int Find(int x) {
	if (uf[x] == x) return x;
	int root = Find(uf[x]); //x의 부모의 root값
	uf[x] = root;
	return root;
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);
	uf[X] = Y;
}

int main() {
	int n, m;
	cin >> n >> m;

	//초기화 해주기
	for (int i = 1; i <= n; i++) uf[i] = i;

	for (int i = 0; i < m; i++) {
		int order, a, b;
		cin >> order >> a >> b;
		if (order == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b))cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}