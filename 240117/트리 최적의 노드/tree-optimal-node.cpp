#include<iostream>
#include<vector>
#include<tuple>
#include<string.h>
#define MAX_N 10000
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
		int a, b;
		cin >> a >> b;
		tree[a].push_back({ b,1 });
		tree[b].push_back({ a,1 });
	}

	//1번 노드에서 거리구하기

	visited[1] = true;
	Traversal(1, 0);
	
	int num = big.second;

	memset(visited, 0, sizeof(visited));
	visited[num] = true;
	Traversal(num, 0);
	cout << (big.first+1)/2 << "\n";
}