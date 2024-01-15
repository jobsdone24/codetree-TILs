#include<iostream>
#include<string>

#define MAX_N 250000
using namespace std;

typedef struct Node{
	string str;
	Node* prev;
	Node* nxt;
};

Node node[MAX_N];
int nodecnt;
Node* cur; //현재 중심 주소

Node* getNode(string arr) {
	node[nodecnt].str = arr;
	node[nodecnt].nxt = nullptr;
	node[nodecnt].prev = nullptr;
	return &node[nodecnt++];
}

void PushFront(Node* n) {
	//이전이 null인 경우
	if (cur->prev == nullptr) {
		n->nxt = cur;
		cur->prev = n;
	}
	else {
		Node* prv = cur->prev;
		n->nxt = cur;
		n->prev = prv;
		cur->prev = n;
		prv->nxt = n;
	}
}

void PushBack(Node* n) {
	//이전이 null인 경우
	if (cur->nxt == nullptr) {
		n->prev = cur;
		cur->nxt = n;
	}
	else {
		Node* next = cur->nxt;
		n->prev = cur;
		n->nxt = next;
		cur->nxt = n;
		next->prev= n;
	}
}

int main() {
	string s_init;
	cin >> s_init;
	int N;
	cin >> N;
	cur = getNode(s_init);
	
	for (int i = 0; i < N; i++) {
		int order;
		cin >> order;
		if (order == 1) {
			string arr;
			cin >> arr;
			Node* temp = getNode(arr);
			
			//노드 cur 앞에 삽입하기
			PushFront(temp);
		}
		else if (order == 2) {
			string arr;
			cin >> arr;
			Node* temp = getNode(arr);
			
			//노드 cur 뒤에 삽입하기
			PushBack(temp);
		}
		else if (order == 3) {
			if (cur->prev != nullptr) cur = cur->prev;
		}
		else if (order == 4) {
			if (cur->nxt != nullptr) cur = cur->nxt;
		}

		//이전
		if (cur->prev == nullptr)cout << "(Null) ";
		else cout << cur->prev->str << ' ';
		//cur
		cout << cur->str << " ";
		//다음
		if (cur->nxt == nullptr)cout << "(Null) ";
		else cout << cur->nxt->str << ' ';
        cout <<"\n";
	}
}