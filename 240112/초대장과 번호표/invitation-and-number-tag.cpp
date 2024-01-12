#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>

#define MAX_N 100000
#define MAX_G 250000
using namespace std;
vector<int> ninfo[MAX_N+1];
unordered_set<int> group[MAX_G+1];
bool visited[MAX_N+1];

int main(){
    int N,G;
    cin >> N >> G;

    for(int i=0;i<G;i++){
        int size;
        cin >> size;
        for(int j=0;j<size;j++){
            int num;
            cin >> num;
            ninfo[num].push_back(i);
            group[i].insert(num);
        }
    }

    visited[1]= true;
    queue<int> q;
    q.push(1);

    int ans = 0;

    while(!q.empty()){
        int num = q.front();   
        q.pop();
        ans++;
        for(int i=0;i<ninfo[num].size();i++){
            int gnum = ninfo[num][i];
            group[gnum].erase(num);


            if(group[gnum].size() ==1){
                int next = *(group[gnum].begin());
                if(visited[next]==false){
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    cout << ans;

}