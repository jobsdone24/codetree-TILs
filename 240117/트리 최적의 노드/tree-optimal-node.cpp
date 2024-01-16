#include<iostream>
#include<vector>
#include<tuple>
#include<string.h>
#include<climits>
#define MAX_N 100000
using namespace std;

vector<pair<int,int> > tree[MAX_N + 1];
bool visited[MAX_N + 1];

pair<int, int> big = { 0,0 };
void Traversal(int num,int worth) {
	for (int i = 0; i < (int)tree[num].size(); i++) {
		//특정 점에서 num을 지날때의 길이는 worth이다.
		if (big.first < worth)big = { worth,num };
		int next, dist;
		tie(next,dist) = tree[num][i]; // 부모 num, 자식 next
		if (visited[next] == false) {
			visited[next] = true;
			Traversal(next, worth+dist);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b,length;
		cin >> a >> b;
		tree[a].push_back({ b,1 });
		tree[b].push_back({ a,1 });
	}

	int small = INT_MAX;
	for(int i=1;i<=n;i++){
		big ={0,0};
		visited[i] = true;
		Traversal(i, 0);
		memset(visited, 0, sizeof(visited));
		if(big.first<small)small = big.first;
	}
	cout << small << "\n";
}