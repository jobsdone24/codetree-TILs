/*

	- rc x : x가 1인 경우 난이도가 가장 높은 문제의 번호 출력 (가장 문제 번호 높은것)
			 x가 -1인 경우 가장 낮은 문제 번호 출력( 문제 번호 작은것)

	- ap P L: 난이도 L 문제번호 P 추가

	- sv P L : 난이도가 L인 문제 번호 P 제거
	
	set을 사용해야 하는 이유 -> 난이도 별 문제 최대값, 최소값을 자주 참조해야 하기 때문

*/

#include<iostream>
#include<set>
#define MAX_N 100000

using namespace std;

int main() {
	int n;
	cin >> n;
	set<pair<int, int> > s;

	for (int i = 0; i < n; i++) {
		int L, P;
		cin >> P>> L;
		s.insert({ L,P });
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char arr[3];
		cin >> arr;

		if (arr[0] == 'r') {
			int x;
			cin >> x;

			if (x == 1) {
				cout << s.rbegin()->second << '\n';
			}
			else cout << s.begin()->second << "\n";
		}
		else if (arr[0] == 'a') {
			int p, l;
			cin >> p >> l;
			s.insert({ l,p });
		}
		else if (arr[0] == 's') {
			int p, l;
			cin >> p >> l;
			s.erase({ l,p });
		}
	}
}