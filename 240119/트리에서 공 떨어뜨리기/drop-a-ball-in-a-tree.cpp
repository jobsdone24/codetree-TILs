#include<iostream>
#define MAX_N 200'000
using namespace std;

int lnode[MAX_N + 1];
int rnode[MAX_N + 1];
int ans;

void dfs(int node, long long ball){
	if(lnode[node]==-1 && rnode[node] ==-1){
		ans = node;
		return;
	}
	if(lnode[node]==-1) dfs(rnode[node], ball);
	else if(rnode[node]==-1) dfs(lnode[node],ball);
	else if(ball%2==0) dfs(rnode[node],ball/2);
	else dfs(lnode[node],(ball+1)/2);


}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lnode[i] >> rnode[i];
	}
	long long k;
	cin >> k;
	dfs(1,k);
	cout << ans;
}