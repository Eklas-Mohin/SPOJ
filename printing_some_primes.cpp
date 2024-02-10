/**
 *    author: mohin    
**/

#include <bits/stdc++.h>

using namespace std;

const int mx = 1e8;
vector<bool> sieve(mx + 1, true);

void primeSieve() {
    sieve[0] = sieve[1] = false;
    for (int i = 4; i <= mx; i += 2) {
        sieve[i] = false;
    }
    for (int i = 3; i * i <= mx; i += 2) {
        if (sieve[i]) {
            for (int j = i * i; j <= mx; j += i) {
                sieve[j] = false;
            }
        }
    } 
}

void solve() {
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= mx; i += 2) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < primes.size(); i += 100) {
        cout << primes[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    primeSieve();
    solve();
    return 0;
}
