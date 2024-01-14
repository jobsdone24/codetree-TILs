#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
    cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (pq.size() >= 2) {
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		if (n1 == n2) continue;
		pq.push(n1 - n2);
	}
	if (pq.empty())cout << -1;
	else cout << pq.top();
}