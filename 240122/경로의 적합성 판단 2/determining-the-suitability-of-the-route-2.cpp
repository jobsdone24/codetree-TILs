#include<iostream>
#define MAX_N 100'000
using namespace std;

int uf[MAX_N+1];
int find(int x){
    if(uf[x] == x) return x;
    int root = find(uf[x]);
    uf[x] = root;
    return root;
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    uf[X] = Y;
}

int n,m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) uf[i] = i;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        Union(x,y);
    }

    bool check = false;
    int num;
    cin >> num;
    int team = find(num);
    for(int i=1;i<k;i++){
        int temp;
        cin >> temp;
        if(team != find(temp)){
            check = true;
            break;
        }
    }
    if(check == false) cout << 1<<"\n";
    else cout << 0<<"\n";
}