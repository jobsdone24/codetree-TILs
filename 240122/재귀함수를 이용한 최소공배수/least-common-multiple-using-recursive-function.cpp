#include<iostream>

using namespace std;

int N;
int first_num;
int tmp;

//a가 더 큰수
int fnd(int a, int b, int n) {
	if (((a * n) % b) == 0) return a*n;
	else return fnd(a, b, n + 1);
}

int main(void) {

	cin >> N;

	cin >> first_num;

	for (int i = 1; i < N; i++) {
		cin >> tmp;

		if (first_num > tmp) {
			first_num = fnd(first_num, tmp, 1);
		}
		else {
			first_num = fnd(tmp, first_num, 1);
		}
	}

	cout << first_num;


	return 0;
}