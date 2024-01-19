#include<iostream>
#include<unordered_set>
#include<stack>
using namespace std;
unordered_set<int> s;
int test(int x) {
	stack<int> st;
	int num = x;
	st.push(num);
	while (num > 1) {
		num /= 2;
		st.push(num);
	}
	
	//stack에서 빼내기
	while (!st.empty()) {
		int n = st.top();
		st.pop();
		if (s.find(n) != s.end()) return n;
	}
	return 0;
}
int main() {
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		int t = test(num);
		if (t == 0) s.insert(num);
		cout << t<<'\n';
	}
}