#include <iostream>
#define MAX_N 100'000
using namespace std;
int arr[MAX_N+1];
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<m;i++){
    int left = 0;
    int right = n-1;
    int target;
    cin >> target;
    //이진 탐색
    bool flag = false;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid]==target){
            cout << mid+1<<'\n';
            flag = true;
            break;
        }
        else if(arr[mid]<target) left = mid+1;
        else right = mid-1;
    }
    if(flag==false)cout <<-1<<"\n";
    }
    return 0;
}