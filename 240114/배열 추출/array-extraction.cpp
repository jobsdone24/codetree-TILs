#include <iostream>
#include <queue>

using namespace std;

// 변수 선언
int n;
priority_queue<int> pq;  

int main() {
    // 입력:
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if(x != 0) {
            // x가 자연수라면
            // priority queue에 x를 넣어줍니다.
            pq.push(x);
        }
        else {
            // x가 0이라면
            // 최댓값을 찾아 출력한 뒤 제거합니다.
            if(pq.empty())
                cout << 0 << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
    return 0;
}