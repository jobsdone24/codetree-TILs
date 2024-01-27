#include <iostream>
#include<math.h>
#include<algorithm>

#define MAX_N 100'000
using namespace std;
int arr[MAX_N + 1];
int n;


//특정 수보다 같거나 큰 것
int lowerfunc(int target){
    int left = 0;
    int right = n-1;
    int lower = n;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]>=target){
            right = mid -1;
            lower = min(lower,mid);
        } 
        else left = mid+1;  
    }
    return lower;
}

//특정 수를 최초로 초과하는 것
int upperfunc(int target){
    int left = 0;
    int right = n-1;
    int lower = n;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]>target){
            right = mid -1;
            lower = min(lower,mid);
        } 
        else left = mid+1;  
    }
    return lower;
}


int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        int num1 = lowerfunc(start);
        int num2 = upperfunc(end);
        cout <<num2 - num1<<'\n';
    }
    return 0;
}