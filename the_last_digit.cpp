/**
 *    author: mohin    
**/

#include <bits/stdc++.h>

using namespace std;

int binaryExponentiation(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = binaryExponentiation(a, b / 2);
    if (b % 2) {
        return (res * res * a) % 10;
    } else {
        return (res * res) % 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t{}, a{}, b{};
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int res = binaryExponentiation(a, b);
        cout << res << endl;
    }
    return 0;
}
