#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<tuple<int, int, int> > pq;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ -(x + y),-x,-y });
	}
	for (int i = 0; i < m; i++) {
		int hap, xx, yy;
		tie(hap, xx, yy) = pq.top();
		pq.pop();
		pq.push({ hap - 4,xx - 2,yy - 2 });
	}
	int dx, dy;
	tie(ignore, dx, dy) = pq.top();
	cout << -dx << " " << -dy << "\n";
}