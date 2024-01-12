#include<iostream>
#include<unordered_set>
#define MAX_N 100000
using namespace std;

int people[MAX_N+1];
pair<int, int> change[MAX_N+1];
unordered_set<int> counting[MAX_N+1];

void Seat_Change(int k,int n) {
	for (int i = 0; i < k; i++) {
		int a = change[i].first;
		int b = change[i].second;
		int first = people[a];
		int second = people[b];

		counting[first].insert(b);
		counting[second].insert(a);
		people[a] = second;
		people[b] = first;
	}
}
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		people[i] = i;
		counting[i].insert(i);
	}


	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		change[i] = { a,b };
	
	}
	Seat_Change(k,n);
	Seat_Change(k, n);
	Seat_Change(k, n);

	for (int i = 1; i <= n; i++) {
		cout << counting[i].size() << '\n';
	}
}