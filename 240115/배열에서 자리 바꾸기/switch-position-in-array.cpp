#include<iostream>
#define MAX_N 250000
using namespace std;

typedef struct Node {
	int num;
	Node* prev;
	Node* nxt;
};

Node* info[MAX_N + 1];
Node node[MAX_N + 5];
Node* Head;
Node* Tail;
int nodecnt;

Node* getNode(int num) {
	node[nodecnt].num = num;
	node[nodecnt].nxt = nullptr;
	node[nodecnt].prev = nullptr;
	return &node[nodecnt++];
}

void Init() {
	nodecnt = 0;
	Head = getNode(-1);
	Tail = getNode(-1);
	Head->nxt = Tail;
	Tail->prev = Head;
}

void AddNode(Node* n) {
	Node* prev = Tail->prev;
	n->nxt = Tail;
	n->prev = prev;
	prev->nxt = n;
	Tail->prev = n;
}

pair<Node*, Node*> CutNode(Node* st, Node* ed) {
	Node* prev = st->prev;
	Node* next = ed->nxt;
	
	st->prev = nullptr;
	ed->nxt = nullptr;

	prev->nxt = next;
	next->prev = prev;
	return { prev, next };
}

void ChangeNode(Node* a, Node* b, Node* c, Node* d) {
	//a~b가 c, d사이로 들어감  c a ~ b d
	a->prev = c;
	b->nxt = d;
	c->nxt = a;
	d->prev = b;
}

void show() {
	Node* cur = Head->nxt;
	while (cur != Tail) {
		cout << cur->num << " ";
		cur = cur->nxt;
	}
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	Init();

	//길이 N짜리 배열 만들기
	for (int i = 1; i <= N; i++) {
		Node* newnode = getNode(i);
		info[i] = newnode;
		AddNode(newnode);
	}
	
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Node* sf = info[a];
		Node* ef = info[b];
		Node* ss = info[c];
		Node* es = info[d];
		//바로 다음인 경우 따로 고려해주기
		if (ef->nxt == ss) {
			pair<Node*, Node*> first = CutNode(sf, ef);
			ChangeNode(sf, ef, es, es->nxt);
		}
		else if (es->nxt == sf) {
			pair<Node*, Node*> second = CutNode(ss, es);
			ChangeNode(ss, es, ef, ef->nxt);
		}
		//한칸 이상 띄어져 있을 경우
		else {
			pair<Node*, Node*> first = CutNode(sf, ef);
			pair<Node*, Node*> second = CutNode(ss, es);
			ChangeNode(sf, ef, second.first, second.second);
			ChangeNode(ss, es, first.first, first.second);
		}
	}

	show();
}