#include <iostream>
#include <unordered_map>
#define MAX_N 100000
#define MAX_M 10
using namespace std;

typedef struct Node{
    int num;
    Node* next;
    Node* prev;
};

Node node[MAX_N+10];
unordered_map<int,Node*> info;
int nodecnt;

Node* Head[MAX_M+1];
Node* Tail[MAX_M+1];

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
}

void AddNode(Node* target, Node* start, Node* end){
    Node* prev = target->prev;
    Node* next = target;
    start->prev = prev;
    end->next = next;
    prev->next = start;
    next->prev = end;
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
        Node* start = Head[i]->next;
        if(start == Tail[i]) cout << -1<<"\n"; //사람 없는 경우
        else{
            while(start != Tail[i]){
                cout << start->num<<' ';
                start = start->next;
            }
            cout <<'\n';
        }
    }
}

int main(){
    int Q;
    cin >> N >> M >>Q;
    
   Init();

    for(int i=1;i<=M;i++){
        int num;
        cin >> num;
        for(int j=0;j<num;j++){
            int people;
            cin >> people;
            Node* newnode = getNode(people);
            AddNode(Tail[i], newnode, newnode);
        }
    }

    for(int i=0;i<Q;i++){
        int order;
        cin >> order;
        if(order==1){
            int a,b;
            cin >> a >> b;
            Node* target = info[a];
            Node* cur = info[b];
            DeleteNode(target,target);
            AddNode(cur,target,target);
        }
        else if(order==2){
            int a;
            cin >> a;
            Node* target = info[a];
            DeleteNode(target,target);
            info.erase(a);
        }
        else if(order==3){
            int a,b,c;
            cin >> a >> b >> c;
            Node* st = info[a];
            Node* ed = info[b];
            Node* target = info[c];
            DeleteNode(st,ed);
            AddNode(target,st,ed);
        }
    }
    show();
}