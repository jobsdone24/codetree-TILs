#include <iostream>
using namespace std;

int main() {
    int fiv[50]={0};

    fiv[1]=1;
    fiv[2]=1;

    int n;
    cin >> n;

    for(int i=3;i<=45;i++){
        fiv[i] = fiv[i-1] + fiv[i-2];
    }

    cout << fiv[n];
    return 0;
}