/**
 *    author: mohin    
**/

#include <bits/stdc++.h>

using namespace std;

vector<long long> primeFactorization(long long n) {
    vector<long long> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        ans.push_back(n);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n{};
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vector<long long> pf = primeFactorization(n);
        sort(pf.begin(), pf.end());
        for (int i = 0; i < pf.size(); ++i) {
            int cnt{1};
            for (int j = i + 1; j < pf.size(); ++j) {
                if (pf[i] == pf[j]) {
                    cnt += 1;
                    i = j;
                } else {
                    i = j - 1;
                    break;
                }
            }
            cout << pf[i] << '^' << cnt << ' ';
        }
        cout << endl;
    }
    return 0;
}