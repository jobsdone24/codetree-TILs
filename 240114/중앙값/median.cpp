#include<iostream>
#include<queue>
using namespace std;

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		priority_queue<int> small;
		priority_queue<int> big;
		int middle;
		int m;
		cin >> m;

		cin >> middle;
		cout << middle << " ";
		for (int i = 1; i < m; i++) {
			int num;
			cin >> num;
			if (num >= middle) big.push(-num);
			else small.push(num);

			//홀수번째 인 경우
			if (i % 2 == 0) {
				if (small.size() < big.size()) {
					int num = -big.top();
					big.pop();
					small.push(middle);
					middle = num;
				}
				else if(small.size()>big.size()){
					int num = small.top();
					small.pop();
					big.push(-middle);
					middle = num;
				}
				cout << middle << " ";
			}
		}
		cout << "\n";
	}
}