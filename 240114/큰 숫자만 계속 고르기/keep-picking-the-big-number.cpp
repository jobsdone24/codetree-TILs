#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++) {
		int num = pq.top();
		pq.pop();
		num--;
		pq.push(num);
	}
	cout << pq.top();
}