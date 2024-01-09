#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
	string a;
	cin >> a;
	
	unordered_map<int, int> count;
	int size = a.size();

	for (int i = 0; i < size; i++) {
		count[a[i]]++;
	}

	int flag = 0;
	for (int i = 0; i < size; i++) {
		if (count[a[i]] == 1) {
			cout << a[i];
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		cout << "None";
	}
}