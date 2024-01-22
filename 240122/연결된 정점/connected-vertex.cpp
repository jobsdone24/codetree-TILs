#include<iostream>
#define MAX_N 100'000
using namespace std;

int uf[MAX_N + 1];
int ufcnt[MAX_N+1];

int Find(int x){
	if(uf[x] == x)return x;
	int root = Find(uf[x]);
	uf[x] = root;
	return root;
}

void Union(int x, int y){
	int X = Find(x);
	int Y = Find(y);
	if(X != Y){
	 uf[X] = Y;
	 ufcnt[Y] += ufcnt[X]; 
	}
}

//집합을 나누고 각 집합에 몇개나 포함되어 있는지 확인하기


int main() {
	int n, m;
	cin >> n >> m;

	//초기화 해주기
	for (int i = 1; i <= n; i++){
		uf[i] = i;
		ufcnt[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		char order;
		int a, b;
		cin >> order;
		if (order == 'x') {
			cin >> a >> b;
			Union(a, b);
		}
		else {
			cin >> a;
			cout << ufcnt[Find(a)]<<"\n";
		}
	}
}