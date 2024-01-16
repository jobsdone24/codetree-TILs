#include <iostream>
#include <unordered_map>
#include <string>
#define MAX_N 100000
#define MAX_M 10
using namespace std;

typedef struct Node{
    string name;
    Node* next;
    Node* prev;
};

Node node[MAX_N+10];
unordered_map<string,Node*> info;
int nodecnt;

Node* Head[MAX_M+1];
Node* Tail[MAX_M+1];

int N,M;

Node* getNode(string arr){
    node[nodecnt].name = arr;
    node[nodecnt].prev = nullptr;
    node[nodecnt].next = nullptr;
    info[arr] = &node[nodecnt];
    return &node[nodecnt++];
}

void Init(){
    nodecnt = 0;
    for(int i=1;i<=M;i++){
        Head[i] = getNode("head");
        Tail[i] = getNode("tail");
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
                cout << start->name<<' ';
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

    int k = 0;
    int cnt = N/M;
    int line = 1;
    for(int i=1;i<=N;i++){
       string name;
        cin >> name;
        k++;
        Node* newnode = getNode(name);
        AddNode(Tail[line],newnode,newnode);
        if(k==cnt){
            line++;
            k=0;
        }
    }
    for(int i=0;i<Q;i++){
        int order;
        cin >> order;
        if(order==1){
            string a,b;
            cin >> a >> b;
            Node* target = info[a];
            Node* cur = info[b];
            DeleteNode(target,target);
            AddNode(cur,target,target);
        }
        else if(order==2){
            string a;
            cin >> a;
            Node* target = info[a];
            DeleteNode(target,target);
            info.erase(a);
        }
        else if(order==3){
            string a,b,c;
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