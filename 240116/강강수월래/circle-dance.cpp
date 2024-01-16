#include <iostream>
#include <unordered_map>
#define MAX_N 100000
#define MAX_M 10
#define MAX_Q 10000
using namespace std;

typedef struct Node{
    int num;
    Node* next;
    Node* prev;
};

Node node[MAX_N+2*(MAX_Q+MAX_M)];
unordered_map<int,Node*> info;
unordered_map<int,int> cinfo;
int nodecnt;

Node* Head[MAX_Q+MAX_M+1];
Node* Tail[MAX_Q+MAX_M+1];
int circlecnt;
int N,M;

Node* getNode(int num){
    node[nodecnt].num = num;
    node[nodecnt].prev = nullptr;
    node[nodecnt].next = nullptr;
    info[num] = &node[nodecnt];
    return &node[nodecnt++];
}

void Init(){
    nodecnt = 0;
    for(int i=1;i<=M;i++){
        Head[i] = getNode(-1);
        Tail[i] = getNode(-1);
        Head[i]->next = Tail[i];
        Tail[i]->prev = Head[i];
    }
    circlecnt = M;
}

void AddNode(Node* target, Node* start, Node* end){
    Node* prev = target->prev;
    Node* next = target;
    start->prev = prev;
    end->next = next;
    prev->next = start;
    next->prev = end;
}

void NodeChange(int num, Node* s, Node* e){
    Node* cur = s;
    while(cur != e){    
        int n = cur->num;
        cinfo[n] = num;
        cur = cur->next;
    }
    cinfo[cur->num] = num;
}
void DeleteNode(Node* ds, Node* de){
    Node* next = de->next;
    Node* prev = ds->prev;
    next->prev = prev;
    prev->next = next;
    de->next = nullptr;
    ds->prev = nullptr;
}

void show(){
    for(int i=1;i<=M;i++){
        Node* cur = Head[i]->next;
        while(cur != Tail[i]){
            cout << cur->num<<" ";
            cur = cur->next;
        }
        cout<<"\n";
    }
}

int main(){
    ios::base_sync_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> N >> M >>Q;
    
    Init();

    // 원 초기화 하기
    for(int i=1;i<=M;i++){
        int num;
        cin >> num;
        for(int j=0;j<num;j++){
            int people;
            cin >> people;
            cinfo[people] = i; //각 people이 몇번째 circle에 있는지 확인
            Node* newnode = getNode(people);
            AddNode(Tail[i], newnode, newnode);
        }
    }

    show();
    for(int i=0;i<Q;i++){
        int order;
        cin >> order;
        if(order==1){
            int a,b;
            cin >> a >> b;
            Node* target = info[a];
            Node* cur = info[b];
            int tcircle = cinfo[a];
            int circle = cinfo[b];
            Node* start = cur;
            Node* end;
            if(start->prev == Head[circle]) end = Tail[circle]->prev;
            else end = start->prev;
            //바꾸는 노드 변화
            NodeChange(tcircle,start,end);
            DeleteNode(start,end);
            AddNode(target->next,start,ed);
        }
        else if(order==2){
            int a,b;
            cin >> a >> b;
            //Node* target = info[a];
            //DeleteNode(target,target);
        }
        else if(order==3){
            int a;
            cin >> a;
        }
    }
    show();
}