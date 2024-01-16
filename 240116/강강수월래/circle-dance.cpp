#include <iostream>
#include <unordered_map>
#include<climits>
#define MAX_N 100000
#define MAX_M 10
#define MAX_Q 10000
using namespace std;

typedef struct Node {
    int num;
    Node* next;
    Node* prev;
};

Node node[MAX_N + MAX_M];
int nodecnt;
unordered_map<int, Node*> info;
//unordered_map<int, int> cinfo;
//Node* Head[MAX_Q + MAX_M + 1];
//Node* Tail[MAX_Q + MAX_M + 1];
int circlecnt;
int N, M;

Node* getNode(int num) {
    node[nodecnt].num = num;
    node[nodecnt].prev = nullptr;
    node[nodecnt].next = nullptr;
    info[num] = &node[nodecnt];
    return &node[nodecnt++];
}

void Init() {
    nodecnt = 0;
    /*for (int i = 1; i <= M; i++) {
        Head[i] = getNode(-1);
        Tail[i] = getNode(-1);
        Head[i]->next = Tail[i];
        Tail[i]->prev = Head[i];
    }
    circlecnt = M;
    */
}

//타겟 앞에 추가
void AddFrontNode(Node* target, Node* start, Node* end) {
    Node* prev = target->prev;
    Node* next = target;
    start->prev = prev;
    end->next = next;
    prev->next = start;
    next->prev = end;
}

//타겟 뒤에 추가
void AddBackNode(Node* target, Node* start, Node* end) {
    Node* prev = target;
    Node* next = target->next;
    start->prev = prev;
    end->next = next;
    prev->next = start;
    next->prev = end;
}

/*void NodeChange(int num, Node* s, Node* e) {
    Node* cur = s;
    while (cur != e) {
        int n = cur->num;
        cinfo[n] = num;
        cur = cur->next;
    }
    cinfo[cur->num] = num;
}
*/

void DeleteNode(Node* ds, Node* de) {
    Node* next = de->next;
    Node* prev = ds->prev;
    next->prev = prev;
    prev->next = next;
    de->next = nullptr;
    ds->prev = nullptr;
}

void show(int num) {
    cout << num << "이 포함된 원 순환 시작!\n";
    Node* target = info[num];
    Node* cur = target;
    cout << cur->num << " ";
    cur = cur->next;
    while (cur != target) {
        cout << cur->num << " ";
        cur = cur->next;
    }
    cout << "\n";
}

int SmallNumNode(int num) {
    Node* target = info[num];
    Node* cur = target;
    int small = INT_MAX;
    if (cur->num < small) small = cur->num;
    cur = cur->next;
    while (cur != target) {
        int temp = cur->num;
        if (temp < small) small = temp;
        cur = cur->next;
    }
    return small;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> N >> M >> Q;

    Init();

    // 원 초기화 하기
    for (int i = 1; i <= M; i++) {
        int num;
        cin >> num;

        if (num == 0) continue;
        //처음 원 초기화 하기
        int sp;
        cin >> sp;
        Node* start = getNode(sp);
        Node* cur = start;

        for (int j = 1; j < num; j++) {
            int people;
            cin >> people;
            //cinfo[people] = i; //각 people이 몇번째 circle에 있는지 확인
            Node* newnode = getNode(people);
            cur->next = newnode;
            newnode->prev = cur;
            cur = cur->next;
        }
        
        //원형 이중 연결리스트로 만들어주기
        cur->next = start;
        start->prev = cur;
    }

    for (int i = 0; i < Q; i++) {
        int order;
        cin >> order;
        if (order == 1) {
            int a, b;
            cin >> a >> b;
            
            //a의 주소값
            Node* anode = info[a];

            //b의 주소값, b바로 전의 주소값 
            Node* bstart = info[b];
            Node* bend = bstart->prev;
            
            AddBackNode(anode, bstart, bend);
        }
        else if (order == 2) {
            int a, b;
            cin >> a >> b;
            Node* anode = info[a];
            Node* bnode = info[b];

            Node* start = anode;
            Node* end = bnode->prev;

            //DeleteNode 해주기
            DeleteNode(start, end);

            //잘려 나간 걸 바탕으로 원형 이중 연결리스트 만들기
            end->next = start;
            start->prev = end;
        }
        else if (order == 3) {
            int a;
            cin >> a;
            int target = SmallNumNode(a);
            Node* start = info[target];
            Node* cur = start;

            //start를 기준으로 반시계 방향으로 돌기
            cout << cur->num<<" ";
            cur = cur->prev;
            while (cur != start) {
                cout << cur->num << " ";
                cur = cur->prev;
            }
        }
    }
}