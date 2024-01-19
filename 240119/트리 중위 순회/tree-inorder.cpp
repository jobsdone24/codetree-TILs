#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int arr[1200];
vector<int> s[10];
void inorder(int start, int end,int step) {
	if (start > end)return;
	int mid = (start + end) / 2;
	s[step].push_back(arr[mid]);
	inorder(start, mid - 1,step+1);
	inorder(mid + 1, end, step + 1);
}

int main() {
	int n;
	cin >> n;
	
	int su = pow(2, n) - 1;
	for (int i = 0; i < su; i++) cin >> arr[i];
	inorder(0, su-1,0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			cout << s[i][j] << " ";
		}cout << "\n";
	}
}