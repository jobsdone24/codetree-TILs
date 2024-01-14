#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		char arr[10];
		cin >> arr;
		if (arr[0] == 'p' && arr[1] == 'u') {
			int x;
			cin >> x;
			pq.push(x);
		}
		else if (arr[0] == 'p' && arr[1] == 'o') {
			cout << pq.top()<<"\n";
			pq.pop();
		}
		else if (arr[0] == 's') cout << pq.size() << "\n";
		else if (arr[0] == 'e') {
			if (pq.empty())cout << 1 << '\n';
			else cout << 0 << "\n";
		}
		else {
			cout << pq.top() << "\n";
		}
	}
}