#include <iostream>
using namespace std;

int main() {
    int n , b;
    int digits[1000] = {};
    int cnt = 0;
    cin >> n >> b;

    while (true) {
        if(n < b) {
            digits[cnt++] = n;
            break;
        }
    
        digits[cnt++] = n % b;
        n /= b;
    }
    
    // print binary number
    for(int i = cnt - 1; i >= 0; i--)
        cout << digits[i];
}