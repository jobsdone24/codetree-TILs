#include<iostream>

#define MAX_N 100000
#define MAX_Q 400000
using namespace std;

typedef struct Node {
	int num;
	Node* prev;
	Node* nxt;
};

Node* info[MAX_N + 1];
Node node[MAX_N + 5];
int nodecnt;

Node* getNode(int num) {
	node[nodecnt].num = num;
	node[nodecnt].nxt = nullptr;
	node[nodecnt].prev = nullptr;
	return &node[nodecnt++];
}

//노드 빼내기
void DeleteNode(int num) {
	Node* dnode = info[num];

	if (dnode->nxt == nullptr && dnode->prev == nullptr) return;
	else if (dnode->nxt == nullptr) {
		dnode->prev->nxt = nullptr;
		dnode->prev = nullptr;
	}
	else if (dnode->prev == nullptr) {
		dnode->nxt->prev = nullptr;
		dnode->nxt = nullptr;
	}
	else {
		dnode->nxt->prev = dnode->prev;
		dnode->prev->nxt = dnode->nxt;
		dnode->nxt = nullptr;
		dnode->prev = nullptr;
	}
	return;
}

void InsertFront(int n1, int n2) {
	Node* cur = info[n1];
	Node* inode = info[n2];
	
	//cur노드 앞에 없는 경우
	if (cur->prev == nullptr) {
		inode->nxt = cur;
		cur->prev = inode;
	}
	//있는 경우
	else {
		inode->nxt = cur;
		inode->prev = cur->prev;
		cur->prev->nxt = inode;
		cur->prev = inode;
	}
}

void InsertEnd(int n1, int n2) {
	Node* cur = info[n1];
	Node* inode = info[n2];

	//cur 노드 뒤가 없는 경우
		//cur노드 앞에 없는 경우
	if (cur->nxt == nullptr) {
		inode->prev = cur;
		cur->nxt= inode;
	}
	//있는 경우
	else {
		inode->prev = cur;
		inode->nxt = cur->nxt;
		cur->nxt->prev = inode;
		cur->nxt = inode;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		Node* newnode = getNode(i);
		info[i] = newnode;
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int order;
		cin >> order;
		if (order == 1) {
			int num;
			cin >> num;
			DeleteNode(num);
		}
		else if (order == 2) {
			int a, b;
			cin >> a >> b;
			InsertFront(a, b);
		}
		else if (order == 3) {
			int a, b;
			cin >> a >> b;
			InsertEnd(a, b);
		}
		else if (order == 4) {
			int a;
			cin >> a;
			Node* temp = info[a];
			//이전 정보
			if (temp->prev == nullptr) cout << 0 << " ";
			else cout << temp->prev->num << " ";

			//다음 정보
			if (temp->nxt == nullptr) cout << 0 << " ";
			else cout << temp->nxt->num << " ";
			cout << "\n";
		}
	}
	for (int i = 1; i <= N; i++) {
		Node* temp = info[i];
		if (temp->nxt == nullptr)cout << 0 << " ";
		else cout << temp->nxt->num << " ";
	}
}