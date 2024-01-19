#include<iostream>
#define MAX_N 1000
using namespace std;

int a[MAX_N+1];
int par[MAX_N+1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	int finding_node;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] == k) finding_node = i;
	}

	int idx = 0;

	for(int i=2;i<=n;i++){
		if(a[i]> a[i-1]+1) idx++;
		par[i] = idx;
	}

	int ans=0;
	for(int i=1;i<=n;i++){
		if(!par[par[i]] || !par[par[finding_node]])continue;
		if(par[i] != par[finding_node] && par[par[i]] == par[par[finding_node]])ans++;
	}
	cout << ans;
}