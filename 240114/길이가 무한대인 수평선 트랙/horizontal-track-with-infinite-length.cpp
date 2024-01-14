#include<iostream>
#include<set>
#include<tuple>
#define MAX_N 100000
using namespace std;

set<pair<int, int> > group;
int x[MAX_N], v[MAX_N];


//앞에 있는 사람을 따라잡는 경우 event 등록하기 시간 전에 있는 사람 정보
set<tuple<double, int, int>> event_t;

void addEvent(int x0, int v0, int x1, int v1) {
	if (v0 <= v1) return;
	else {
		event_t.insert(make_tuple(1.0 * (x1 - x0) / (v0 - v1), x0, v0));
		return;
	}
}

void eraseEvent(int x0, int v0, int x1, int v1) {
	if (v0 <= v1) return;
	else {
		event_t.erase(make_tuple(1.0 * (x1 - x0) / (v0 - v1), x0, v0));
		return;
	}
}

int main() {
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> v[i];
		group.insert({ x[i],v[i] });
	}

	//전에 사람이 다음 사람을 따라잡는 event 등록
	for (int i = 0; i < N - 1; i++) {
		addEvent(x[i], v[i], x[i + 1], v[i + 1]);
	}

	//event에는 가장 짧은 순서로 저장되어 있음 앞지르는 사건이 있으면 반복
	while (!event_t.empty()) {
		double t;
		int a, b;
		tie(t, a, b) = *event_t.begin(); //가장 빨리 만나는 두 경우
		if (t > T) break; // 처음으로 범위를 벗어나면 out 시켜주기

		//만난 경우 각 group과 event 갱신해주기
		group.erase({ a,b });
		event_t.erase({ t,a,b });

		//이전 이전에 있는 사람 확인하기
		auto iter = group.upper_bound({ a,b });
		if (iter != group.begin()) {
			iter--;
			int aa, bb;
			tie(aa, bb) = *iter;
			eraseEvent(aa, bb, a, b);
			addEvent(aa, bb, iter->first, iter->second);
		}
	}
	cout << (int)group.size();
}