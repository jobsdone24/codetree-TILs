#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_N 1000

// 변수 선언
int n, k;
int arr[MAX_N+1];

int main() {
    // 입력:
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    // 배열을 앞에서부터 순회하며 쌍을 만들어줍니다.
    for(int i = 0; i < n; i++) {
        int target = k-arr[i];
        unordered_map<long long, int> count;
        for(int j=i+1; j<n; j++){
        long long diff = (long long)target - arr[j];
        // 가능한 모든 쌍의 수를 세어줍니다.
        ans += count[diff];

        // 현재 숫자의 개수를 하나 증가시켜줍니다.
        count[arr[j]]++;
        }
    }

    cout << ans;
    return 0;
}