#include<iostream>
#include<string>
#include<unordered_map>
#define MAX_N 100000
using namespace std;

typedef struct Node {
	int num;
	Node* prev;
	Node* next;
};

Node node[MAX_N];
Node* Head;
Node* Tail;
unordered_map<int, Node*> info;

int citycnt;
int nodecnt;
int Q;
int cnt;

Node* getNode(int arr) {
	node[nodecnt].num = arr;
	node[nodecnt].next = nullptr;
	node[nodecnt].prev = nullptr;
	info[arr] = &node[nodecnt];
	return &node[nodecnt++];
};

void Init() {
	nodecnt = 0;

	//이중 연결리스트
	Head = getNode(-1);
	Tail = getNode(-1);
	Head->next = Tail;
	Tail->prev = Head;

	//1번학생 집어넣기
	Node* first = getNode(++cnt);
	AddNode(Tail->prev,first);
}

void AddNode(Node* start,Node* newnode) {
	Node* st = start;
	Node* ed = start->next;
	newnode->next = ed;
	newnode->prev = st;
	st->next = newnode;
	ed->prev = newnode;
}

void AddFrontNode(Node* target, Node* newnode) {
	Node* st = target->prev;
	Node* ed = target;
	newnode->next = ed;
	newnode->prev = st;
	st->next = newnode;
	ed->prev = newnode;
}


void DeleteNode(Node* dnode) {
	Node* next = dnode->next;
	Node* prev = dnode->prev;
	next->prev = prev;
	prev->next = next;
	dnode->next = nullptr;
	dnode->prev = nullptr;
}

int main() {
	cin >> Q;

	//초기값 설정
	Init();

	for (int i = 0; i < Q; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			int a, b;
			cin >> a >> b;
			// b명의 학생 줄 세우기

			Node* start;
			Node* end;

			for (int j = 0; j < b; j++) {
				Node* newnode = getNode(++cnt);
				if (j == 0) start = newnode;
				if (j == b - 1) end = newnode;
				
				AddNode(target, newnode);
			}
		}
		else if (num == 2) {
			int a, b;
			cin >> a >> b;
			// b명의 학생 줄 세우기
			for (int j = 0; j < b; j++) {
				Node* newnode = getNode(++cnt);
				Node* target = info[a];
				AddFrontNode(target, newnode);
			}
		}
		else if (num == 3) {
			int a;
			cin >> a;
			Node* cur = info[a];
			if (cur->prev == Head || cur->next == Tail) cout << -1 << '\n';
			else cout << cur->prev->num << ' ' << cur->next->num << '\n';
		}
	}
}