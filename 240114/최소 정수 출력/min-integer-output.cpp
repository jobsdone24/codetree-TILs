#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int,vector<int>, greater<int> > pq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > 0) pq.push(num);
		else {
            if(pq.empty()) cout << "0\n";
            else{
			cout << pq.top() << "\n";
			pq.pop();
            }
        }
	}
}