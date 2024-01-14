#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> pluspq;
priority_queue<int> minuspq;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pluspq.empty() && minuspq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			else if(pluspq.empty()){
				cout << -minuspq.top() << "\n";
				minuspq.pop();
				continue;
			}
			else if (minuspq.empty()) {
				cout << -pluspq.top() << "\n";
				pluspq.pop();
				continue;
			}
            else{
			int num = -pluspq.top(); //절대값
			int num2 = -minuspq.top(); //절대값
			if (num >= num2) {
				cout << -num2 << "\n";
				minuspq.pop();
			}
			else {
				cout << num << "\n";
				pluspq.pop();
			}
            }
		}
		else if (x > 0) pluspq.push(-x);
		else minuspq.push(x);

	}
}