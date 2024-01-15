#include<iostream>
#include<queue>
#include<tuple>
#include<functional>
#include<climits>
#define MAX_N 100000
#define MAX_T 10000
using namespace std;

typedef struct {
	int start;
	int time;
	int num;
}s;

struct compare {
	bool operator()(s a, s b) {
		if (a.start == b.start) {
			return a.num > b.num;
		}
		return a.start > b.start;
	}
};


pair<int, int> info[MAX_N]; //도착 머무름 시간
priority_queue<int, vector<int>, greater<int> > wqueue;
priority_queue<s, vector<s>, compare> timecheck;
int big = INT_MIN;
int totaltime;
int cnt = 0;

void Arrive(int time) {
	//time 시간 내에 도착한 사람들 확인
	while (!timecheck.empty()) {
		s temp = timecheck.top();
		if (temp.start <= time) {
			wqueue.push(temp.num); // 다음 번호로 넣어주기
			timecheck.pop();
		}
		else break;
	}
}

void Entrance() {
	//대기하고 있는 wqueue에서 비교해서 넣어주기
	if (!wqueue.empty()) {
		cnt++;
		int num = wqueue.top();
		wqueue.pop();
		//num 사람 들어감

		int temptime = totaltime - info[num].first;
		totaltime += info[num].second; //시간 추가
		if (big < temptime) big = temptime;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, t;
		cin >> a >> t;
		info[i] = { a,t };
		timecheck.push({ a,t,i });
	}

	while (!timecheck.empty()) {
		if (wqueue.empty()) {
			s temp = timecheck.top();
			timecheck.pop();
			wqueue.push(temp.num);
			if (totaltime < temp.start)totaltime = temp.start;
		}
		Arrive(totaltime);
		Entrance();	
	}

	while (cnt != N) Entrance();
	cout << big;
}