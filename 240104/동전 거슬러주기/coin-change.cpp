#include<iostream>
#include<climits>
using namespace std;

int N,M;
int coin[103];
int small[10003];

int main(){
    cin >> N >> M;

    for(int i=1;i<=N;i++) cin >> coin[i];

    //최소값 구하기 -> dp 값을 모두 최대로 만들기
    for(int i=0;i<=M;i++){
        small[i] = INT_MAX;
    }    
    small[0] = 0;

    for(int i=1;i<=M;i++){
        for(int j=1; j<=N; j++){
            int c = coin[j];
            if(i>=c){
                if(small[i-c] == INT_MAX) continue;
                small[i] = min(small[i], small[i-c]+1);
            }
        }
    }

    cout << small[M];
}