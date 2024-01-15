#include<iostream>
#include<string>
#define MAX_N 100000
using namespace std;

typedef struct Node {
	string name;
	Node* prev;
	Node* next;
};

Node node[2*MAX_N];
Node* Head;
Node* Tail;
Node* pinset;

int citycnt;
int nodecnt;
int N, Q;

Node* getNode(string arr) {
	node[nodecnt].name = arr;
	node[nodecnt].next = nullptr;
	node[nodecnt].prev = nullptr;
	return &node[nodecnt++];
};

void Init() {
	nodecnt = 0;

	//이중 연결리스트
	Head = getNode("head");
	Tail = getNode("tail");
	Head->next = Tail;
	Tail->prev = Head;
}

void AddNode(Node* newnode) {
	Node* prev = Tail->prev;
	newnode->next = Tail;
	newnode->prev = prev;
	prev->next = newnode;
	Tail->prev = newnode;
	citycnt++;
}

void show() {
	if (citycnt <= 2) cout << -1 << '\n';
	else {
		Node* cur = pinset;
		if (cur->prev == Head) cout << Tail->prev->name;
		else cout << cur->prev->name;
		cout << " ";
		if (cur->next == Tail)cout << Head->next->name;
		else cout << cur->next->name;
		cout << "\n";
	}
}

void DeleteNode(Node* dnode) {
	citycnt--;
	Node* next = dnode->next;
	Node* prev = dnode->prev;
	next->prev = prev;
	prev->next = next;
	dnode->next = nullptr;
	dnode->prev = nullptr;
}

int main() {
	cin >> N >> Q;

	//초기값 설정
	Init();

	for (int i = 0; i < N; i++) {
		string n;
		cin >> n;
		Node* newnode = getNode(n);
		AddNode(newnode);
	}
	
	pinset = Head->next; // 첫번째 핀셋 지정해주기
	
	for (int i = 0; i < Q; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			if (citycnt > 1) {
				if (pinset->next == Tail)pinset = Head->next;
				else pinset = pinset->next;
			}
		}
		else if (num == 2) {
			if (citycnt > 1) {
				if (pinset->prev == Head) pinset = Tail->prev;
				else pinset = pinset->prev;
			}
		}
		else if (num == 3) {
			if (citycnt > 1) {
				//도시 제거하기
				Node* target;
				if (pinset->next == Tail) target = Head->next;
				else target = pinset->next;
				DeleteNode(target);
			}
		}
		else if (num == 4) {
			string arr;
			cin >> arr;
			citycnt++;
			Node* newnode = getNode(arr);
			newnode->next = pinset->next;
			newnode->prev = pinset;
			pinset->next->prev = newnode;
			pinset->next = newnode;
		}
		show();
	}	
}