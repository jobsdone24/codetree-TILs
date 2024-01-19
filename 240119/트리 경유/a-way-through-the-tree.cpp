#include<iostream>
#include<unordered_set>
#include<stack>
using namespace std;
unordered_set<int> s;
int test(int x) {
	int ret = 0;
    while(x){
        if(s.find(x) !=s.end()){
            ret = x;
        }
        x /=2;

    }
    return ret;
}
int main() {
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		int t = test(num);
        if(t==0)s.insert(num);
		cout << t<<'\n';
	}
}