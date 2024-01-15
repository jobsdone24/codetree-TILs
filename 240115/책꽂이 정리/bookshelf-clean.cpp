#include<iostream>
#define MAX_N 250000
#define MAX_K 100
using namespace std;

typedef struct Node {
	int num;
	Node* prev;
	Node* nxt;
};

Node node[MAX_N + 2*MAX_K+1];
Node* Head[MAX_K+1];
Node* Tail[MAX_K+1];
int nodecnt;
int N, K;
int BookCnt[MAX_K + 1];

void show() {
	for (int i = 1; i <= K; i++) {
		cout << BookCnt[i] << " ";
		Node* cur = Head[i]->nxt;
		while (cur != Tail[i]) {
			cout << cur->num << " ";
			cur = cur->nxt;
		}
		cout << "\n";
	}
}

Node* getNode(int num) {
	node[nodecnt].num = num;
	node[nodecnt].nxt = nullptr;
	node[nodecnt].prev = nullptr;
	return &node[nodecnt++];
}

void AddBackNode(int k ,Node* newnode) {
	//k번째 책꽂이에 newnode 넣기
	Node* pnode = Tail[k]->prev;
	newnode->nxt = Tail[k];
	newnode->prev = pnode;
	pnode->nxt = newnode;
	Tail[k]->prev = newnode;
}

void AddFrontNode(int k, Node* newnode) {
	Node* nnode = Head[k]->nxt;
	newnode->nxt = nnode;
	newnode->prev = Head[k];
	nnode->prev = newnode;
	Head[k]->nxt = newnode;
}

void Init() {
	nodecnt = 0;
	for (int i = 1; i <= K; i++) {
		Head[i] = getNode(-1);
		Tail[i] = getNode(-1);
		Head[i]->nxt = Tail[i];
		Tail[i]->prev = Head[i];
	}
	
	// 1번 책꽂이에 다 꽂기
	for (int i = 1; i <= N; i++) {
		Node* newnode = getNode(i);
		AddBackNode(1, newnode);
	}
	BookCnt[1] = N;
}

void DeleteNode(Node* d) {
	Node* nnode = d->nxt;
	Node* pnode = d->prev;
	nnode->prev = pnode;
	pnode->nxt = nnode;
	d->nxt = nullptr;
	d->prev = nullptr;
}

void ChangeNode(int num, Node* starget, Node* etarget) {
	//i번째 책꽂이의 책을 target 사이로 두기
	
	//해당 책꽂이에서 삭제하기
	Node* start = Head[num]->nxt;
	Node* end = Tail[num]->prev;

	Head[num]->nxt = Tail[num];
	Tail[num]->prev = Head[num];

	//새로 연결해주기
	starget->nxt = start;
	start->prev = starget;

	etarget->prev = end;
	end->nxt = etarget;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	Init();
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int order, a, b;
		cin >> order >> a >> b;
		if (order == 1) {
			//책 유무 확인
			if (BookCnt[a]==0) continue;
			else {
				Node* cur = Head[a]->nxt;
				DeleteNode(cur);
				AddBackNode(b, cur);
				BookCnt[a]--;
				BookCnt[b]++;
			}
		}
		else if (order == 2) {
			//책 유무 확인
			if (BookCnt[a] == 0) continue;
			else {
				Node* cur = Tail[a]->prev;
				DeleteNode(cur);
				AddFrontNode(b, cur);
				BookCnt[a]--;
				BookCnt[b]++;
			}
		}
		else if (order == 3) {
			if (a == b || BookCnt[a]==0) continue;
			else {
				Node* st = Head[b];
				Node* et = Head[b]->nxt;
				ChangeNode(a, st, et);
				BookCnt[b] += BookCnt[a];
				BookCnt[a] = 0;
			}
		}
		else if (order == 4) {
			if (a == b|| BookCnt[a]==0) continue;
			else {
				Node* st = Tail[b]->prev;
				Node* et = Tail[b];
				ChangeNode(a, st, et);

				BookCnt[b] += BookCnt[a];
				BookCnt[a] = 0;
			}
		}
	}
	show();
}