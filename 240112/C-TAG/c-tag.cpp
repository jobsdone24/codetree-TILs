#include<iostream>
#include<unordered_set>
#include<string>
#define MAX_N 500
#define MAX_M 50

using namespace std;
string A[MAX_N + 1];
string B[MAX_N + 1];
int n, m;
int visited[MAX_M];
int sunseo[MAX_M];
int ans;
void Sellect(int depth, int k) {
	//m개를 다 선택했을 경우
	if (depth == 3) {
		//처리하기
		unordered_set<string> play;

		for (int i = 0; i < n; i++) {
			string hap = "";
			for (int j = 0; j < 3; j++) {
				int ss = sunseo[j];
				hap += A[i][ss];
			}
			play.insert(hap);
		}

		//b와 비교
		bool flag = false;
		for (int i = 0; i < n; i++) {
			string hap = "";
			if (flag)break;
			for (int j = 0; j < 3; j++) {
				int ss = sunseo[j];
				hap += B[i][ss];
			}
			if (play.find(hap) != play.end()) {
				flag = true;
				break;
			}
		}

		if (flag == false) ans++;
		return;
	}
	for (int i = k; i < m; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			sunseo[depth] = i;
			Sellect(depth + 1, i);
			visited[i] = 0;
		}
	}
}

int main() {	
	cin >> n >> m;
	//A입력 받기
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		A[i] = temp;
	}

	//B입력 받기
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		B[i] = temp;
	}

	//50 C 3구하기
	Sellect(0, 0);
	
	cout << ans;
}