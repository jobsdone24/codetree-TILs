#include<iostream>
#include<vector>
using namespace std;

int leftchild[30];
int rightchild[30];

void preorder(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(leftchild[x]);
	preorder(rightchild[x]);
}

void inorder(int x) {
	if (x == -1)return;

	inorder(leftchild[x]);
	cout << (char)(x + 'A');
	inorder(rightchild[x]);
}

void postorder(int x) {
	if (x == -1)return;
	postorder(leftchild[x]);
	postorder(rightchild[x]);
	cout << (char)(x + 'A');
}
int main() {
	int n;
	cin >> n;

	//초기화

	for (int i = 0; i < n; i++) {
		leftchild[i] = -1;
		rightchild[i] = -1;
	}


	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') leftchild[a - 'A'] = b-'A';
		if (c != '.') rightchild[a - 'A'] = c-'A';
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << "\n";
	return 0;
}