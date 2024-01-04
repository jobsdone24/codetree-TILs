#include<iostream>
#include<climits>
using namespace std;

int element[103];
int sy[10003]; //합이 k인 가장 작은 부분 수열

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> element[i];
    }

    for(int i =0;i<=m;i++){
        sy[i] = INT_MAX;
    }
    sy[0] = 0;

    //1~m 까지 확인할 때 뒤에서 부터 확인 시 동일한 값 중복이 일어나지 않음
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            int num = element[i];
            if(j-num>=0){

                if(sy[j-num]==INT_MAX) continue;

                sy[j] = min(sy[j],sy[j-num]+1);
            }
        }
    }
    if(sy[m]==INT_MAX) cout<< -1;
    else cout << sy[m];
}