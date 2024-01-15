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
int N, M;

Node* getNode(int arr) {
	node[nodecnt].num = arr;
	node[nodecnt].next = nullptr;
	node[nodecnt].prev = nullptr;
	return &node[nodecnt++];
};

void Init() {
	nodecnt = 0;

	//이중 연결리스트
	Head = getNode(-1);
	Tail = getNode(-1);
	Head->next = Tail;
	Tail->prev = Head;
}

void AddNode(Node* newnode) {
	Node* prev = Tail->prev;
	newnode->next = Tail;
	newnode->prev = prev;
	prev->next = newnode;
	Tail->prev = newnode;
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
	cin >> N >> M;

	//초기값 설정
	Init();

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		Node* newnode = getNode(num);
		AddNode(newnode);
		info[num] = newnode; //주소 저장
	}
	
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		Node* cur = info[num];
		//왼쪽
		if (cur->next == Tail) cout << Head->next->num;
		else cout << cur->next->num;

		cout << ' ';

		//오른쪽
		if (cur->prev == Head) cout << Tail->prev->num;
		else cout << cur->prev->num;
		//삭제
		DeleteNode(cur);
		info.erase(num);
		cout << '\n';
	}	
}