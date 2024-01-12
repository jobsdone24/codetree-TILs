#include<iostream>
#include<unordered_set>
#define MAX_N 200000
using namespace std;


int main() {
	unordered_set<int> A;
	unordered_set<int> dap;
	int n, m;
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.insert(num);
		dap.insert(num);
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if(A.find(num)== A.end()){
			dap.insert(num);
		}
		else dap.erase(num);
	}
	cout << dap.size();
}