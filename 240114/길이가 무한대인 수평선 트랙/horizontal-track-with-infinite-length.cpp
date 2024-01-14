#include<iostream>
#include<set>
#include<tuple>
#define MAX_N 100000
using namespace std;

int X[MAX_N], V[MAX_N];
set<pair<int, int> > group;
set<tuple<double, int, int> > event_t;

void addEvent(int x0, int v0, int x1, int v1) {
	if (v0 <= v1)return;
	else {
		event_t.insert({ 1.0 * (x1 - x0) / (v0 - v1), x0,v0 });
		return;
	}
}

void eraseEvent(int x0, int v0, int x1, int v1) {
	if (v0 <= v1)return;
	else {
		event_t.erase({ 1.0 * (x1 - x0) / (v0 - v1), x0,v0 });
		return;
	}
}

int main() {
	int N, T;
	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		cin >>X[i] >> V[i];
		group.insert({ X[i],V[i] });
	}

	//만나는 이벤트 만들기
	for (int i = 0; i < N - 1; i++) {
		addEvent(X[i], V[i], X[i + 1], V[i + 1]);
	}

	while (!event_t.empty()) {
		double time;
		int x, v;
		tie(time, x, v) = *event_t.begin();
		if (time > T) break;
		
		//겹치는 이벤트가 발생했을 때  기존 것 갱신
		event_t.erase({ time,x,v });
		group.erase({ x,v });

		auto iter = group.upper_bound({ x,v });
		int nx, nv;
		tie(nx, nv) = *iter;
		if (iter != group.begin()) {
			//이전 것 확인하기
			int px, pv;
			iter--;
			tie(px, pv) = *iter;
			addEvent(px, pv, nx, nv);
			eraseEvent(px, pv, x, v);
		}
	}
	cout << group.size();
}